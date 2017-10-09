//
// Created by Dawid Drozd aka Gelldur on 08.10.17.
//
#pragma once

#include <istream>
#include <memory>
#include <vector>

namespace sel
{
class State;
}

namespace Bee
{

class Beehive
{
public:
	Beehive(std::shared_ptr<sel::State> state);

private:
	std::shared_ptr<sel::State> _state;
};

}
