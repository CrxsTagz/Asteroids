#include "App.hpp"
#include <iostream>
#include <algorithm>

// OpenGL includes
// #include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

namespace Engine
{
	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;

	App::App(const std::string& title, const int width, const int height)
		: m_title(title)
		, m_width(width)
		, m_height(height)
		, m_nUpdates(0)
		, m_timer(new TimeManager)
		, m_mainWindow(nullptr)
	{
		m_state = GameState::UNINITIALIZED;
		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();
	}

	App::~App()
	{
		CleanupSDL();

        // Removes timer allocation
        delete m_timer;
	}

	void App::Execute()
	{
		if (m_state != GameState::INIT_SUCCESSFUL)
		{
			std::cerr << "Game INIT was not successful." << std::endl;
			return;
		}

		m_state = GameState::RUNNING;

		SDL_Event event;
		while (m_state == GameState::RUNNING)
		{
			// Input polling
			//
			while (SDL_PollEvent(&event))
			{
				OnEvent(&event);
			}

			//
			Update();
			Render();
		}
	}

	bool App::Init()
	{
		// Init the external dependencies
		//
		bool success = SDLInit() && GlewInit();
		if (!success)
		{
			m_state = GameState::INIT_FAILED;
			return false;
		}

		// Setup the viewport
		//
		SetupViewPort();

		// Change game state
		//
		m_state = GameState::INIT_SUCCESSFUL;

		return true;
	}

	void App::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
	{		
		switch (keyBoardEvent.keysym.scancode)
		{
		default:			
			SDL_Log("%S was pressed.", keyBoardEvent.keysym.scancode);
			break;
		}
	}

	void App::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_ESCAPE:
			OnExit();
			break;
		default:
			//DO NOTHING
			break;
		}
	}

	void App::Update()
	{
		double startTime = m_timer->GetElapsedTimeInSeconds();

		// Update code goes here
		//

		double endTime = m_timer->GetElapsedTimeInSeconds();
		double nextTimeFrame = startTime + DESIRED_FRAME_TIME;

		while (endTime < nextTimeFrame)
		{
			// Spin lock
			endTime = m_timer->GetElapsedTimeInSeconds();
		}

		//double elapsedTime = endTime - startTime;        

		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();

		m_nUpdates++;
	}

	void App::Render()
	{
		glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);



/*2f es para dos dimensiones, es decir que entra dos valores
estos valores van clock wise*/
//this is the part where it draws in the screen//
		
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

			glVertex2f(0.0, 150.0);
			glVertex2f( 2.5,  145.0);
			glVertex2f( 7.5, 145.0);
			glVertex2f( 12.5, 135.0);
			glVertex2f( 25.0, 125.0);
			glVertex2f(25.0, 120.0);
			glVertex2f( 12.5,  125.0);
			glVertex2f( 12.5, 120.0);
			glVertex2f( 12.5, 115.0);
			glVertex2f( 17.5, 110.0);
			glVertex2f(17.5, 110.5);
			glVertex2f( 17.5, 115.0);
			glVertex2f( 20.0, 115.5);
			glVertex2f( 22.5, 115.0);
			glVertex2f( 22.5, 110.5);
			glVertex2f(22.5, 110.0);
			glVertex2f( 22.5,  105.5);
			glVertex2f( 25.0, 105.0);
			glVertex2f( 25.0, 100.0);
			glVertex2f( 5.0, 100.0);
			glVertex2f( 3.0, 95.0);
			glVertex2f( 0.0, 95.0);
			glVertex2f( -3.0, 95.0);
			glVertex2f( -5.0, 100.0);
			glVertex2f( -25.0, 100.0);
			glVertex2f( -25.0, 105.0);
			glVertex2f(-22.5, 105.5);
			glVertex2f( -22.5, 110.0);
			glVertex2f(-22.5, 110.5);
			glVertex2f( -22.5, 115.0);
			glVertex2f( -20.0, 115.5);
			glVertex2f( -17.5, 115.0);
			glVertex2f( -17.5, 110.5 );
			glVertex2f( -17.5, 110.0);
			glVertex2f( -12.5, 115.0);
			glVertex2f( -12.5, 120.0);
			glVertex2f( -12.5, 125.0);
			glVertex2f( -25.0,  120.0);
			glVertex2f( -25.0, 125.0);
			glVertex2f( -12.5, 135.0);
			glVertex2f(-7.5, 145.0);
			glVertex2f( -2.5, 145.0);
			glVertex2f(0.0, 145.0);
			glVertex2f(2.5, 145.0);
			glVertex2f(-2.5, 145.0);
			glVertex2f( 0.0, 150.0);

		glEnd();

		SDL_GL_SwapWindow(m_mainWindow);
	}

	bool App::SDLInit()
	{
		// Initialize SDL's Video subsystem
		//
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cerr << "Failed to init SDL" << std::endl;
			return false;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		Uint32 flags =  SDL_WINDOW_OPENGL     | 
						SDL_WINDOW_SHOWN      | 
						SDL_WINDOW_RESIZABLE;

		m_mainWindow = SDL_CreateWindow(
			m_title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			m_width,
			m_height,
			flags
		);

		if (!m_mainWindow)
		{
			std::cerr << "Failed to create window!" << std::endl;
			SDL_Quit();
			return false;
		}

		m_context = SDL_GL_CreateContext(m_mainWindow);
		SDL_GL_MakeCurrent(m_mainWindow, m_context);

		// Make double buffer interval synced with vertical scanline refresh
		SDL_GL_SetSwapInterval(0);

		return true;
	}

	void App::SetupViewPort()
	{
		// Defining ortho values
		//
		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;  //f means float, you are telling the program you are workin with a float

		// Set viewport to match window
		//
		glViewport(0, 0, m_width, m_height);

		// Set Mode to GL_PROJECTION
		//
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set projection MATRIX to ORTHO
		//
		glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);

		// Setting Mode to GL_MODELVIEW
		//
		glMatrixMode(GL_MODELVIEW);
	}

	bool App::GlewInit()
	{
		// GLenum err = glewInit();
		// if (GLEW_OK != err)
		// {
		// 	std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
		// 	return false;
		// }

		return true;
	}

	void App::CleanupSDL()
	{
		// Cleanup
		//
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_mainWindow);

		SDL_Quit();
	}

	void App::OnResize(int width, int height)
	{
		// TODO: Add resize functionality
		//
		m_width = width;
		m_height = height;

		SetupViewPort();
	}

	void App::OnExit()
	{
		// Exit main for loop
		//
		m_state = GameState::QUIT;

		// Cleanup SDL pointers
		//
		CleanupSDL();
	}
}