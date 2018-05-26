#include "world.h"
#include <ctime>
#include <memory>
#include <stdlib.h>
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	World* w = new World(); //delete
	w->SpawnPlayer();
	w->SpawnMonster();
	w->UpdateArray();
	w->Draw();
	w->Instruction();
	while (true) {
		w->GetInput();
	}
	delete w;
	w = NULL;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	getchar();
	return 0;
}