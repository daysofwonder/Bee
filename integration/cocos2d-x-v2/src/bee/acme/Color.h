//
// Created by Dawid Drozd aka Gelldur on 10.10.17.
//
// Source from: https://github.com/gelldur/common-cpp
#pragma once

namespace Acme
{

namespace Color
{

/***
 * Color format is AARRGGBB in hex
 * eg. red = 0xffff0000
 * eg. green = 0xff00ff00
 * eg. blue = 0xff0000ff
 */
namespace ARGB
{

/**
 * @param color format is AARRGGBB
 * @return RR
 */
inline unsigned char getRed(const int colorARGB)
{
	return static_cast<unsigned char>((colorARGB & 0xFF0000) >> 16);
}

/**
 * @param color format is AARRGGBB
 * @return GG
 */
inline unsigned char getGreen(const int colorARGB)
{
	return static_cast<unsigned char>((colorARGB & 0x00FF00) >> 8);
}

/**
 * @param color format is AARRGGBB
 * @return BB
 */
inline unsigned char getBlue(const int colorARGB)
{
	return static_cast<unsigned char>(colorARGB & 0x0000FF);
}

/**
 * @param color format is AARRGGBB
 * @return AA
 */
inline unsigned char getAlpha(const int colorARGB)
{
	return static_cast<unsigned char>((colorARGB & 0xFF000000) >> 24);
}

inline int setAlpha(const int colorARGB, unsigned char alpha)
{
	return (colorARGB & 0x00FFFFFF) | (alpha << 24);
}

}

}
}

namespace Bee
{

namespace Color
{

inline cocos2d::ccColor3B convertTo3B(const int color)
{
	cocos2d::ccColor3B converted;
	converted.r = Acme::Color::ARGB::getRed(color);
	converted.g = Acme::Color::ARGB::getGreen(color);
	converted.b = Acme::Color::ARGB::getBlue(color);
	return converted;
}

inline cocos2d::ccColor4F convertTo4F(const int color)
{
	cocos2d::ccColor4F converted;
	converted.r = Acme::Color::ARGB::getRed(color) / 255.F;
	converted.g = Acme::Color::ARGB::getGreen(color) / 255.F;
	converted.b = Acme::Color::ARGB::getBlue(color) / 255.F;
	converted.a = Acme::Color::ARGB::getAlpha(color) / 255.F;
	return converted;
}

inline cocos2d::ccColor4B convertTo4B(const int color)
{
	cocos2d::ccColor4B converted;
	converted.r = Acme::Color::ARGB::getRed(color);
	converted.g = Acme::Color::ARGB::getGreen(color);
	converted.b = Acme::Color::ARGB::getBlue(color);
	converted.a = Acme::Color::ARGB::getAlpha(color);
	return converted;
}

}

}
