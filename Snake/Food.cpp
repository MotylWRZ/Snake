#include "Food.h"



Food::Food(sf::Vector2f pPos, float pRadious, sf::Color pColor, int pScoreValue)
	:m_scoreValue(pScoreValue)
{
	m_foodShape.setPosition(pPos);
	m_foodShape.setRadius(pRadious);
	m_foodShape.setFillColor(pColor);
}


Food::~Food()
{
}

void Food::Reinitialise(sf::Vector2f pPos, float pRadious, sf::Color pColor, int pScoreValue)
	
{
	m_foodShape.setPosition(pPos);
	m_foodShape.setRadius(pRadious);
	m_foodShape.setFillColor(pColor);
	m_scoreValue = pScoreValue;
}

void Food::ReinitialiseRandom()
{
	// Set new, random position
	float tPosX = GetRandomFloatInRange(10.0f, 700.0f);
	float tPosY = GetRandomFloatInRange(10.0f, 700.0f);
	m_foodShape.setPosition(sf::Vector2f(tPosX, tPosY));
	
}

float Food::GetRandomFloatInRange(float pRangeMin, float pRangeMax)
{
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = pRangeMax - pRangeMin;
	float r = random * diff;
	return pRangeMin + r;
}

void Food::Render(sf::RenderWindow& pWindow)
{
	pWindow.draw(m_foodShape);
}
