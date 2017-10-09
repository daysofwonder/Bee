//
// Created by Dawid Drozd aka Gelldur on 09.10.17.
//
#include "Rect.h"
//////////////////////////////////

#include <bee/acme/RGBA.h>
#include <bee/acme/Color.h>

using namespace cocos2d;

namespace Bee
{

Rect::Rect(const std::string& id)
		: _node{id, new CCLayerColor{}}
{
	get()->initWithColor(Color::convertTo4B(0xFFFF0000), 50, 50);
}

void Rect::setColor(const int color)
{
	Bee::RGBA::setColor(get(), color);
}

void Rect::setOpacity(double value)
{
	Bee::RGBA::setOpacity(get(), value);
}

cocos2d::CCLayerColor* Rect::get() const
{
	auto layer = dynamic_cast<CCLayerColor*>(_node.node.get());
	assert(layer);
	return layer;
}

}
