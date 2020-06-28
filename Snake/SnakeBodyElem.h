#pragma once
#include "SFML/Graphics.hpp"
class SnakeBodyElem
{
public:
	
	
	SnakeBodyElem(sf::Vector2f& pSize, sf::Vector2f& pPosition, sf::Color& pColor);
	
	~SnakeBodyElem();

	/*inline void SetPosition(sf::Vector2f pPos) { m_elemShape.setPosition(pPos); };*/

	/*inline sf::Vector2f& GetPosition() { return m_elemShape.getPosition(); };
	inline sf::RectangleShape& rGetShape() { return m_elemShape; };*/
	sf::RectangleShape m_elemShape;
private:
	
	
};

