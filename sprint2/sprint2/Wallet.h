#pragma once
#include "utils.h"

class Wallet {
	private:
		sf::Font Font;
		sf::Text Text;
		string Plinks = "Plinks: ";
		string AmountString = "";
		int Amount = 100;
		int TowerCost = 50;

	public:
		Wallet();
		Wallet(string font, int charSize, sf::Vector2f position);
		sf::Text getText();
		int getAmount();
		void setAmount(int amount);
		void updateAmount(int amount);
		void updateAmountString();
		int getTowerCost();
		void deductTowerCost();
};

