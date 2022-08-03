#pragma once
#include "Node.h"
#include <vector>

class MinHeap
{
	std::vector<Node> m_heapPtr; // pointer to array of nodes in heap
	int m_heapSize; // current number of elements in heap

	void swap(Node* node1, Node* node2);

public:
	MinHeap();
	~MinHeap();

	void MinHeapify(int idx);

	// Returns the min node (root) from min heap
	Node GetMin() { return m_heapPtr[0]; }

	void Insert(Node node);
	Node RemoveMin();
	int GetSize() { return m_heapSize; }
	int FindNode(Node node);

	// Utility functions
	int FindParent(int idx) { return (idx - 1) / 2; }
	int FindLeft(int idx) { return (idx * 2) + 1; }
	int FindRight(int idx) { return (idx * 2) + 2; }
};

