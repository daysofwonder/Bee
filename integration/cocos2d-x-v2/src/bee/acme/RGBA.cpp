//
// Created by Dawid Drozd aka Gelldur on 10.10.17.
//
#include "RGBA.h"
//////////////////////////////////

#include <cocos2d.h>

#include "Color.h"

namespace Bee
{

namespace RGBA
{
void setColor(cocos2d::CCRGBAProtocol* node, const int color)
{
	node->setColor(Color::convertTo3B(color));
	node->setOpacity(Acme::Color::ARGB::getAlpha(color));
}

void setOpacity(cocos2d::CCRGBAProtocol* node, double value)
{
	value = std::max(0.0, std::min(value, 1.0));//Normalize
	node->setOpacity(static_cast<GLubyte>(255.F * value));
}

}

}
