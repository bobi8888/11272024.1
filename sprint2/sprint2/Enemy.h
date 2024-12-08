#pragma once
#include "utils.h"
#include "Path.h"


class Enemy {
	private:
		sf::Texture Texture;
		sf::Sprite Sprite;
		const float BaselineHP = 5.f;
		float HP = 5.f;
		float Speed = 10;
		int PathIndex = 0;
		bool IsActive = false;
		bool IsAlive = true;

		float PrevX = 0.f, PrevY = 0.f;
		bool IsAboveMid;

	public:
		Enemy(){}
		Enemy(string sprite, sf::Vector2f position);
		Enemy(string sprite, sf::Vector2f position, float speed, float targetY);
		Enemy(string sprite, float speed, Path path);

		sf::Sprite getSprite();
		void setPosition(sf::Vector2f position);

		int getPathIndex();
		void incrementPathIndex();

		float getPrevX();
		void setPrevX();
		float getPrevY();
		void setPrevY();

		float getX();
		float getY();
		void updateX();
		void updateY();

		bool getIsActive();
		void setIsActive(bool isActive);

		float getHP();
		void setHP(float damage);
		void healHP();

		bool getIsAboveMid();

		~Enemy(){}
};

