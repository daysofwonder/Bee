//
// Created by Dawid Drozd aka Gelldur on 08.10.17.
//
#pragma once

#include <cocos2d.h>

namespace Bee
{

class Node
{
public:
	std::string id;
	cocos2d::CCObjectPtr<cocos2d::CCNode> node;

	Node(const std::string& id);
	Node(const std::string& id, cocos2d::CCNode*);

	Node(const Node& other);
	Node(Node&& other);

	Node& operator=(const Node& other);
	Node& operator=(Node&& other);

	~Node();

	Node getNode() const
	{
		return Node{*this};
	}

	void setPosition(const double x, const double y);
	void addChild(Node& uiElement);
	void setSize(const double width, const double height);
	void setAnchor(const double x, const double y);
	void setScale(const double x, const double y);
	void setRotation(const double degrees);
	void setVisible(const bool isVisible);
};

}
