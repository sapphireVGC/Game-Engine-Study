#pragma once
#include <iostream>

using namespace std;

class sth {
	public:
		const int memSize = 2024;

		char* beginP = nullptr;
		char* endP = nullptr;
		char* cursor = nullptr;

		sth();

		virtual ~sth();

		void initMemory();
		void printMemoryPool();
		void addText(char value);
		void finish();

		char* myMalloc(size_t size);
};
