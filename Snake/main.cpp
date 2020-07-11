#include <iostream>
#include <SFML/Graphics.hpp>
#include "Application.h"
int main()
{
	Application Game(1240, 720, "SnakeGame");
	Game.Initialise();
	Game.Run();
	
	
	return 0;
}