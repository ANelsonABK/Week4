#include "AStar.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

/*
Implements the A* search algorithm using pseudocode from Wikipedia.
*/
AStar::AStar()
	: m_openSet(MinHeap())
	, m_cameFrom(std::unordered_map<char, char>())
{

}

AStar::~AStar()
{
}

/*
Reconstructs the shortest path with the cheapest cost.
*/
void AStar::ReconstructPath(Node currentNode)
{
	/*
	* TODO: Either prints the wrong path/correct answer, 
	* or correct path/wrong answer.
	*/
	char curr = currentNode.m_val;
	visited::iterator itr;
	std::vector<char> totalPath;
	std::vector<char> keys;

	totalPath.push_back(currentNode.m_val);

	// Get all the keys in the cameFrom map
	std::transform(
		std::begin(m_cameFrom),
		std::end(m_cameFrom),
		std::back_inserter(keys),
		[](auto const& pair) { return pair.first; });

	// Get the path from the current node back to the start
	while (std::find(keys.begin(), keys.end(), curr) != keys.end())
	{
		curr = m_cameFrom.find(curr)->second;
		totalPath.push_back(curr);
	}

	// Print out the path in reverse order
	for (int i = totalPath.size() - 1; i > 0; i--)
	{
		std::cout << totalPath[i] << "->";
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

//void AStar::AddToPath(Node neighbor, Node current)
//{
//	m_cameFrom[neighbor] = current;
//}

/*
Uses the A* search algorithm to find a path from the start node
to the goal node.
*/
void AStar::AStarSearch(Node start, Node goal)
{
	// Set gScore of starting node to 0
	start.m_gScore = 0;

	//Compute the heuristic of the starting node
	start.m_hScore = ComputeHeuristic(start, goal);

	// Compute best guess path cost for starting node
	start.m_fScore = start.m_gScore + start.m_hScore;

	// Add starting node to openSet
	m_openSet.Insert(start);

	while (m_openSet.GetSize() > 0)
	{
		// TODO: Check to make sure it gets the correct min cost node
		// Get current root of openSet
		Node currNode = m_openSet.GetMin();

		// Check if current node is the goal
		if (currNode.m_val == goal.m_val)
		{
			ReconstructPath(currNode);
			return;
		}

		// Remove the current node from the min heap
		m_openSet.RemoveMin();

		// Iterate over node's neighbors
		for (auto& neighbor : currNode.m_edgeMap)
		{
			// Get distance from start to neighbor node through current node
			Node node = *(neighbor.first);
			int tentativeGScore = currNode.m_gScore + neighbor.second;

			if (tentativeGScore < node.m_gScore)
			{
				 /* TODO: Fix issue where some node's gScore is the wrong one.
				 */
				// Found a better path to neighbor; save it
				//AddToPath(node.m_val, currNode.m_val);
				m_cameFrom[node.m_val] = currNode.m_val;

				// Update the neighbor's scores
				node.m_gScore = tentativeGScore;
				node.m_hScore = ComputeHeuristic(node, goal);
				node.m_fScore = node.m_gScore + node.m_hScore;

				// Add neighbor to open set if not already seen
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