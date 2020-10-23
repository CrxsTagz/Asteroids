#pragma once
#ifndef SHIP_HPP
#define SHIP_HPP

namespace Engine
{
    class ship
    {
    public:
        void ship_render();

    protected:
        int m_ship;
        int x;
        int y;
    };
} // namespace Engine

#endif