#include "MemoryPool.h"

struct MemoryMetaData {
	int size;
};

MemoryPool::MemoryPool()
{
}


MemoryPool::~MemoryPool()
{
}

void MemoryPool::initMemory() {
	beginP = reinterpret_cast<char*>(malloc(memSize));
	endP = beginP + memSize;
	cursor = beginP;
}

char* MemoryPool::myMalloc(size_t size) {
	char *returnLocation = nullptr;
	returnLocation = cursor;
	
	int actualSize = size + sizeof(MemoryMetaData);
	MemoryMetaData *p = reinterpret_cast<MemoryMetaData*>(cursor);
	p->size = size;

	int offset = actualSize % 4;
	if (offset != 0) {
		//actualSize = actualSize 
	}

	return returnLocation;
}

void MemoryPool::finish() {
	free(this);
}

void MemoryPool::printMemoryPool() {
	char* text = beginP;

	while (text < endP) {
		cout << *text;
		text++;
	}
}

void MemoryPool::addText(char t) {
	if (cursor == endP) {
		initMemory();
	}

	char* mall = nullptr;

	mall = myMalloc(sizeof(t));
	*mall = t;
}

