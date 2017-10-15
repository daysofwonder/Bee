//
// Created by Dawid Drozd aka Gelldur on 09.10.17.
//
#pragma once

#include "Node.h"

namespace Bee
{

class Rect
{
public:
	Rect(const std::string& id);

	void setColor(const int color);
	void setOpacity(double value);

	Node* getNode()
	{
		return &_node;
	}

private:
	Node _node;

	cocos2d::CCLayerColor* get() const;
};

}
