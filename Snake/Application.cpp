#include "Application.h"
#include "SinglyLinkedList.h"
 




Application::Application(int pWindowWidth, int pWindowHeight, std::string pAppName)
	:m_window(sf::VideoMode(pWindowWidth, pWindowHeight), pAppName)
	, m_screenWidth(pWindowWidth)
	, m_screenHeight(pWindowHeight)
	, m_desiredUpdateTime(sf::seconds(1.0f / 60.0f))
{
	//Example of Singly-Linked List storing data of type int
	SinglyLinkedList<char> list(1);
	list.PushFront(11);
	list.PushFront(12);
	list.PushFront(12);
	int bla = list.Length();
	list.PopFront();
	bla = list.Length();
	bla = 0;


}


Application::~Application()
{
}

void Application::Update(sf::Time pDeltaTime)
{

}

void Application::Render()
{
	m_window.clear();

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
