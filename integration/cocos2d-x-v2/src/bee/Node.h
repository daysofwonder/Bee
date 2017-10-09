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

	Node(std::string id)
			: id(id)
			, node{cocos2d::CCLayerColor::create({0xff, 0x00, 0x00, 0xff}, 50, 50)}
	{
		std::cout << "Node(" << id << ")" << std::endl;
	}

	~Node()
	{
		std::cout << "~Node(" << id << ")" << std::endl;
	}

	void sprite(std::string fileName)
	{
		if (cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName.c_str()) != fileName)
		{
			node = cocos2d::CCSprite::create(fileName.c_str());
		}
		else
		{
			//			node = cocos2d::CCLabelTTF::create(("Sorry no such file:" + fileName).c_str()
			//											   , Theme::Font::button.c_str()
			//											   , Theme::Size::Font::hud);
		}
	}

	void setX(double x)
	{
		node->setPositionX(x);
	}

	void setY(double y)
	{
		node->setPositionY(y);
	}

	void addChild(Node* uiElement)
	{
		std::cout << "(" << id << ").addChild(" << uiElement->id << ")" << std::endl;
		node->addChild(uiElement->node.get());
	}

	void setSize(double width, double height)
	{
		node->setContentSize({static_cast<float>(width), static_cast<float>(height)});
	}

	void setColor(int color)
	{
		//dynamic_cast<cocos2d::CCLayerColor*>(node.get())->setColor(Acme::Color::convert(color));
	}
};

}
