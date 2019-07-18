#include <iostream>
#include "MyMemoryPool.hpp"

int main()
{
	MyMemoryPool m;
	//no1 number of block size 
	m.init(2, 10);

	int* val = reinterpret_cast<int*> (m.alloc());
	if (val != nullptr) {
		*val = 16;
		std::cout << "Alloc : " << *val << std::endl;
	}



	m.printMemory();
	m.release(val);
	m.printMemory();

	int* val2 = reinterpret_cast<int*> (m.alloc());
	if (val != nullptr) {
		*val = 26;
		std::cout << "Alloc : " << *val << std::endl;
	}

	m.printMemory();
	m.release(val2);
	m.printMemory();

	getchar();
}