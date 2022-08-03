#pragma once
#include "MinHeap.h"
#include <vector>
#include <unordered_map>
#include <map>

class AStar
{
	// Maps
	MinHeap m_openSet;

	typedef std::map<Node*, std::vector<Node>> visited;
	visited *m_cameFrom;

public:

	AStar();
	~AStar();

	int ComputeHeuristic(Node node, Node goal);
	void ReconstructPath(Node currentNode);
	void AStarSearch(Node start, Node goal);
};