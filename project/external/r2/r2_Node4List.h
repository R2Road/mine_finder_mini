#pragma once

namespace r2
{
	template<typename T>
	struct Node4List
	{
		using ValueT = T;
		using MyT = Node4List<ValueT>;

		ValueT MyValue;
		MyT* pPrev = nullptr;
		MyT* pNext = nullptr;
	};

	template<typename T>
	class Node4ListCleaner_ClearValue
	{
	public:
		void operator()( Node4List<T>* node )
		{
			node->pNext = nullptr;
			node->pPrev = nullptr;
			node->MyValue = {};
		}
	};

	template<typename T>
	class Node4ListCleaner_StayValue
	{
	public:
		void operator()( Node4List<T>* node )
		{
			node->pNext = nullptr;
			node->pPrev = nullptr;
		}
	};
}