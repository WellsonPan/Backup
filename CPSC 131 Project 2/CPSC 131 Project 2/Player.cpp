//
//  Player.cpp
//

#include "Player.h"

// TO DO: implement Player's assignment operator
Player& Player::operator=(const Player& p) {
	if (this != &p)
	{
		playerName = p.getName();
		position = p.getPosition();
		die = p.die;
	}
	return *this;
	// TODO: implement this function properly
	//throw std::logic_error("not implemented yet");
}

// return player's new position after player rolls die
// If the new position is outside of the board, player stays put
// If not, player moves to the new square = player's postion + die's face value
// TO DO: implement this function to move player to the new postion
//        after player rolls die. Position must be inside the board
int Player::rollDieAndMove() {
	Die rollDie;
	if ((position + rollDie.getFaceValue()) > 100)
	{
		return position;
	}
	else
	{
		position += rollDie.getFaceValue();
		return position;
	}
	// TODO: implement this function properly
	//throw std::logic_error("not implemented yet");
}