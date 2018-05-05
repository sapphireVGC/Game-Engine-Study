#include "monster.h"
#include "orc.h"
#include "zombie.h"
#include "player.h"

using namespace std;

orc orcs[100];
zombie zombies[100];
player p;

int orcCnt = 0;
int zombieCnt = 0;

void Update() {
	int playerHP;

	for (int i = 0; i < orcCnt; i++) {
		playerHP = p.GetHP();
		playerHP = playerHP - orcs[i].GetATK();

		if (playerHP < 0) {
			playerHP == 0;
			break;
		}

		orcs[i].smash();
		p.SetHP(playerHP);
		p.DisplayStats();
	}

	for (int i = 0; i < zombieCnt; i++) {
		playerHP = p.GetHP();
		playerHP = playerHP - zombies[i].GetATK();

		if (playerHP < 0) {
			playerHP == 0;
			break;
		}

		zombies[i].bite();
		p.SetHP(playerHP);
		p.DisplayStats();
	}
}

int main() {	
	p.SetHP(5000);
	p.DisplayStats();

	for (int i = 0; i < 100; i++) {
		int ranType = 0;
		ranType = rand() % 2;

		int ranAtk = 0;

		if(ranType == 0) {
			ranAtk = rand() % 51 + 50;

			orcs[orcCnt].SetMonsterType("Orc");
			orcs[orcCnt].SetMonsterName("Orc" + std::to_string(orcCnt));
			orcs[orcCnt].SetATK(ranAtk);
			orcs[orcCnt].DisplayStats();

			orcCnt++;
		}
		else {
			ranAtk = rand() % 26 + 25;

			zombies[zombieCnt].SetMonsterType("Zombie");
			zombies[zombieCnt].SetMonsterName("Zombie" + std::to_string(zombieCnt));
			zombies[zombieCnt].SetATK(ranAtk);
			zombies[zombieCnt].DisplayStats();

			zombieCnt++;
		}
	}

	Update();
	getchar();

	return 0;
}