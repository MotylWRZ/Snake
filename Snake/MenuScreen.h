#pragma once
#include <vector>
#include "UITextElement.h"
#include "MenuElement.h"
class MenuScreen
{
public:
	MenuScreen();
	~MenuScreen();

private:
	std::vector<MenuElement*> m_menuElems;
};

