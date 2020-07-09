#include "MenuElement.h"



MenuElement::MenuElement(std::string pText, sf::Vector2f pPosition, int pSize, sf::Color pColorActive, sf::Color pColorNotActive, bool pIsActive)
	:m_elemText(pText)
	, m_position(pPosition)
	, m_size(pSize)
	, m_colorActive(pColorActive)
	, m_colorNotActive(pColorNotActive)
	, m_bIsActive(pIsActive)
{
	if (m_bIsActive)
		m_textElem = new UITextElement(m_elemText, m_size, m_colorActive, m_position);
	else
		m_textElem = new UITextElement(m_elemText, m_size, m_colorNotActive, m_position);
}


MenuElement::~MenuElement()
{
	delete m_textElem;
}

void MenuElement::Render(sf::RenderWindow& pWindow)
{
	m_textElem->Render(pWindow);
}

void MenuElement::SetActive(bool pIsActive)
{
	if (pIsActive)
		m_textElem->SetFillColor(m_colorActive);
	else
		m_textElem->SetFillColor(m_colorNotActive);

	m_bIsActive = pIsActive;
}
