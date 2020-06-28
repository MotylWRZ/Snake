#include "Snake.h"



Snake::Snake()
	:m_health(100)
	, m_speed(20.0f)
	, m_foodColected(0)
	, m_eCurrMoveDirection(E_MOVE_RIGHT)
	, m_movement(m_speed, 0.0f)
{

	sf::Vector2f tPos(100.0f, 100.0f);
	sf::RectangleShape tShape = sf::RectangleShape(sf::Vector2f(20.0f, 20.0f));
	for (int i = 0; i < 10; i++)
	{
		
		m_snakeBody.PushFront(tShape);
		m_snakeBody.GetHeadPtr()->data.setPosition(tPos);
		tPos.x += 21.0f;
	}
	
}


Snake::~Snake()
{
}

void Snake::Move()
{
	/*if (m_snakeBody.Length() > 0)
	{
		auto tCurrElem = m_snakeBody.GetHeadPtr();
		while (tCurrElem != nullptr)
		{
			tCurrElem->data.move(m_movement);
			tCurrElem = tCurrElem->next;
		}
	}*/
	if (m_snakeBody.Length() > 0)
{
		/*sf::Vector2f tPos = m_snakeBody.GetEndPtr()->data.getPosition();
		sf::Vector2f tTurnPos = m_snakeBody.GetHeadPtr()->data.getPosition();
		sf::RectangleShape shape(sf::Vector2f(20.0f, 20.0f));
		if (tPos == tTurnPos)
		{
			shape.setPosition(tPos + m_movement);
			m_snakeBody.PushBack(shape);
			m_snakeBody.PopBack();
		}
		else
		{
			shape.setPosition(tPos + -m_movement);
			m_snakeBody.PushFront(shape);
			m_snakeBody.PopBack();
		}*/
		auto tCurrElem = m_snakeBody.GetHeadPtr();
		sf::Vector2f tPos = tCurrElem->data.getPosition();
		//tCurrElem->next->data.setPosition(tCurrElem->data.getPosition());
		m_snakeBody.PopBack();
		sf::RectangleShape shape(sf::Vector2f(20.0f, 20.0f));
		shape.setPosition(tPos + m_movement);
		m_snakeBody.PushFront(shape);
	
		
		
}
	
}

void Snake::Render(sf::RenderWindow& pWindow)
{
	if (m_snakeBody.Length() > 0)
	{
		auto tCurrElem = m_snakeBody.GetHeadPtr();
		while (tCurrElem != nullptr)
		{
			pWindow.draw(tCurrElem->data);
			tCurrElem = tCurrElem->next;
		}
	}
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