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

	// See if the node's children have smaller fScores
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
void MinHeap::RemoveMin()
{
	// If heap is empty, return
	if (m_heapSize <= 0)
	{
		//return Node(NULL, 0, 0);
		return;
	}

	//Node root = m_heapPtr[0];

	// If heap has one node, remove it and return
	if (m_heapSize == 1)
	{
		
		m_heapSize--;
		m_heapPtr.erase(m_heapPtr.end() - 1);
		//return root;
		return;
	}

	// remove root from the heap
	m_heapPtr[0] = m_heapPtr[m_heapSize - 1];
	m_heapPtr.erase(m_heapPtr.end() - 1);
	m_heapSize--;

	// Fix the heap
	MinHeapify(0);

	//return root;
}

/*
Swap two nodes to keep the minheap intact.
*/
void MinHeap::swap(Node* node1, Node* node2)
{
	Node temp = *node1;
	*node1 = *node2;
	*node2 = temp;
}

/*
Checks if the node exists in the heap.
*/
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