#include "Ship.hpp"
#include "App.hpp"
#include "Physics.hpp"
#include "Vector2.hpp"

#include <gl\GL.h>

//STL
#include <iostream>
#include <cmath>

namespace Engine
{

	Ship::Ship(App *parent)
		: m_position(Math::Vector2::Origin), m_velocity(Math::Vector2::Origin), m_angle(0.0f), m_rotation(250.0f), m_mass(1.0f), m_parent(parent) //TODO: RR: contemplate using a component based design approach

	{
		std::cout << "Construction of ship\n";
		ChangeShip();
	}

	Ship::Ship(App *parent, float _x, float _y)
		: m_position(_x, _y), m_velocity(Math::Vector2::Origin), m_angle(0.0f), m_rotation(250.0f), m_mass(1.0f), m_parent(parent)

	{
		std::cout << "Construction of ship\n";
	}

	Ship::~Ship()
	{
		std::cout << "Destruction of ship\n";
	}

	void Ship::MoveUp()
	{
		ApplyImpulse(Math::Vector2(THRUST));
	}

	void Ship::RotateLeft(float deltaTime)
	{

		m_angle += m_rotation * deltaTime;
	}

	void Ship::RotateRight(float deltaTime)
	{
		m_angle -= m_rotation * deltaTime;
	}

	void Ship::ApplyDrag(Math::Vector2 force)
	{
		m_velocity.x *= force.x;
		m_velocity.y *= force.y;
	}
	void Ship::ApplyImpulse(Math::Vector2 impulse)
	{
		if (m_mass > 0)
		{
			m_velocity.x += (impulse.x / m_mass) * cosf((m_angle + ANGLE_OFFSET) * (Engine::Math::Vector2::PI / 180));
			m_velocity.y += (impulse.x / m_mass) * sinf((m_angle + ANGLE_OFFSET) * (Engine::Math::Vector2::PI / 180));
		}
	}

	void Ship::Update(float deltaTime)
	{
		//calculate speed
		float speed =
			std::fabs(m_velocity.Length());

		//Cap speed
		if (speed > MAX_VELOCITY)
		{
			m_velocity.x = (m_velocity.x / speed) * MAX_VELOCITY;
			m_velocity.y = (m_velocity.y / speed) * MAX_VELOCITY;
		}

		//Set new state
		m_currentSpeed = speed;
		m_position.x += m_velocity.x * deltaTime;
		m_position.y += m_velocity.y * deltaTime;

		//Applies drag

		ApplyDrag(Math::Vector2(DRAG_FORCE));
		//TODO::RR:: Apply this to the asteroids
		//calcuations for wrap around

		float halfWidth = m_parent->GetWidth() / 2.0f;
		float halfHeight = m_parent->GetHeight() / 2.0f;

		float worldMinX = -halfWidth;
		float worldMaxX = halfWidth;

		float worldMinY = -halfHeight;
		float worldMaxY = halfHeight;

		m_position.x = wrap(m_position.x, worldMinX, worldMaxX);
		m_position.y = wrap(m_position.y, worldMinY, worldMaxY);
	}

