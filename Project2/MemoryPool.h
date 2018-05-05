#pragma once
#include <iostream>

using namespace std;

class MemoryPool {
public:
	const int memSize = 2024;

	char* beginP = nullptr;
	char* endP = nullptr;
	char* cursor = nullptr;

	MemoryPool();

	virtual ~MemoryPool();

	void initMemory();
	void printMemoryPool();
	void addText(char value);
	void finish();

	char* myMalloc(size_t size);
};
