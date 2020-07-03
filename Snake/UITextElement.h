#pragma once
#include <SFML/Graphics.hpp>
#include "UITextElement.h"
#include <string>
class UITextElement
{
public:
	UITextElement();
	UITextElement(std::string pText, int pFontSize, sf::Color pTextColor, sf::Vector2f pPosition);
	~UITextElement();

private:
	sf::Text  m_text;
	std::string m_textString;
	int		  m_fontSize;
	sf::Color m_textColor;
	sf::Vector2f m_position;
};

