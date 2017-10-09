//
// Created by Dawid Drozd aka Gelldur on 10.10.17.
//
#pragma once

namespace cocos2d
{
class CCRGBAProtocol;
}

namespace Bee
{

namespace RGBA
{
void setColor(cocos2d::CCRGBAProtocol* node, const int color);
void setOpacity(cocos2d::CCRGBAProtocol* node, double value);
}

}
