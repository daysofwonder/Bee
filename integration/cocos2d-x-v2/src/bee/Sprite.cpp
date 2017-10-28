//
// Created by Dawid Drozd aka Gelldur on 09.10.17.
//
#include "Sprite.h"
//////////////////////////////////

#include <bee/acme/RGBA.h>

using namespace cocos2d;

namespace Bee
{

Sprite::Sprite(const std::string& id)
		: _node{id, new CCSprite{}}
{
	get()->init();
}

void Sprite::sprite(std::string fileName)
{
	if (CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName.c_str()) != fileName)
	{
		get()->initWithFile(fileName.c_str());
	}
	else
	{
		CCLOGWARN("No such file: %s", fileName.c_str());
	}
}

void Sprite::setColor(const int color)
{
	Bee::RGBA::setColor(get(), color);
}

void Sprite::setOpacity(double value)
{
	Bee::RGBA::setOpacity(get(), value);
}

void Sprite::setSize(const double width, const double height)
{
	const auto& size = get()->getContentSize();
	get()->setScaleX(static_cast<float>(width / size.width));
	get()->setScaleY(static_cast<float>(height / size.height));
}

cocos2d::CCSprite* Sprite::get() const
{
	auto sprite = dynamic_cast<CCSprite*>(_node.node.get());
	assert(sprite);
	return sprite;
}

}
