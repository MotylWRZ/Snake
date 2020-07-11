#pragma once
#include "UITextElement.h"
class MenuElement
{
public:
	MenuElement(std::string pText, sf::Vector2f pPosition, int pSize, sf::Color pColorActive = sf::Color::Blue , sf::Color pColorNotActive = sf::Color::White, bool pIsActive = false);
	~MenuElement();

	void Render(sf::RenderWindow& pWindow);
	void SetActive(bool pIsActive);

	//Accesors/Mutators
	inline bool IsActive() { return m_bIsActive; };
	inline sf::Color GetColorActive() { return m_colorActive; };
	inline sf::Color GetColorNotActive() { return m_colorNotActive; };
	inline sf::Vector2f GetPosition() { return m_position; };
	
	inline void SetText(std::string pText) { m_elemText = pText; m_textElem->SetString(m_elemText); };



private:
		std::string m_elemText;
		bool m_bIsActive;
		sf::Color m_colorActive;
		sf::Color m_colorNotActive;
		sf::Vector2f m_position;
		UITextElement* m_textElem;
		int m_size;
};

