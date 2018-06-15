#include "world.h"
#include <memory>
#include <stdlib.h>
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

using namespace std;

int main() {
	World* w = new World();
	w->InitMap();
	w->Instruction();
	w->GetInput();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	delete w;
	w = NULL;
	getchar();
	return 0;
}