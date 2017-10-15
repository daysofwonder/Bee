//
// Created by Dawid Drozd aka Gelldur on 14.10.17.
//
#pragma once

#include "Node.h"

namespace Bee
{

struct Vertex
{
	Node node;
	std::vector<Vertex> children;

	Vertex(const Node& node);
};

class Graph
{
public:
	Node findNodeById(const std::string& id) const;

	void addRelation(Node* nodeParent, Node* nodeChild);

private:
	std::vector<Vertex> _pool;
};
}
