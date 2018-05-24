#include "world.h"
#include <ctime>
#include <memory>

using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	World* w = new World();
	w->SpawnPlayer();
	w->SpawnMonster();
	w->UpdateArray();
	w->Draw();
	w->Instruction();
	while (true) {
		w->GetInput();
	}
	getchar();
	return 0;
}