#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "GameWorld.h"
class Application
{

public:

	enum class AppState
	{
		MAIN_MENU,
		IN_GAME,
	}m_appState;

	Application(int pWindowWidth, int pWindowHeight, std::string pAppName);
	virtual ~Application();

	void Initialise();
	void HandleEvent(const sf::Event& pEvent);
	void HandleInput(sf::Keyboard::Key pKey, bool pPressed);
	void Update(sf::Time pDeltaTime);
	void Render();
	void Run();

private:
	sf::Event m_event;
	sf::RenderWindow m_window;
	std::size_t m_screenWidth;
	std::size_t m_screenHeight;
	sf::Time m_desiredUpdateTime;
	
	GameWorld* m_gameWorld;

};

