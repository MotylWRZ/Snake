#include <iostream>
#include <SFML/Graphics.hpp>
#include "Application.h"
int main()
{
	Application Game(1240, 720, "SnakeGame");
	Game.Run();
	
	system("PAUSE");
	return 0;
}