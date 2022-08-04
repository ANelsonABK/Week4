#pragma once
#include <unordered_map>
#include <string>

/*
Node class to keep track of nodes in the graph and their edges. The 
three costs needed for A* search (gScore, hScore, and fScore) are 
saved to reference and make any updates to anytime in the search.
*/
class Node
{
	// Position of node on the graph
	int m_xPosition;
	int m_yPosition;

	/*
	Key is a pointer to a Node object.
	*/
	typedef std::unordered_map<Node*, int> edgemap;
	
public:
	char m_val;
	int m_gScore; // the cost from start to node
	int m_hScore; // the heuristic cost
	int m_fScore; // the sum of gScore and hScore

	edgemap m_edgeMap;

	Node(char val, int x, int y);
	~Node();

	void AddEdge(Node* node, int cost);
	int GetXPosition() { return m_xPosition; }
	int GetYPosition() { return m_yPosition; }
};

