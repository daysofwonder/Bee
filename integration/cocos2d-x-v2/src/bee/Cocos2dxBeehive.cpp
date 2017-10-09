//
// Created by Dawid Drozd aka Gelldur on 08.10.17.
//
#include <bee/Cocos2dxBeehive.h>
//////////////////////////////////

#include <cassert>

#include <selene.h>

#include <bee/Node.h>

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
			"setX", &Node::setX
			, "setY", &Node::setY
			, "addChild", &Node::addChild
			, "setColor", &Node::setColor
			, "setSize", &Node::setSize
			, "sprite", &Node::sprite
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
	return static_cast<Node*>(state["rootView"])->node.get();
}

}
