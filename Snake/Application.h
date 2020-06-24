#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Application
{
public:
	Application(int pWindowWidth, int pWindowHeight, std::string pAppName);
	virtual ~Application();

	void Update(sf::Time pDeltaTime);
	void Render();
	void Run();

private:
	sf::Event m_event;
	sf::RenderWindow m_window;
	std::size_t m_screenWidth;
	std::size_t m_screenHeight;
	sf::Time m_desiredUpdateTime;
	


};

