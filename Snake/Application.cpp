#include "Application.h"
//#include "SinglyLinkedList.h"

 




Application::Application(int pWindowWidth, int pWindowHeight, std::string pAppName)
	:m_window(sf::VideoMode(pWindowWidth, pWindowHeight), pAppName)
	, m_screenWidth(pWindowWidth)
	, m_screenHeight(pWindowHeight)
	, m_desiredUpdateTime(sf::seconds(1.0f / 60.0f))
{
	//Example of Singly-Linked List storing data of type int
	/*SinglyLinkedList<char> list;
	list.PushFront(11);
	list.PushFront(12);
	list.PushFront(12);
	int bla = list.Length();
	list.PopFront();
	bla = list.Length();
	bla = 0;*/
	

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
	m_snake.Move();
}

void Application::Render()
{
	m_window.clear();
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
