//
// Created by kevin on 11/8/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "card.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>

#ifndef GOFISH_DECK_H
#define GOFISH_DECK_H

#endif //GOFISH_DECK_H
// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck will randomize whatever cards are in the deck
// Do not shuffle if you have less than 2 cards
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//

#ifndef _DECK_H
#define _DECK_H

#include "card.h"


class Deck
{
    static const int SIZE = 52;

public:

    //Default Constructor
    // place 52 ordered cards in the deck.
    Deck();


    /* FUNCTION - void Deck::shuffle()
     * shuffles the deck

     precondition - the deck must have at least 3 cards to shuffle

     input parms -  none

     output parms - none
    */
    void shuffle();   // shuffle the cards in the current deck


    /* FUNCTION - Card Deck::dealCard()
     * deals a card to player

     input parms -  none

     output parms - card dealt
    */
    Card dealCard();   // get a card, after 52 are dealt, fail


    /* FUNCTION - int Deck::size()
     * returns current size of deck

     input parms -  none

     output parms - current size of deck
    */
    int  size() const; // # cards left in the deck



private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif
