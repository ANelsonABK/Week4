#include "AStar.h"
#include <iostream>
#include <cmath>
#include <vector>

/*
Implements the A* search algorithm using pseudocode from Wikipedia.
*/
AStar::AStar()
	//:  m_cameFrom(std::map<Node, std::vector<Node>>())
	//, m_openSet(MinHeap())
	: m_openSet(MinHeap())
	, m_cameFrom(new std::map<Node*, std::vector<Node>>())
{

}

AStar::~AStar()
{
	delete m_cameFrom;
}

/*
Reconstructs the shortest path with the cheapest cost
*/
void AStar::ReconstructPath(Node currentNode)
{

	// Find where current node is int visited list
	visited::iterator itr;
	for (itr = m_cameFrom->begin(); itr != m_cameFrom->end(); itr++)
	{
		if (itr->first->m_val == currentNode.m_val) {
			break;
		}
	}

	// iterate over nodes that were in the path
	std::vector<Node> path = itr->second;
	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i].m_val << " ";
	}

	std::cout << currentNode.m_val << std::endl;

	std::cout << "Total cost of path: " << currentNode.m_fScore << std::endl;
}

/*
Computes the cost of the cheapest path from the current
node to the goal node using the Euclidean Distance
*/
int AStar::ComputeHeuristic(Node node, Node goal)
{
	int xValue = (goal.GetXPosition() - node.GetXPosition());
	int yValue = (goal.GetYPosition() - node.GetYPosition());

	return std::sqrt(std::pow(xValue, 2) + std::pow(yValue, 2));
}

/*
Uses the A* search algorithm to find a path from the start node
to the goal node.
*/
void AStar::AStarSearch(Node start, Node goal)
{
	// Add starting node to openSet
	m_openSet.Insert(start);

	// Set gScore of starting node to 0
	start.m_gScore = 0;

	//Compute the heuristic of the starting node
	start.m_hScore = ComputeHeuristic(start, goal);

	// Compute best guess path cost for starting node
	start.m_fScore = start.m_gScore + start.m_hScore;

	while (m_openSet.GetSize() > 0)
	{
		// Get current root of openSet
		Node currNode = m_openSet.GetMin();

		// Check if current node is the goal
		if (currNode.m_val == goal.m_val)
		{
			ReconstructPath(currNode);
			return;
		}

		m_openSet.RemoveMin();

		// Iterate over node's neighbors
		for (auto& neighbor : currNode.m_edgeMap)
		{
			Node node = *(neighbor.first);
			node.m_gScore = neighbor.second;
			// Get distance from start to neighbor node through current node
			int tentativeGScore = currNode.m_gScore + node.m_gScore;

			if (tentativeGScore <= node.m_gScore)
			{
				// Found a better path to neighbor; save it
				// Get current path to neighbor node if one exists
				visited::iterator itr;
				for (itr = m_cameFrom->begin(); itr != m_cameFrom->end(); itr++)
				{
					if (itr->first->m_val == node.m_val)
					{
						break;
					}
				}

				std::vector<Node> nodesVisited;
				if (itr != m_cameFrom->end())
				{
					nodesVisited = itr->second;
				}

				nodesVisited.push_back(currNode);
				// TODO: fix issue where map won't update values
				m_cameFrom->insert_or_assign(&node, nodesVisited);
				//m_cameFrom.erase(node);
				//m_cameFrom.insert(
				//	std::pair<Node, std::vector<Node>>(*node, nodesVisited));
				//if (m_cameFrom.find(node) == m_cameFrom.end())
				//{
				//	m_cameFrom.insert(
				//		std::pair<Node, std::vector<Node>>(node, nodesVisited));
				//}
				//else
				//{
				//	m_cameFrom[node] = nodesVisited;
				//}

				// Update the neighbor's scores
				node.m_gScore = tentativeGScore;
				node.m_hScore = ComputeHeuristic(node, goal);
				node.m_fScore = node.m_gScore + node.m_hScore;

				//// Add updated neighbor back to edge map
				currNode.AddEdge((Node*)&node, node.m_gScore);

				// Add neighbor to open set if not already seen
				// TODO: see if this needs to be changed
				if (m_openSet.FindNode(node) == -1)
				{
					m_openSet.Insert(node);
				}
			 }
		}
	}

	// Goal was never reached
	std::cout << "Not possible to reach " << goal.m_val << " from "
		<< start.m_val << ".\n";
}
