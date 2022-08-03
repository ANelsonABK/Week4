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
	typedef std::map<Node*, Node> visited;
	visited *m_cameFrom;

public:

	AStar();
	~AStar();

	int ComputeHeuristic(Node node, Node goal);
	void ReconstructPath(Node currentNode);
	void AStarSearch(Node start, Node goal);
};