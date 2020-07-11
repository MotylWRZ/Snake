#include "MenuScreen.h"
#include "Application.h"


MenuScreen::MenuScreen(Application* pAppPtr)
	:m_applicationPtr(pAppPtr)
	,m_itemSize(70)
	,m_itemSpacing(m_itemSize)
	,m_menuOffset(-m_itemSize, -200.0f)
	,m_titleSize(120)
{
}


MenuScreen::~MenuScreen()
{
	for (auto tElem : m_menuElems)
	{
		delete tElem;
	}
}

void MenuScreen::Initialise()
{
	

	sf::Vector2f tPos;
	tPos.x = static_cast<float>(m_applicationPtr->GetWindow().getSize().x / 2);
	tPos.y = static_cast<float>(m_applicationPtr->GetWindow().getSize().y / 2) + m_menuOffset.y;

	m_gameTitle = new UITextElement("SNAKE", m_titleSize, sf::Color::White, sf::Vector2f(tPos.x, tPos.y));
	tPos.y += m_gameTitle->GetFontSize() + m_itemSpacing;
	for (int i = 0; i < 2; i++)
	{
		std::string tString= "Empty";
		if (i == 0)
		{
			tString = "Start";
		}
		else if (i == 1)
		{
			tString = "Exit";
		}
		else
			tString = "Empty";
		
		MenuElement* tElem = new MenuElement(tString, tPos, m_itemSize);
		m_menuElems.push_back(tElem);

		tPos.y += m_itemSpacing;
	}

}

void MenuScreen::HandleInput(sf::Keyboard::Key pKey, bool pPressed)
{
	switch (pKey)
	{
	case sf::Keyboard::Up:
	{
		break;
	}
	case sf::Keyboard::Down:
	{
		break;
	}
	case sf::Keyboard::Enter:
	{
		m_applicationPtr->m_appState = Application::AppState::IN_GAME;
		break;
	}
	}
}

void MenuScreen::Render(sf::RenderWindow & pWindow)
{
	m_gameTitle->Render(pWindow);
	for (auto tElem : m_menuElems)
	{
		tElem->Render(pWindow);
	}
}
