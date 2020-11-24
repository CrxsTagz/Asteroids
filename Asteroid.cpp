#include "Asteroid.hpp"
#include "App.hpp"

#include <gl\GL.h>
#include <cmath>
#include <cstdlib>

namespace Engine
{
    const size_t NUM_POINTS = 16;
    const float MIN_SIZE = 25.0f;
    const float MAX_SIZE = 45.0f;

    static constexpr float MAX_VELOCITY = 500.0f;
    static constexpr float THRUST = 15.0f;
    static constexpr float DRAG_FORCE = 0.999f;
    static constexpr float ANGLE_OFFSET = 90.0f;

    // Move this out to a Math
    const float PI = 3.141592653;

    inline float randInRange(float min, float max)
    {
        return min + (max - min) * (rand() / static_cast<float>(RAND_MAX));
    }

    // TODO: RR: Get this out of here!
    inline float wrap(float x, float min, float max)
    {
        if (x < min)
            return max - (min - x);
        if (x > max)
            return min + (x - max);
        return x;
    }

    Asteroid::Asteroid(App *parent)
        : m_mass(1.0f), m_angle(0.0f), m_rotation(120), m_parent(parent) // TODO: RR: Contemplate using a component based design approach
    {
        float sizeFactor = 1;
        float min = MIN_SIZE / sizeFactor;
        float max = MAX_SIZE / sizeFactor;

        for (size_t idx = 0; idx < NUM_POINTS; ++idx)
        {
            const float radians = (idx / static_cast<float>(NUM_POINTS)) * 2.0f * PI;
            const float randDist = randInRange(min, max); //min + (max - min) * (rand() / static_cast<float>(RAND_MAX));

            m_points.push_back(Engine::Math::Vector2(sinf(radians) * randDist,
                                                     cosf(radians) * randDist));
        }

        float x = randInRange(-150.0f, 150.0f);
        float y = randInRange(-150.0f, 150.0f);
        m_position = Engine::Math::Vector2(x, y);
        ApplyImpulse(Engine::Math::Vector2(x, y));
    }

    void Asteroid::ApplyImpulse(Engine::Math::Vector2 impulse)
    {
        if (m_mass > 0)
        {
            m_velocity.x += (impulse.x / m_mass) * cosf((m_rotation) * (PI / 180));
            m_velocity.y += (impulse.y / m_mass) * sinf((m_rotation) * (PI / 180));
        }
    }

    void Asteroid::Update(float deltaTime)
    {
        m_angle += m_rotation * deltaTime;

        m_position.x += m_velocity.x * deltaTime;
        m_position.y += m_velocity.y * deltaTime;

        // Calculations for wrap around
        // TODO: RR: Create a parent class to handle this for all rendered entities
        float halfWidth = m_parent->GetWidth() / 2.0f;
        float halfHeight = m_parent->GetHeight() / 2.0f;

        float worldMinX = -halfWidth;
        float worldMaxX = halfWidth;

        float worldMinY = -halfHeight;
        float worldMaxY = halfHeight;

        m_position.x = wrap(m_position.x, worldMinX, worldMaxX);
        m_position.y = wrap(m_position.y, worldMinY, worldMaxY);
    }

    void Asteroid::Render()
    {
        glLoadIdentity();
        glTranslatef(m_position.x, m_position.y, 0.f);
        glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_LINE_LOOP);
        std::vector<Engine::Math::Vector2>::iterator it = m_points.begin();
        for (; it != m_points.end(); ++it)
        {
            glVertex2f((*it).x, (*it).y);
        }
        glEnd();
    }
} // namespace Engine