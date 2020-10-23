#include <iostream>
#include "Ship.hpp"
#include <SDL2/SDL_opengl.h>

namespace Engine
{
	void ship::ship_render()
	{

		glBegin(GL_LINE_LOOP);
		/*
			****** Little ship******
								*/
		/*
			
			glVertex2f(0.0, 20.0);
			glVertex2f( 12.0,  -10.0);
			glVertex2f( 6.0, -4.0);
			glVertex2f( -6.0, -4.0);
			glVertex2f( -12.0, -10.0);*/

		/* 
			
			==***Kinda the one i wanted to make***==

			glVertex2f(0.0, 90.0);
			glVertex2f( 3.0,  84.0);
			glVertex2f( 9.5, 84.0);
			glVertex2f( 12.0, 78.0);
			glVertex2f( 12.0, 60.0);
			glVertex2f(60.0, 30.0);
			glVertex2f( 60.0,  18.0);
			glVertex2f( 12.0, 18.0);
			glVertex2f( 7.2, 0.0);
			glVertex2f( 0.0, 0.0);
			glVertex2f(-7.2, 0.0);
			glVertex2f( -12.0, 18.0);
			glVertex2f( -60.0, 18.0);
			glVertex2f( -60.0, 30.0);
			glVertex2f( -12.0, 60.0);
			glVertex2f(-12.0, 78.0);
			glVertex2f( -9.5,  84.0);
			glVertex2f( -3.0, 84.0);
			glVertex2f( 0.0, 90.0);
			*/
		/*
         ===========BIG SHIP============
*/
		glVertex2f(0.0, 150.0);
		glVertex2f(2.5, 145.0);
		glVertex2f(7.5, 145.0);
		glVertex2f(12.5, 135.0);
		glVertex2f(25.0, 125.0);
		glVertex2f(25.0, 120.0);
		glVertex2f(12.5, 125.0);
		glVertex2f(12.5, 120.0);
		glVertex2f(12.5, 115.0);
		glVertex2f(17.5, 110.0);
		glVertex2f(17.5, 110.5);
		glVertex2f(17.5, 115.0);
		glVertex2f(20.0, 115.5);
		glVertex2f(22.5, 115.0);
		glVertex2f(22.5, 110.5);
		glVertex2f(22.5, 110.0);
		glVertex2f(22.5, 105.5);
		glVertex2f(25.0, 105.0);
		glVertex2f(25.0, 100.0);
		glVertex2f(5.0, 100.0);
		glVertex2f(3.0, 95.0);
		glVertex2f(0.0, 95.0);
		glVertex2f(-3.0, 95.0);
		glVertex2f(-5.0, 100.0);
		glVertex2f(-25.0, 100.0);
		glVertex2f(-25.0, 105.0);
		glVertex2f(-22.5, 105.5);
		glVertex2f(-22.5, 110.0);
		glVertex2f(-22.5, 110.5);
		glVertex2f(-22.5, 115.0);
		glVertex2f(-20.0, 115.5);
		glVertex2f(-17.5, 115.0);
		glVertex2f(-17.5, 110.5);
		glVertex2f(-17.5, 110.0);
		glVertex2f(-12.5, 115.0);
		glVertex2f(-12.5, 120.0);
		glVertex2f(-12.5, 125.0);
		glVertex2f(-25.0, 120.0);
		glVertex2f(-25.0, 125.0);
		glVertex2f(-12.5, 135.0);
		glVertex2f(-7.5, 145.0);
		glVertex2f(-2.5, 145.0);
		glVertex2f(0.0, 145.0);
		glVertex2f(2.5, 145.0);
		glVertex2f(-2.5, 145.0);
		glVertex2f(0.0, 150.0);

		glEnd();
	};
} // namespace Engine
