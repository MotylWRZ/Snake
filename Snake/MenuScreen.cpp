#include "MenuScreen.h"
#include "Application.h"


MenuScreen::MenuScreen(Application* pAppPtr)
	:m_applicationPtr(pAppPtr)
	,m_itemSize(70)
	,m_itemSpacing(m_itemSize)
	,m_menuOffset(-m_itemSize, -200.0f)
	,m_titleSize(120)
	,m_currentSelection(0)
{
}


MenuScreen::~MenuScreen()
{
	// Delete all menu elements allocated dynamically in memory
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

	// Create and position the Game Title
	m_gameTitle = new UITextElement("SssNAKE", m_titleSize, sf::Color::White, sf::Vector2f(tPos.x, tPos.y));
	tPos.y += m_gameTitle->GetFontSize();

	// Create the menu elements
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
			if(pPressed)
			OnMoveUp();
		break;
	}
	case sf::Keyboard::Down:
	{
			if (pPressed)
			OnMoveDown();
		break;
		
	}
	case sf::Keyboard::Enter:
	{
			OnSelect();
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

void MenuScreen::OnMoveUp()
{
	m_currentSelection = (--m_currentSelection + m_menuElems.size()) % m_menuElems.size();

	//Reset all menu elements and set them as not active
	for (auto& tElem : m_menuElems)
	{
		tElem->SetActive(false); 
	}
	//Set currently seletced element as active
	m_menuElems[m_currentSelection]->SetActive(true);
}

void MenuScreen::OnMoveDown()
{
	m_currentSelection = (++m_currentSelection + m_menuElems.size()) % m_menuElems.size();

	//Reset all menu elements and set them as not active
	for (auto& tElem : m_menuElems)
	{
		tElem->SetActive(false);
	}
	//Set currently seletced element as active
	m_menuElems[m_currentSelection]->SetActive(true);
}

void MenuScreen::OnSelect()
{
	switch (m_currentSelection)
	{
	case 0:
	{
		m_applicationPtr->m_appState = Application::AppState::IN_GAME;
		break;
	}
	case 1:
	{
		m_applicationPtr->m_appState = Application::AppState::EXIT;
		break;
	}
	}
}
