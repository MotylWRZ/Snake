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
	
	m_font.loadFromFile("../Fonts/SegoeMarker.ttf");
	m_text.setFont(m_font);

	m_text.setOrigin(m_text.getLocalBounds().left + m_text.getLocalBounds().width / 2.0f,
		m_text.getLocalBounds().top + m_text.getLocalBounds().height / 2.0f);
	m_text.setPosition(m_position);
}

UITextElement::UITextElement(const UITextElement& pOther)
	:m_textString(pOther.m_textString)
	, m_fontSize(pOther.m_fontSize)
	, m_textColor(pOther.m_textColor)
	, m_position(pOther.m_position)
{
	m_font = pOther.m_font;
	m_text = pOther.m_text;
}

UITextElement::~UITextElement()
{
}

void UITextElement::Render(sf::RenderWindow& pWindow)
{
	pWindow.draw(m_text);
}
