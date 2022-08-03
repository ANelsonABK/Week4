#pragma once
#include <unordered_map>
#include <string>

class Node
{

	int m_xPosition;
	int m_yPosition;

	/*
	Key is a pointer to a Node object.
	*/
	typedef std::unordered_map<Node*, int> edgemap;
	
public:
	std::string m_val;
	int m_gScore; // the cost from start to node
	int m_hScore; // the heuristic cost
	int m_fScore; // the sum of gScore and hScore

	edgemap m_edgeMap;

	Node(std::string val, int x, int y);
	~Node();

	void AddEdge(Node* node, int cost);
	int GetXPosition() { return m_xPosition; }
	int GetYPosition() { return m_yPosition; }
};

