//
// Created by kevin on 11/8/2018.
//

#ifndef GOFISH_GO_FISH_H
#define GOFISH_GO_FISH_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "player.h"
#include <ctime>
#include <cstdlib>
#include <string>

#endif //GOFISH_GO_FISH_H

/* FUNCTION: void dealHand(Deck &d, Player &p, int numCards)
 * Deals a certain number of cards to a player.

   input - A deck, a player to deal to and number of cards to be dealt

   output - none
*/
void dealHand(Deck &d, Player &p, int numCards);


/* FUNCTION: int playGame(Player& p1, Player& p2, Deck& d);
 * Plays the whole game gold fish between two players only,
 * with one different rule: You get to keep drawing cards while
 * your guesses are correct, even if you get an empty hand at one point.
 * The winner is the player with the most books.

   input - two players and a deck

   output -
        * 1 -- if player one wins
        * 2 -- if player two wins
        * 0 -- if there's a tie
*/
int playGame(Player& p1, Player& p2, Deck& d, ofstream& write_file);
