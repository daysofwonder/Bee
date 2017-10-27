//
// Created by Dawid Drozd aka Gelldur on 10.10.17.
//
#pragma once

#include <bee/Node.h>

namespace Bee
{

class Label
{
public:
	Label(const std::string& id);

	void setColor(const int color);
	void setOpacity(double value);

	void setFont(std::string font);
	void setFontSize(const int size);
	void setText(std::string text);
	void setAlign(std::string alignText);

	Node getNode() const
	{
		return _node;
	}

private:
	Node _node;

	cocos2d::CCLabelTTF* get() const;
	bool setAlignOption(const std::string& alignTextOption);
};

}
