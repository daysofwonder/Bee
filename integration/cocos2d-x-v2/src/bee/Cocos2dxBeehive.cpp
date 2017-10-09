//
// Created by Dawid Drozd aka Gelldur on 08.10.17.
//
#include <bee/Cocos2dxBeehive.h>
//////////////////////////////////

#include <cassert>

#include <selene.h>

#include "Node.h"
#include "Sprite.h"
#include "Rect.h"
#include "Label.h"

namespace Bee
{

Cocos2dxBeehive::Cocos2dxBeehive(const std::string& content)
		: _state{new sel::State{true}}
		, _beehive{_state}
{
	sel::State& state = *_state;

	if (state(content.c_str()) == false)
	{
		assert(false);
	}

	state["Node"].SetClass<Node, std::string>(
			"setPosition", &Node::setPosition
			, "addChild", &Node::addChild
			, "setSize", &Node::setSize
	);
	state["Sprite"].SetClass<Sprite, std::string>(
			"sprite", &Sprite::sprite
			, "setColor", &Sprite::setColor
			, "setOpacity", &Sprite::setOpacity
			, "getNode", &Sprite::getNode
	);
	state["Rect"].SetClass<Rect, std::string>(
			"setColor", &Rect::setColor
			, "setOpacity", &Rect::setOpacity
			, "getNode", &Rect::getNode
	);
	state["Label"].SetClass<Label, std::string>(
			"setColor", &Label::setColor
			, "setOpacity", &Label::setOpacity
			, "setAlign", &Label::setAlign
			, "setFont", &Label::setFont
			, "setFontSize", &Label::setFontSize
			, "setText", &Label::setText
			, "getNode", &Label::getNode
	);
}

cocos2d::CCNode* Cocos2dxBeehive::createView(const std::string& content)
{
	sel::State& state = *_state;
	if (state(content.c_str()) == false)
	{
		return nullptr;
	}

	//TODO check safety
	auto luaData = state["rootView"];
	if (luaData.exists() == false)
	{
		CCLOG("Missing rootView");
		return nullptr;
	}
	auto nodeWrapper = static_cast<Bee::Node*>(luaData);
	assert(nodeWrapper);
	return nodeWrapper->node.get();
}

}