	void Ship::ChangeShip()
	{

		m_current_Ship = ++m_current_Ship % 3;

		m_points.clear();

		switch (m_current_Ship)
		{
		case 1:
			/*
			****** Little ship******
								*/

			m_points.push_back(Math::Vector2(0.0, 20.0));
			m_points.push_back(Math::Vector2(12.0, -10.0));
			m_points.push_back(Math::Vector2(6.0, -4.0));
			m_points.push_back(Math::Vector2(-6.0, -4.0));
			m_points.push_back(Math::Vector2(-12.0, -10.0));
			break;
		case 2:
			m_points.push_back(Math::Vector2(0.0, 90.0));
			m_points.push_back(Math::Vector2(3.0, 84.0));
			m_points.push_back(Math::Vector2(9.5, 84.0));
			m_points.push_back(Math::Vector2(12.0, 78.0));
			m_points.push_back(Math::Vector2(12.0, 60.0));
			m_points.push_back(Math::Vector2(60.0, 30.0));
			m_points.push_back(Math::Vector2(60.0, 18.0));
			m_points.push_back(Math::Vector2(12.0, 18.0));
			m_points.push_back(Math::Vector2(7.2, 0.0));
			m_points.push_back(Math::Vector2(0.0, 0.0));
			m_points.push_back(Math::Vector2(-7.2, 0.0));
			m_points.push_back(Math::Vector2(-12.0, 18.0));
			m_points.push_back(Math::Vector2(-60.0, 18.0));
			m_points.push_back(Math::Vector2(-60.0, 30.0));
			m_points.push_back(Math::Vector2(-12.0, 60.0));
			m_points.push_back(Math::Vector2(-12.0, 78.0));
			m_points.push_back(Math::Vector2(-9.5, 84.0));
			m_points.push_back(Math::Vector2(-3.0, 84.0));
			m_points.push_back(Math::Vector2(0.0, 90.0));
			break;

		default:
			/* ===========BIG SHIP============*/

			m_points.push_back(Math::Vector2(0.0, 150.0));
			m_points.push_back(Math::Vector2(2.5, 145.0));
			m_points.push_back(Math::Vector2(7.5, 145.0));
			m_points.push_back(Math::Vector2(12.5, 135.0));
			m_points.push_back(Math::Vector2(25.0, 125.0));
			m_points.push_back(Math::Vector2(25.0, 120.0));
			m_points.push_back(Math::Vector2(12.5, 125.0));
			m_points.push_back(Math::Vector2(12.5, 120.0));
			m_points.push_back(Math::Vector2(12.5, 115.0));
			m_points.push_back(Math::Vector2(17.5, 110.0));
			m_points.push_back(Math::Vector2(17.5, 110.5));
			m_points.push_back(Math::Vector2(17.5, 115.0));
			m_points.push_back(Math::Vector2(20.0, 115.5));
			m_points.push_back(Math::Vector2(22.5, 115.0));
			m_points.push_back(Math::Vector2(22.5, 110.5));
			m_points.push_back(Math::Vector2(22.5, 110.0));
			m_points.push_back(Math::Vector2(22.5, 105.5));
			m_points.push_back(Math::Vector2(25.0, 105.0));
			m_points.push_back(Math::Vector2(25.0, 100.0));
			m_points.push_back(Math::Vector2(5.0, 100.0));
			m_points.push_back(Math::Vector2(3.0, 95.0));
			m_points.push_back(Math::Vector2(0.0, 95.0));
			m_points.push_back(Math::Vector2(-3.0, 95.0));
			m_points.push_back(Math::Vector2(-5.0, 100.0));
			m_points.push_back(Math::Vector2(-25.0, 100.0));
			m_points.push_back(Math::Vector2(-25.0, 105.0));
			m_points.push_back(Math::Vector2(-22.5, 105.5));
			m_points.push_back(Math::Vector2(-22.5, 110.0));
			m_points.push_back(Math::Vector2(-22.5, 110.5));
			m_points.push_back(Math::Vector2(-22.5, 115.0));
			m_points.push_back(Math::Vector2(-20.0, 115.5));
			m_points.push_back(Math::Vector2(-17.5, 115.0));
			m_points.push_back(Math::Vector2(-17.5, 110.5));
			m_points.push_back(Math::Vector2(-17.5, 110.0));
			m_points.push_back(Math::Vector2(-12.5, 115.0));
			m_points.push_back(Math::Vector2(-12.5, 120.0));
			m_points.push_back(Math::Vector2(-12.5, 125.0));
			m_points.push_back(Math::Vector2(-25.0, 120.0));
			m_points.push_back(Math::Vector2(-25.0, 125.0));
			m_points.push_back(Math::Vector2(-12.5, 135.0));
			m_points.push_back(Math::Vector2(-7.5, 145.0));
			m_points.push_back(Math::Vector2(-2.5, 145.0));
			m_points.push_back(Math::Vector2(0.0, 145.0));
			m_points.push_back(Math::Vector2(2.5, 145.0));
			m_points.push_back(Math::Vector2(-2.5, 145.0));
			m_points.push_back(Math::Vector2(0.0, 150.0));
			break;
		}
	}

	void Ship::Render()
	{
		glLoadIdentity();

		glTranslatef(m_position.x, m_position.y, 0.0);

		glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

		glBegin(GL_LINE_LOOP);

		std::vector<Math::Vector2>::iterator it = m_points.begin();

		for (; it != m_points.end(); ++it)
		{
			glVertex2f((*it).x, (*it).y);
		}
		glEnd();
	};

	void Ship::Respawn()
	{
		glLoadIdentity();
		m_position.x = 0.0f;
		m_position.y = 0.0f;
		m_velocity.x = 0.0f;
		m_velocity.y = 0.0f;
		m_angle = 0.0f;

		glTranslatef(m_position.x, m_position.y, 0.0);

		glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

		glBegin(GL_LINE_LOOP);
		glEnd();
	}

} // namespace Engine
