//
// Created by Dawid Drozd aka Gelldur on 08.10.17.
//
#pragma once

#include <string>

#include <bee/Beehive.h>

namespace cocos2d
{
class CCNode;
}

namespace Bee
{

class Cocos2dxBeehive
{
public:
	Cocos2dxBeehive(const std::string& content);

	cocos2d::CCNode* createView(const std::string& content);

private:
	std::shared_ptr<sel::State> _state;
	Bee::Beehive _beehive;
};

}
