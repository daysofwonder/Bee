//
// Created by Dawid Drozd aka Gelldur on 08.10.17.
//
#include <bee/Beehive.h>
//////////////////////////////////

namespace Bee
{

Beehive::Beehive(std::shared_ptr<sel::State> state)
		: _state{std::move(state)}
{
}

}
