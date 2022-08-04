#pragma once
#include "MinHeap.h"
#include <vector>
#include <unordered_map>
#include <map>

class AStar
{
	// Maps
	MinHeap m_openSet;

	/*
	Key is a pointer to a Node object.
	*/
	typedef std::unordered_map<char, char> visited;
	
public:

	AStar();
	~AStar();

	visited m_cameFrom;

	int ComputeHeuristic(Node node, Node goal);
	void ReconstructPath(Node currentNode);
	void AStarSearch(Node start, Node goal);
	//void AddToPath(Node neighbor, Node current);
};