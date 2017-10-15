//
// Created by Dawid Drozd aka Gelldur on 14.10.17.
//
#include "Graph.h"
//////////////////////////////////

namespace Bee
{

Vertex::Vertex(const Node& node)
	: node(node)
{
}

Node Graph::findNodeById(const std::string& id) const
{
	// Now this is simple implementation //FIXME
	for(const auto& vertex : _pool)
	{
		if(vertex.node.id == id)
		{
			return vertex.node;
		}
	}
	return Node{id, nullptr};
}

void Graph::addRelation(Node* nodeParent, Node* nodeChild)
{
	// Now this is simple implementation //FIXME
	_pool.push_back(Vertex{*nodeChild});
}
}
