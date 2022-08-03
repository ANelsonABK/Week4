#include "Node.h"

Node::Node(std::string val, int x, int y)
	: m_val(val)
	, m_xPosition(x)
	, m_yPosition(y)
	, m_hScore(0)
	, m_fScore(0)
	, m_gScore(0)
{

}

Node::~Node()
{

}

/*
Add an edge connecting two nodes together with a cost
to reach the node
*/
void Node::AddEdge(Node* node, int cost)
{
	m_edgeMap[node] = cost;
}
