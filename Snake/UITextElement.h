#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class UITextElement
{
public:
	UITextElement();
	UITextElement(std::string pText, int pFontSize, sf::Color pTextColor, sf::Vector2f pPosition);
	UITextElement(const UITextElement& pOther); //Copy Constructor
	~UITextElement();

	void Render(sf::RenderWindow& pWindow);

	//Accesors/Mutators
	inline sf::Vector2f GetPosition() { return m_position; };
	inline std::string GetString() { return m_textString; };
	inline int GetFontSize() { return m_fontSize; };

	inline void SetPosition(sf::Vector2f pNewPos) { m_position = pNewPos; m_text.setPosition(m_position); };
	inline void SetFillColor(sf::Color pNewColor) { m_textColor = pNewColor; m_text.setFillColor(m_textColor); };
	inline void SetFontSize(int pNewSize) { m_fontSize = pNewSize; m_text.setCharacterSize(m_fontSize); };
	inline void SetString(std::string pString) { m_textString = pString; m_text.setString(m_textString); };

private:
	sf::Text  m_text;
	std::string m_textString;
	int		  m_fontSize;
	sf::Color m_textColor;
	sf::Vector2f m_position;
	sf::Font m_font;
};

