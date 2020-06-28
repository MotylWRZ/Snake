#include "Snake.h"



Snake::Snake()
	:m_health(100)
	, m_speed(20.0f)
	, m_foodColected(0)
	, m_eCurrMoveDirection(E_MOVE_RIGHT)
	, m_movement(m_speed, 0.0f)
	, m_snakeBodyElemSize(sf::Vector2f(20.0f, 20.0f))
	, m_position(sf::Vector2f(100.0f, 100.0f))
	, m_headColor(sf::Color::Green)
	, m_bodyColor(sf::Color::White)
{
	
	sf::Vector2f tPos(100.0f, 100.0f);
	SnakeBodyElem tElem(m_snakeBodyElemSize, m_position, m_bodyColor);
	for (int i = 0; i < 10; i++)
	{
		m_snakeBody.PushFront(tElem);
		m_snakeBody.GetHeadPtr()->data.SetPosition(tPos);
		tPos.x += 21.0f;
	}
	
}


Snake::~Snake()
{
}

void Snake::ChangeMoveDirection(EMoveDirection pNewDirection)
{

	m_eCurrMoveDirection = pNewDirection;
	switch (m_eCurrMoveDirection)
	{
	case E_MOVE_UP:
	{
		m_movement = sf::Vector2f(0.0f, -m_speed);
		break;
	}
	case E_MOVE_DOWN:
	{
		m_movement = sf::Vector2f(0.0f, m_speed);
		break;
	}
	case E_MOVE_LEFT:
	{
		m_movement = sf::Vector2f(-m_speed, 0.0f);
		break;
	}
	case E_MOVE_RIGHT:
	{
		m_movement = sf::Vector2f(m_speed, 0.0f);
		break;
	}
	}

}

void Snake::HandleInput(sf::Keyboard::Key pKey, bool pPressed)
{
	if (!pPressed)
		return;

	switch (pKey)
	{
	case sf::Keyboard::Up:
	{
		ChangeMoveDirection(E_MOVE_UP);
		break;
	}
	case sf::Keyboard::Down:
	{
		ChangeMoveDirection(E_MOVE_DOWN);
		break;
	}
	case sf::Keyboard::Left:
	{
		ChangeMoveDirection(E_MOVE_LEFT);
		break;
	}
	case sf::Keyboard::Right:
	{
		ChangeMoveDirection(E_MOVE_RIGHT);
		break;
	}
	}
}


void Snake::Move()
{
	//Check wheter the lenght of the list(SnakeBody) is greater than 0
	if (m_snakeBody.Length() > 0)
	{
		auto tCurrElem = m_snakeBody.GetHeadPtr();
		sf::Vector2f tPos = tCurrElem->data.GetPosition();
		m_snakeBody.PopBack(); // Delete the last node
		// Create a new element at updated position
		SnakeBodyElem tBodyElem(m_snakeBodyElemSize, sf::Vector2f(tPos + m_movement), m_bodyColor); 
		m_snakeBody.PushFront(tBodyElem); // Add new element to the fronmt of the list
	}
	
}


void Snake::Update(float pDeltaTime)
{
	this->Move();
}

void Snake::Render(sf::RenderWindow& pWindow)
{
	if (m_snakeBody.Length() > 0)
	{
		auto tCurrElem = m_snakeBody.GetHeadPtr();
		while (tCurrElem != nullptr)
		{
			pWindow.draw(tCurrElem->data.rGetShape());
			tCurrElem = tCurrElem->next;
		}
	}
}

