#include "world.h"
#include <ctime>

using namespace std;

world w;

int main() {
	srand((unsigned int)time(NULL));
	w.Start();
	while (true) {
		w.GetInput();
	}
	getchar();
	return 0;
}