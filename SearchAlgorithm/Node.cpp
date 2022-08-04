#include "Node.h"
#include <limits>

Node::Node(char val, int x, int y)
	: m_val(val)
	, m_xPosition(x)
	, m_yPosition(y)
	, m_hScore(0)
	// set default values of fScore and gScore to max value of int
	, m_fScore(std::numeric_limits<int>::max())
	, m_gScore(std::numeric_limits<int>::max())
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
