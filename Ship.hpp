#pragma once
#ifndef SHIP_HPP
#define SHIP_HPP
#include <iostream>

namespace Engine
{
    class ship
    {
    public:
        void ship_render();

    protected:
        int m_ship;
    };
} // namespace Engine

#endif