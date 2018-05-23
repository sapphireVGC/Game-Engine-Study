#include "world.h"
#include "config.h"
#include <ctime>
#include <memory>

using namespace std;

world *w = new world();

int main() {
	srand((unsigned int)time(NULL));
	w->Start();
	while (true) {
		w->GetInput();
	}
	getchar();
	return 0;
}