#include "AStar.h"
#include <iostream>

int main()
{
	// Create an instance of AStar
	AStar astar = AStar();

	// Create nodes
	Node a = Node("a", 0, 0);
	Node b = Node("b", 0, 0);
	Node c = Node("c", 0, 0);
	Node d = Node("d", 0, 0);

	// Add the edges
	a.AddEdge((Node*)&b, 5);
	b.AddEdge((Node*)&c, 1);
	a.AddEdge((Node*)&d, 7);
	c.AddEdge((Node*)&d, 1);

	astar.AStarSearch(a, d);
}