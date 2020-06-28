#pragma once
#include "SFML/Graphics.hpp"
class SnakeBodyElem
{
public:
	
	SnakeBodyElem() {};
	SnakeBodyElem(sf::Vector2f pSize, sf::Vector2f pPosition, sf::Color pColor);
	
	SnakeBodyElem(const SnakeBodyElem& pOther); // Copy Constructor
	~SnakeBodyElem();

	inline void SetPosition(sf::Vector2f pPos) { m_elemShape.setPosition(pPos); };

	inline sf::Vector2f GetPosition() { return m_elemShape.getPosition(); };
	inline sf::RectangleShape& rGetShape() { return m_elemShape; };
	
private:
	sf::Vector2f m_size;
	sf::Vector2f m_position;
	sf::Color m_color;
	sf::RectangleShape m_elemShape;
	
};

