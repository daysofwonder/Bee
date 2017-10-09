//
// Created by Dawid Drozd aka Gelldur on 10.10.17.
//
#include "Label.h"
//////////////////////////////////

#include <bee/acme/RGBA.h>

using namespace cocos2d;

namespace Bee
{

Label::Label(const std::string& id)
		: _node{id, new CCLabelTTF{}}
{
	get()->init();
}

void Label::setColor(const int color)
{
	Bee::RGBA::setColor(get(), color);
}

void Label::setOpacity(double value)
{
	Bee::RGBA::setOpacity(get(), value);
}

void Label::setFont(std::string font)
{
	get()->initWithString("Sample text", font.c_str(), 16);
}

void Label::setFontSize(const int size)
{
	get()->setFontSize(size);
}

void Label::setText(std::string text)
{
	get()->setString(text.c_str());
}

void Label::setAlign(std::string alignText)
{
	if (alignText == "center")
	{
		alignText = "centerVertical|centerHorizontal";
	}

	auto found = alignText.find("|");
	if (found == std::string::npos)
	{
		if (setAlignOption(alignText) == false)
		{
			CCLOG("Invalid align option: %s", alignText.c_str());
			return;
		}
	}
	else
	{
		auto first = alignText.substr(0, found);
		if (setAlignOption(first) == false)
		{
			CCLOG("Invalid align option: %s", alignText.c_str());
			return;
		}
		auto second = alignText.substr(found + 1);
		if (setAlignOption(second) == false)
		{
			CCLOG("Invalid align option: %s", alignText.c_str());
			return;
		}
	}
}

cocos2d::CCLabelTTF* Label::get() const
{
	auto node = dynamic_cast<CCLabelTTF*>(_node.node.get());
	assert(node);
	return node;
}

bool Label::setAlignOption(const std::string& alignTextOption)
{
	if (alignTextOption == "top")
	{
		get()->setVerticalAlignment(kCCVerticalTextAlignmentTop);
		return true;
	}
	if (alignTextOption == "centerVertical")
	{
		get()->setVerticalAlignment(kCCVerticalTextAlignmentCenter);
		return true;
	}
	if (alignTextOption == "bottom")
	{
		get()->setVerticalAlignment(kCCVerticalTextAlignmentBottom);
		return true;
	}
	///////////////////////////////////////////////////////////////////
	if (alignTextOption == "left")
	{
		get()->setHorizontalAlignment(kCCTextAlignmentLeft);
		return true;
	}
	if (alignTextOption == "centerHorizontal")
	{
		get()->setHorizontalAlignment(kCCTextAlignmentCenter);
		return true;
	}
	if (alignTextOption == "right")
	{
		get()->setHorizontalAlignment(kCCTextAlignmentRight);
		return true;
	}

	return false;
}

}
