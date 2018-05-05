#include "sth.h"

sth::sth()
{
}


sth::~sth()
{
}

void sth::initMemory() {
	beginP = reinterpret_cast<char*>(malloc(memSize));
	endP = beginP + memSize;
	cursor = beginP;
}

char* sth::myMalloc(size_t size) {
	char* returnLocation = nullptr;

	returnLocation = cursor;
	cursor += size;

	return returnLocation;
}

void sth::finish() {
	free(this);
}

void sth::printMemoryPool() {
	char* text = beginP;

	while (text < endP) {
		cout << *text;
		text++;
	}
}

void sth::addText(char t) {
	if (cursor == endP) {
		initMemory();
	}

	char* mall = nullptr;

	mall = myMalloc(sizeof(t));
	*mall = t;
}

