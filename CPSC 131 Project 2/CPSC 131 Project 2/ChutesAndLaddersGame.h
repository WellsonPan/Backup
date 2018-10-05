//
//  ChutesAndLaddersGame.hpp
//

#pragma once

#include <stdio.h>
#include <string>

#include "ArrayQueue.h"
#include "Player.h"
#include "GameBoard.h"

using namespace std;

// TO DO - change the default value to the number of your team members
const int MIN_NUMBER_OF_PLAYERS = 2;

class ChutesAndLaddersGame {
private:
	const int WINNING_POSITION = 100;

	string winner;       // the winner
	GameBoard gameBoard; // the game board

						 // TO DO: use ArrayQueue to store the players
	ArrayQueue<Player> group;

public:
	// TODO: implement the constructor with all your team members
	// constructor with the default value of 2 minimim players
	ChutesAndLaddersGame(int nPlayers = MIN_NUMBER_OF_PLAYERS);

	// TODO: implement the destructor
	// destructor
	~ChutesAndLaddersGame();

	// accessors
	// TO DO: implement the accessor to get the number Of Players
	long getNumberOfPlayers() {
		return group.size();
		// TODO: implement this function properly
		//throw std::logic_error("not implemented yet");
	}
	string getWinner() { return winner; }

	// TODO: implement this function properly
	// reset the game - (1) this will reset the position of each player to zero
	void resetGame();

	// TODO: implement this function properly
	// play the Chutes and Ladders game
	void playGame();
};