#include "SnakeBodyElem.h"



SnakeBodyElem::SnakeBodyElem(sf::Vector2f pSize, sf::Vector2f pPosition, sf::Color pColor)
	:m_size(pSize)
	,m_position(pPosition)
	,m_color(pColor)
{
	m_elemShape.setSize(m_size);
	m_elemShape.setPosition(m_position);
	m_elemShape.setFillColor(m_color);
}

SnakeBodyElem::SnakeBodyElem(const SnakeBodyElem& pOther) //Copy Constructor Implementation
	:m_size(pOther.m_size)
	, m_position(pOther.m_position)
	, m_color(pOther.m_color)
{
	m_elemShape.setSize(m_size);
	m_elemShape.setPosition(m_position);
	m_elemShape.setFillColor(m_color);
}

SnakeBodyElem::~SnakeBodyElem()
{
}
