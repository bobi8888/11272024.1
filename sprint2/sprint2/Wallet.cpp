#include "Wallet.h"

Wallet::Wallet(){}
Wallet::Wallet(string font, int charSize, sf::Vector2f position) {
	Font.loadFromFile(font);
	Text.setFont(Font);
	Text.setCharacterSize(charSize);
	Text.setPosition(position);
	Text.setString(Plinks);
}
sf::Text Wallet::getText() {
	return Text;
}

int Wallet::getAmount() {
	return Amount;
}

void Wallet::setAmount(int amount) {
	Amount = amount;
}
void Wallet::updateAmount(int amount) {
	Amount += amount;
}

void Wallet::updateAmountString() {
	AmountString = Plinks + to_string(Amount);
	Text.setString(AmountString);
}

int Wallet::getTowerCost() {
	return TowerCost;
}

void Wallet::deductTowerCost() {
	Amount -= TowerCost;
}
