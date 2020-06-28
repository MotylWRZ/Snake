#include "SnakeBodyElem.h"



SnakeBodyElem::SnakeBodyElem(sf::Vector2f& pSize, sf::Vector2f& pPosition, sf::Color& pColor)
{
	m_elemShape.setSize(pSize);
	m_elemShape.setPosition(pPosition);
	m_elemShape.setFillColor(pColor);
}


SnakeBodyElem::~SnakeBodyElem()
{
}
