#include "Snake.h"
#include "Food.h"



Snake::Snake(sf::Vector2f pInitialPosition, float pSpeed, int pInitialLength)
	:m_health(100)
	, m_speed(pSpeed)
	, m_foodColected(0)
	, m_eCurrMoveDirection(E_MOVE_RIGHT)
	, m_movement(m_speed + m_BodyElemSpace, 0.0f)
	, m_snakeBodyElemSize(sf::Vector2f(20.0f, 20.0f))
	, m_position(sf::Vector2f(pInitialPosition))
	, m_headColor(sf::Color::Blue)
	, m_bodyColor(sf::Color::White)
	, m_bIsAlive(true)
	, m_worldCollisionActive(false)
	, m_worldBounds(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f))
	, m_BodyElemSpace(1.0f)
	, m_initialSnakeLength(pInitialLength)
{
	sf::Vector2f tPos(100.0f, 100.0f);
	SnakeBodyElem tElem(m_snakeBodyElemSize, m_position, m_bodyColor);
	for (int i = 0; i < m_initialSnakeLength; i++)
	{
		m_snakeBody.PushFront(tElem);
		m_snakeBody.GetHeadPtr()->data.SetPosition(tPos);
		tPos.x += m_snakeBodyElemSize.x + m_BodyElemSpace;
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
		m_movement = sf::Vector2f(0.0f, -m_speed - m_BodyElemSpace);
		break;
	}
	case E_MOVE_RIGHT:
	{
		m_movement = sf::Vector2f(m_speed + m_BodyElemSpace, 0.0f);
		break;
	}
	case E_MOVE_DOWN:
	{
		m_movement = sf::Vector2f(0.0f, m_speed + m_BodyElemSpace);
		break;
	}
	case E_MOVE_LEFT:
	{
		m_movement = sf::Vector2f(-m_speed - m_BodyElemSpace, 0.0f);
		break;
	}
	}
}

void Snake::HandleInput(sf::Keyboard::Key pKey, bool pPressed)
{
	if (!pPressed)
		return;

	int tCurrentDirection = int(m_eCurrMoveDirection);

	switch (pKey)
	{
	case sf::Keyboard::Left:
	{
		tCurrentDirection--;
		if (tCurrentDirection < 0)
			tCurrentDirection = 3;

		ChangeMoveDirection(EMoveDirection(tCurrentDirection));
		break;
	}
	case sf::Keyboard::Right:
	{
		tCurrentDirection++;
		if (tCurrentDirection > 3)
			tCurrentDirection = 0;

		ChangeMoveDirection(EMoveDirection(tCurrentDirection));
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
		// Create a new element at updated position. Set color as a head color as this will be a new front node (head)
		SnakeBodyElem tBodyElem(m_snakeBodyElemSize, sf::Vector2f(tPos + m_movement), m_headColor); 
		m_snakeBody.PushFront(tBodyElem); // Add new element to the fronmt of the list
		// Get the next node (body element) and set the color of it to the body color
		m_snakeBody.GetHeadPtr()->next->data.rGetShape().setFillColor(m_bodyColor);
	}
}

void Snake::AddBodyElem()
{
	auto tCurrElem = m_snakeBody.GetEndPtr();
	sf::Vector2f tPos = tCurrElem->data.GetPosition();
	SnakeBodyElem tBodyElem(m_snakeBodyElemSize, sf::Vector2f(tPos + m_movement), m_bodyColor);
	m_snakeBody.PushBack(tBodyElem);
}

void Snake::CheckSnakeSnakeCollision()
{
	auto tCurrElem = m_snakeBody.GetHeadPtr()->next;
	while (tCurrElem->next != nullptr)
	{
		if (tCurrElem->data.GetPosition() == m_snakeBody.GetHeadPtr()->data.GetPosition())
		{
			this->m_bIsAlive = false;
			break;
		}
		else
		tCurrElem = tCurrElem->next;
	}
}

void Snake::CheckSnakeFoodCollision(Food& pFood)
{
	//Check wheter the snake collides with food object
	if (m_snakeBody.GetHeadPtr()->data.rGetShape().getGlobalBounds().
		intersects(pFood.rGetShape().getGlobalBounds()))
	{
		AddBodyElem(); // Add Body element to the snake
		m_foodColected += pFood.GetScoreValue(); //Increase the current score
		
		if (m_worldCollisionActive)
		{
			//Reinitialise the food at random position using world bounds
			pFood.ReinitialiseRandom(m_worldBounds.left, m_worldBounds.width, m_worldBounds.top, m_worldBounds.height);
		}
		else
		{
			//Reinitialise the food at random position using default values
			pFood.ReinitialiseRandom(100.0f, 700.0f, 100.0f, 700.0f);
		}
	}
}

void Snake::CheckSnakeWorldCollision(sf::FloatRect pWorldBounds)
{
	if (m_snakeBody.GetHeadPtr()->data.GetPosition().x > pWorldBounds.width ||
		m_snakeBody.GetHeadPtr()->data.GetPosition().x < pWorldBounds.left ||
		m_snakeBody.GetHeadPtr()->data.GetPosition().y > pWorldBounds.height ||
		m_snakeBody.GetHeadPtr()->data.GetPosition().y < pWorldBounds.top)
	{
		this->m_bIsAlive = false;
	}
}

void Snake::HandleCollision(Food& pFood, bool pWorldCollisionActive, sf::FloatRect pWorldBounds)
{
	m_worldCollisionActive = pWorldCollisionActive;
	m_worldBounds = pWorldBounds;

	CheckSnakeSnakeCollision();
	CheckSnakeFoodCollision(pFood);

	if(pWorldCollisionActive)
	CheckSnakeWorldCollision(pWorldBounds);
}
 


void Snake::Update(float pDeltaTime)
{
	if (!m_bIsAlive)
		return;
	
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

