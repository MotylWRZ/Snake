#pragma once
#include "UITextElement.h"
class MenuElement
{
public:
	MenuElement();
	~MenuElement();

private:
		bool m_bIsActive;
		sf::Color m_colorActive;
		sf::Color m_colorNotActive;

};

