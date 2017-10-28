//
// Created by Dawid Drozd aka Gelldur on 08.10.17.
//
#include <bee/Node.h>
//////////////////////////////////

#include <bee/Husk.h>

namespace Bee
{

Node::Node(const std::string& id)
		: id{id}
		, node{new cocos2d::CCNode{}}
{
	std::cout << "Node(" << id << ")" << std::endl;
	node->init();
	node->setTag(Husk::convertTag(id));
	assert(node->retainCount() == 1);
}

Node::Node(const std::string& id, cocos2d::CCNode* node)
		: id{id}
		, node{node}
{
	std::cout << "Node(" << id << ")" << std::endl;
	assert(node->retainCount() > 1);
	node->release();
	assert(node->retainCount() == 1);
	node->setTag(Husk::convertTag(id));
}

Node::Node(const Node& other)
		: id{other.id}
		, node{other.node}
{
}

Node::Node(Node&& other)
		: id{other.id}
		, node{std::move(other.node)}
{
}

Node& Node::operator=(const Node& other)
{
	id = other.id;
	node = other.node;
	return *this;
}

Node& Node::operator=(Node&& other)
{
	id = other.id;
	node = std::move(other.node);
	return *this;
}

Node::~Node()
{
	std::cout << "~Node(" << id << ")" << std::endl;
	node = nullptr;
}

void Node::setPosition(const double x, const double y)
{
	node->setPosition(x, y);
}

void Node::addChild(Node& uiElement)
{
	std::cout << "(" << id << ").addChild(" << uiElement.id << ")" << std::endl;
	node->addChild(uiElement.node.get());
}

void Node::setSize(const double width, const double height)
{
	node->setContentSize({static_cast<float>(width), static_cast<float>(height)});
}

void Node::setAnchor(const double x, const double y)
{
	node->setAnchorPoint({static_cast<float>(x), static_cast<float>(y)});
}

void Node::setScale(const double x, const double y)
{
	node->setScaleX(static_cast<float>(x));
	node->setScaleY(static_cast<float>(y));
}

void Node::setRotation(const double degrees)
{
	node->setRotation(static_cast<float>(degrees));
}

void Node::setVisible(const int isVisible)
{
	node->setVisible(isVisible);
}

void Node::setZOrder(const int order)
{
	node->setZOrder(order);
}
}
