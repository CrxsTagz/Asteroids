#pragma once

#ifndef _Physics_HPP
#define _Physics_HPP

namespace Engine
{


      //Added to a physics lib
    static constexpr float MAX_VELOCITY = 500.0f;
    static constexpr float THRUST = 15.0f;
    static constexpr float DRAG_FORCE = 0.999f;
    static constexpr float ANGLE_OFFSET = 90.0f;

  inline float wrap(float x, float min, float max)
    {
        if (x < min)
            return max - (min - x);
        if (x > max)
            return min + (x - max);
        return x;
    }

  
} // namespace Engine
#endif