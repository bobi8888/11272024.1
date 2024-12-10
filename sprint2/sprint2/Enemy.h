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
		int Value = 50;
		float PrevX = 0.f, PrevY = 0.f;
		bool IsAboveMid;
		int Damage = 25;

	public:
		Enemy(){}
		Enemy(string sprite, sf::Vector2f position);
		Enemy(string sprite, sf::Vector2f position, float speed, float targetY);
		Enemy(string sprite, float speed, Path path);

		bool IsAlive = true;

		int getDamage();
		void setDamage(int dmg);
		bool getIsAlive();
		void setIsAlive(bool isAlive);

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
		bool isDestroyed();

		bool getIsAboveMid();
		int getValue();

		~Enemy(){}
};

