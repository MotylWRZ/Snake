#include "UITextElement.h"




UITextElement::UITextElement()
{
}

UITextElement::UITextElement(std::string pText, int pFontSize, sf::Color pTextColor, sf::Vector2f pPosition)
	:m_textString(pText)
	, m_fontSize(pFontSize)
	, m_textColor(pTextColor)
	, m_position(pPosition)
{
	
	m_text.setString(m_textString);
	m_text.setCharacterSize(m_fontSize);
	m_text.setFillColor(m_textColor);
	m_text.setPosition(m_position);

	m_font.loadFromFile("../Fonts/SegoeMarker.ttf");
	m_text.setFont(m_font);
}

UITextElement::~UITextElement()
{
}

void UITextElement::Render(sf::RenderWindow& pWindow)
{
	pWindow.draw(m_text);
}
