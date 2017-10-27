//
// Created by Dawid Drozd aka Gelldur on 27.10.17.
//
#pragma once

#include <string>
#include <cassert>

namespace cocos2d
{
class CCNode;
}

namespace Bee
{

class Husk
{
public:
	explicit Husk(cocos2d::CCNode* workingNode = nullptr);

	static int convertTag(const std::string& tag);

	template<typename T>
	T* extract(const std::string& tag) const
	{
		return extract<T>(_workingNode, tag);
	}

	template<typename T>
	T* extract(cocos2d::CCNode* node, const std::string& tag) const
	{
		auto found = findRecursive(node, convertTag(tag));
		assert(found);
		auto converted = dynamic_cast<T*>(found);
		assert(converted);
		return converted;
	}

private:
	cocos2d::CCNode* _workingNode = nullptr;

	static int hash(const std::string& text);

	cocos2d::CCNode* find(cocos2d::CCNode* node, const int tag) const;
	cocos2d::CCNode* findRecursive(cocos2d::CCNode* node, const int tag) const;
};

}
