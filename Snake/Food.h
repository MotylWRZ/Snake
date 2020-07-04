#pragma once
#include "SFML/Graphics.hpp"
class Food
{
public:
	inline Food() {};
	Food(sf::Vector2f pPos, float pRadious, sf::Color pColor, int pScoreValue);
	virtual ~Food();

	void Reinitialise(sf::Vector2f pPos, float pRadious, sf::Color pColor, int pScoreValue);
	void ReinitialiseRandom(float tPosXMin, float tPosXMax, float tPosYMin, float tPosYMax);
	void Render(sf::RenderWindow& pWindow);


	//Accesors/Mutators
	inline void SetScoreValue(int pScore) { m_scoreValue = pScore; };
	
	inline int GetScoreValue() { return m_scoreValue; };
	inline sf::CircleShape& rGetShape() { return m_foodShape; };

private:
	float GetRandomFloatInRange(float pRangeMin, float pRangeMax);

private:
	sf::CircleShape	 m_foodShape;
	int				 m_scoreValue;
	sf::Vector2f	 m_position;
	sf::Color		 m_color;
};

