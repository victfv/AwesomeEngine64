#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>

class MemoryPoolAllocator
{
public:
	MemoryPoolAllocator(size_t blockSize, size_t blockNumber);
	~MemoryPoolAllocator();

	void* allocate();
	void deallocate(void* ptr);

private:
	void* pool_memory_;
	std::unordered_map<void*,bool> blocks;
	std::vector<void*> blockAddresses;
};

