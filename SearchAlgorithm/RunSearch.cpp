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
	Node e = Node("e", 0, 0);
	Node f = Node("f", 0, 0);
	Node g = Node("g", 0, 0);

	// Add the edges
	a.AddEdge((Node*)&b, 5);
	a.AddEdge((Node*)&d, 7);

	b.AddEdge((Node*)&c, 1);
	b.AddEdge((Node*)&f, 2);

	c.AddEdge((Node*)&d, 1);
	c.AddEdge((Node*)&g, 6);

	d.AddEdge((Node*)&e, 1);

	e.AddEdge((Node*)&g, 3);
	
	f.AddEdge((Node*)&g, 1);

	astar.AStarSearch(a, g);

	return 0;
}