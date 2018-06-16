#include "World.h"

using namespace std;

World::World() {
	
}

World::~World() {

}

void World::InitMap() {
	cout << endl << "\tPlease choose the stage(1-2)... ";
	int i;
	string s;
	cin >> s;
	i = stoi(s);
	cf->LoadConfig(i);
	system("CLS");
	cout << endl << "\t";
	for (int i = 0; i < cf->mapVec.size(); i++) {
		if (cf->ReadMap(i) == 0) {
			cout << cf->ReadMap(i) << cf->ReadMap(i) << " ";
		}
		else {
			cout << "   ";
		}
		if (i % mapSize == mapSize - 1) {
			cout << endl << "\t";
		}
	}
}

void World::Instruction() {
	cout << endl << "\t=============================" << endl;
	cout << "\t   A = Benz" << endl;
	cout << "\t   S = BMW" << endl;
	cout << "\t   D = Honda" << endl;
	cout << "\tChoose a car... ";
}

void World::WriteMap() {
	cout << endl << "\t";
	for (int i = 0; i < cf->mapVec.size(); i++) {
		if (carCnt == 2) {
			if (i == car[0]->GetPos() && i == car[1]->GetPos()) {
				cout << car[0]->GetSYMBOL() << car[1]->GetSYMBOL() << " ";
			}
			else if (i == car[0]->GetPos()) {
				cout << car[0]->GetSYMBOL() << "  ";
			}
			else if (i == car[1]->GetPos()) {
				cout << " " << car[1]->GetSYMBOL() << " ";
			}
			else if (cf->ReadMap(i) == 0) {
				cout << cf->ReadMap(i) << cf->ReadMap(i) << " ";
			}
			else {
				cout << "   ";
			}
		}
		else if (carCnt == 1) {
			if (i == car[0]->GetPos()) {
				cout << car[0]->GetSYMBOL() << "  ";
			}
			else if (cf->ReadMap(i) == 0) {
				cout << cf->ReadMap(i) << cf->ReadMap(i) << " ";
			}
			else {
				cout << "   ";
			}
		}
		if (i % mapSize == mapSize - 1) {
			cout << endl << "\t";
		}
	}
	if (carCnt < 2) {
		Instruction();
		if (_kbhit()) {
			input = static_cast<char>(_getch());
			if (input == 'a') {
				SpawnCar("Benz");
			}
			else if (input == 's') {
				SpawnCar("BMW");
			}
			else if (input == 'd') {
				SpawnCar("Honda");
			}
		}
	}
}

void World::UpdateMap() {
	std::chrono::seconds interval(timeDelay);
	WriteMap();
	bool haveCar = true;
	while (haveCar) {
		std::this_thread::sleep_for(interval);
		system("CLS");
		for (int i = 0; i < carCnt; i++) {
			int carP = car[i]->GetPos();
			int carPP = car[i]->GetPastPos();
			if (cf->ReadMap(carP + 1) == 1 && carP + 1 != carPP) {
				car[i]->SetPos(carP + 1);
			}
			else if (cf->ReadMap(carP + mapSize) == 1 && carP + mapSize != carPP) {
				car[i]->SetPos(carP + mapSize);
			}
			else if (cf->ReadMap(carP - 1) == 1 && carP - 1 != carPP) {
				car[i]->SetPos(carP - 1);
			}
			else if (cf->ReadMap(carP - mapSize) == 1 && carP - mapSize != carPP) {
				car[i]->SetPos(carP - mapSize);
			}
			car[i]->SetPastPos(carP);
			int carF = car[i]->GetFUEL();
			carF = carF - fuelCost;
			car[i]->SetDATA(carF); 
			if (carF <= 0) {
				for (int l = i + 1; l < carCnt; l++) {
					car[l - 1] = car[l];
				}
				delete car[carCnt];
				car[carCnt] = NULL;
				car[carCnt] = new Car();
				carCnt--;
				haveCar = false;
			}
		}
		if (carCnt > 0) {
			WriteMap();
		}
	}
	cf->mapVec.clear();
	InitMap();
	Instruction();
}

void World::SpawnCar(const string& s) {
	car[carCnt] = new Car();
	cf->SetTARGET(s);
	cf->LoadConfig(0);
	string temp = cf->GetTEMP(1);
	int fuelTemp = stoi(temp);
	char symbolTemp = cf->GetTEMP(2)[0];
	car[carCnt]->SetDATA(cf->GetTEMP(0), fuelTemp, symbolTemp);
	for (int i = 0; i < cf->mapVec.size(); i++) {
		if (cf->ReadMap(i) == 1) {
			startPnt = i;
			car[carCnt]->SetPos(i);
			car[carCnt]->SetPastPos(i);
			break;
		}
	}
	carCnt++;
	if (carCnt == 1) {
		system("CLS");
		UpdateMap();
	}
}

void World::GetInput() {
	string s;
	char c;
	cin >> s;
	c = s[0];
	if (c == 'a') {
		SpawnCar("Benz");
	}
	else if (c == 's') {
		SpawnCar("BMW");
	}
	else if (c == 'd') {
		SpawnCar("Honda");
	}
}