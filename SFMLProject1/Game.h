#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include <iostream>

namespace Textures
{
	enum ID
	{
		Landscape,
		Airplane,
		Missile
	};
}

class Game
{
public:
	Game();
	void run();
	~Game();
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void updateStatistics(sf::Time elapsedTime);

	static const float PlayerSpeed;
	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow;
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
	std::size_t mStatisticsNumFrames;

	ResourceHolder<sf::Texture, Textures::ID> textures;
	sf::Sprite mPlayer;
	sf::Text mStatisticsText;
	sf::Font mFont;
	sf::Time mStatisticsUpdateTime;
};
