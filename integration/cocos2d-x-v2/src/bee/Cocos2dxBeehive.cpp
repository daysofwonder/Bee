//
// Created by Dawid Drozd aka Gelldur on 08.10.17.
//
#include <bee/Cocos2dxBeehive.h>
//////////////////////////////////

#include <cassert>

#include <selene.h>

#include "Label.h"
#include "Node.h"
#include "Rect.h"
#include "Sprite.h"

#include "Graph.h"

namespace Bee
{

Cocos2dxBeehive::Cocos2dxBeehive(const std::vector<std::string>& searchPaths)
	: _graph{new Graph{}}
	, _state{new sel::State{true}}
	, _beehive{_state}
{
	sel::State& state = *_state;

	std::string luaSearchPaths = ";";
	for(const auto& path : searchPaths)
	{
		luaSearchPaths += path;
		luaSearchPaths += "?.lua;";
	}

	const std::string command = "package.path = package.path .. \"" + luaSearchPaths + "\"";
	if(state(command.c_str()) == false)
	{
		assert(false && "Issue during adding search paths");
	}

	state["beehive"].SetObj(*this, "addRelation", &Cocos2dxBeehive::addRelation);

	state["Node"].SetClass<Node, std::string>("setPosition",
											  &Node::setPosition,
											  "addChild",
											  &Node::addChild,
											  "setSize",
											  &Node::setSize,
											  "setAnchor",
											  &Node::setAnchor,
											  "setScale",
											  &Node::setScale,
											  "setRotation",
											  &Node::setRotation,
											  "setVisible",
											  &Node::setVisible,
											  "getNode",
											  &Node::getNode);
	state["Sprite"].SetClass<Sprite, std::string>("sprite",
												  &Sprite::sprite,
												  "setColor",
												  &Sprite::setColor,
												  "setOpacity",
												  &Sprite::setOpacity,
												  "getNode",
												  &Sprite::getNode);
	state["Rect"].SetClass<Rect, std::string>(
		"setColor", &Rect::setColor, "setOpacity", &Rect::setOpacity, "getNode", &Rect::getNode);
	state["Label"].SetClass<Label, std::string>("setColor",
												&Label::setColor,
												"setOpacity",
												&Label::setOpacity,
												"setAlign",
												&Label::setAlign,
												"setFont",
												&Label::setFont,
												"setFontSize",
												&Label::setFontSize,
												"setText",
												&Label::setText,
												"getNode",
												&Label::getNode);
}

Cocos2dxBeehive::~Cocos2dxBeehive()
{
	delete _graph;
	_graph = nullptr;
}

cocos2d::CCNode* Cocos2dxBeehive::createView(const std::string& content)
{
	sel::State& state = *_state;
	if(state(content.c_str()) == false)
	{
		return nullptr;
	}

	// TODO check safety
	auto luaData = state["rootView"];
	if(luaData.exists() == false)
	{
		CCLOG("Missing rootView");
		return nullptr;
	}
	//Casting lua data if fails will return nullptr
	auto nodeWrapper = static_cast<Bee::Node*>(luaData);
	assert(nodeWrapper);
	return nodeWrapper->node.get();
}

cocos2d::CCNode* Cocos2dxBeehive::findViewById(const std::string& id)
{
	auto found = _graph->findNodeById(id);
	return found.node.get();
}

void Cocos2dxBeehive::addRelation(Node* nodeParent, Node* nodeChild)
{
	assert(nodeParent);
	assert(nodeChild);
	_graph->addRelation(nodeParent, nodeChild);
}
}
