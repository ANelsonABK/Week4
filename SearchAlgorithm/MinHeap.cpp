#include "MinHeap.h"
#include <vector>
#include <iostream>

MinHeap::MinHeap()
	: m_heapSize(0)
	, m_heapPtr(std::vector<Node>())
{
}

MinHeap::~MinHeap()
{

}

/*
Insert a new node into the min heap
*/
void MinHeap::Insert(Node node)
{

	// Insert new node at the end
	m_heapSize++;
	int idx = m_heapSize - 1;
	m_heapPtr.push_back(node);

	// Fix the min heap property if it's violated
	while (idx != 0 &&
		m_heapPtr[FindParent(idx)].m_fScore > m_heapPtr[idx].m_fScore)
	{
		// swap the nodes
		swap(&m_heapPtr[idx], &m_heapPtr[FindParent(idx)]);
		idx = FindParent(idx);
	}

}


/*
Recursive method to heapify a subtree with the root at a given index.
*/
void MinHeap::MinHeapify(int idx)
{
	int left = FindLeft(idx);
	int right = FindRight(idx);
	int smallest = idx;

	if (left < m_heapSize
		&& m_heapPtr[left].m_fScore < m_heapPtr[idx].m_fScore)
		smallest = idx;
	if (right < m_heapSize
		&& m_heapPtr[right].m_fScore < m_heapPtr[smallest].m_fScore)
		smallest = idx;

	if (smallest != idx)
	{
		// swap the nodes
		swap(&m_heapPtr[idx], &m_heapPtr[smallest]);

		// Recursively minheapify
		MinHeapify(smallest);
	}
}

/*
Remove the root node from the min heap.
*/
Node MinHeap::RemoveMin()
{
	// If heap is empty, return null node
	if (m_heapSize <= 0)
	{
		return Node(NULL, 0, 0);
	}

	if (m_heapSize == 1)
	{
		m_heapSize--;
		return m_heapPtr[0];
	}

	// Store the node with the minimum cost and remove it from the heap
	Node root = m_heapPtr[0];
	m_heapPtr[0] = m_heapPtr[m_heapSize - 1];
	m_heapSize--;
	MinHeapify(0);

	return root;
}

/*
Swap two nodes to keep the minheap intact.
*/
void MinHeap::swap(Node* node1, Node* node2)
{
	Node* temp = node1;
	node1 = node2;
	node2 = temp;
}

int MinHeap::FindNode(Node node)
{

	for (int idx = 0; idx < m_heapPtr.size(); idx++)
	{
		// Check if node was found
		if (m_heapPtr[idx].m_val == node.m_val)
		{
			return idx;
		}
	}

	// Node is not in min heap
	return -1;
}