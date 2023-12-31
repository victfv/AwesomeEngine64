#include "MemoryPoolAllocator.h"

MemoryPoolAllocator::MemoryPoolAllocator(size_t blockSize, size_t blockNumber)
{
	pool_memory_ = ::operator new(blockNumber * blockSize);

	blockAddresses.resize(blockNumber);
	for (size_t i = 0; i < blockNumber; i++)
	{
		blockAddresses[i] = static_cast<void*>(static_cast<char*>(pool_memory_) + blockSize * i);
		blocks[static_cast<char*>(pool_memory_) + blockSize * i] = true;
	}
}

MemoryPoolAllocator::~MemoryPoolAllocator()
{
	::operator delete(pool_memory_);
}

void* MemoryPoolAllocator::allocate()
{
	void* block = nullptr;
	for (int i = 0; i < blockAddresses.size(); i++)
	{
		void* addr = blockAddresses[i];
		if (blocks[addr])
		{
			blocks[addr] = false;
			block = addr;
			break;
		}
	}
	return block;
}

bool MemoryPoolAllocator::deallocate(void* ptr)
{
	if (blocks.find(ptr) != blocks.end())
	{
		blocks[ptr] = true;
		return true;
	}
	else
	{
		std::cerr << "Deallocating free memory at address: " << ptr << "\n";
		return false;
	}
}

template <typename T, typename... Args>
T* MemoryPoolAllocator::create(Args&&... args)
{
	void* memory = allocate();
	T* obj = new (memory) T(std::forward<Args>(args)...);
	return obj;
}

template <typename T>
bool MemoryPoolAllocator::destroy(T* obj)
{
	obj->~T();
	return deallocate(obj);
}

