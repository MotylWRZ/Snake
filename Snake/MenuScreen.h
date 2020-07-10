#pragma once
#include <vector>
#include "UITextElement.h"
#include "MenuElement.h"

class Application;

class MenuScreen
{
public:
	MenuScreen(Application* pAppPtr);
	~MenuScreen();

	void Initialise();
	void HandleInput(sf::Keyboard::Key pKey, bool pPressed);
	void Render(sf::RenderWindow& pWindow);

private:
	UITextElement* m_gameTitle;
	int m_titleSize;
	std::vector<MenuElement*> m_menuElems;
	int m_currentSelection;
	Application* m_applicationPtr;
	int m_itemSize;
	int m_itemSpacing;
	sf::Vector2f m_menuOffset;

};

