//
// Created by Dawid Drozd aka Gelldur on 27.10.17.
//
#include "bee/Husk.h"
//////////////////////////////////

#include <cocos2d.h>

namespace Bee
{

Husk::Husk(cocos2d::CCNode* workingNode)
		: _workingNode{workingNode}
{
}

int Husk::convertTag(const std::string& tag)
{
	return hash("$_$_" + tag);
}

cocos2d::CCNode* Husk::find(cocos2d::CCNode* node, const int tag) const
{
	return node->getChildByTag(tag);
}

cocos2d::CCNode* Husk::findRecursive(cocos2d::CCNode* node, const int tag) const
{
	using namespace cocos2d;

	if (node == nullptr)
	{
		assert(false);
		return nullptr;
	}
	CCObject* childRaw = nullptr;
	CCARRAY_FOREACH(node->getChildren(), childRaw)
		{
			auto child = dynamic_cast<CCNode*>(childRaw);
			assert(child);
			if (child->getTag() == tag)
			{
				return child;
			}
			child = findRecursive(child, tag);
			if (child != nullptr)
			{
				return child;
			}
		}
	return nullptr;
}

int Husk::hash(const std::string& text)
{
	//Yeap SO ;) https://stackoverflow.com/a/13487193/1052261
	//std::hash<std::string>{}(typeid(T).name() is slower

	int hash = 5381;
	int c;

	const int size = static_cast<int>(text.size());
	for (int i = 0; i < size; ++i)
	{
		c = text[i];
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return hash;
}

}
