//
// Created by Dawid Drozd aka Gelldur on 09.10.17.
//
#pragma once

#include "bee/Node.h"

namespace Bee
{

class Sprite
{
public:
	Sprite(const std::string& id);

	void sprite(std::string fileName);

	void setColor(const int color);
	void setOpacity(double value);

	Node getNode() const
	{
		return _node;
	}

private:
	Node _node;

	cocos2d::CCSprite* get() const;
};

}
