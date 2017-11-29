//
// Created by Dawid Drozd aka Gelldur on 08.10.17.
//
#pragma once

#include <map>
#include <string>
#include <vector>

#include <bee/Beehive.h>

namespace cocos2d
{
class CCNode;
}

namespace Bee
{

class Graph;
class Node;
class Cocos2dxBeehive;

struct Context
{
	Cocos2dxBeehive* beehive = nullptr;
};

class Cocos2dxBeehive
{
public:
	explicit Cocos2dxBeehive(const std::vector<std::string>& searchPaths);
	Cocos2dxBeehive(const Cocos2dxBeehive& other);
	Cocos2dxBeehive(Cocos2dxBeehive&& other);

	cocos2d::CCNode* createView(const std::string& content);
	cocos2d::CCNode* createViewFromFile(const std::string& filePath);

	cocos2d::CCNode* findViewById(const std::string& id);

	const std::shared_ptr<sel::State>& getState()
	{
		return _state;
	}

private:
	std::shared_ptr<Graph> _graph;
	std::shared_ptr<sel::State> _state;
	Bee::Beehive _beehive;
	const std::vector<std::string> _searchPaths;

	void addRelation(Node* nodeParent, Node* nodeChild);
	Context getContext();
	cocos2d::CCNode* extractView();
};
}
