#include "Application.h"
//#include "SinglyLinkedList.h"

 




Application::Application(int pWindowWidth, int pWindowHeight, std::string pAppName)
	:m_window(sf::VideoMode(pWindowWidth, pWindowHeight), pAppName)
	, m_screenWidth(pWindowWidth)
	, m_screenHeight(pWindowHeight)
	, m_desiredUpdateTime(sf::seconds(1.0f / 10.0f))
{
	m_food = Food(sf::Vector2f(100, 100), 20.0f, sf::Color::Green, 10);

}


Application::~Application()
{
}


void Application::HandleEvent(const sf::Event& pEvent)
{
	//Cache the passed event locally
	sf::Event tEvent = pEvent;

	//Switch statement to decide between the different event types
	switch (tEvent.type)
	{
	case sf::Event::KeyPressed:
	{
		this->HandleInput(tEvent.key.code, true);

		break;
	}
	case sf::Event::KeyReleased:
	{
		this->HandleInput(tEvent.key.code, false);

		break;
	}
	}
}

void Application::HandleInput(sf::Keyboard::Key pKey, bool pPressed)
{
	m_snake.HandleInput(pKey, pPressed);
}


void Application::Update(sf::Time pDeltaTime)
{
	m_snake.Update(pDeltaTime.asSeconds());
	m_snake.HandleCollision(m_food);
}

void Application::Render()
{
	m_window.clear();
	m_food.Render(m_window);
	m_snake.Render(m_window);
	m_window.display();
}

void Application::Run()
{
	sf::Clock clock;
	//Variable to track the time since update() was last executed
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				m_window.close();
			HandleEvent(event);
		}

		//get the elapsed time since the last loop
		sf::Time tDeltaTime = clock.restart();

		timeSinceLastUpdate += tDeltaTime;

		while (timeSinceLastUpdate > m_desiredUpdateTime)
		{
			Update(m_desiredUpdateTime);
			timeSinceLastUpdate -= m_desiredUpdateTime;
		}
		//Render results to the screen
		Render();
	}
}
