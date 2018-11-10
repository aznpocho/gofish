//
// Created by kevin on 11/8/2018.
//

#ifndef GOFISH_CARD_H
#define GOFISH_CARD_H

#endif //GOFISH_CARD_H
//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
public:

    // defines spades as 0, hearts as 1...etc.
    enum Suit {spades, hearts, diamonds, clubs};

    // Default constructor
    // Ace of Spades
    Card();

    // Constructor
    // input of rank and suit
    Card(int rank, Suit s);

    /* FUNCTION - string Card::toString() const
     * turns a card into a string

     input parms -  none

     output parms - returns a card as a string
    */
    string toString()              const;  // return string version e.g. Ac 4h Js


    /* FUNCTION - bool Card::sameSuitAs(const Card& c) const
     * checks whether two suits are the same

     input parms -  card whose suit is to be checked

     output parms - returns true if same, false otherwise
    */
    bool sameSuitAs(const Card& c) const;


    /* FUNCTION - int Card::getRank() const
     * returns the rank of a card

     input parms -  none

     output parms - returns the number corresponding to card's rank
    */
    int  getRank()                 const;  // return rank, 1..13


    /* FUNCTION - string Card::suitString(Suit s) const
     * turns a suit into a string

     input parms -  suit to be turned to string

     output parms - returns a suit as a string
    */
    string suitString(Suit s)      const;  // return "s", "h",...


    /* FUNCTION - string Card::rankString(int r) const
     * turns an integer to a rank

     input parms -  integer to be turned to rank

     output parms - returns a string with corresponding rank
    */
    string rankString(int r)       const;  // return "A", "2", ..."Q"


    /* FUNCTION - bool Card::operator ==(const Card& rhs) const
      * overloads the == operator to compare ranks

      input parms -  Card to the right of operator

      output parms - returns true if the ranks are equal, false otherwise
     */
    bool operator == (const Card& rhs) const;

    /* FUNCTION - bool Card::operator !=(const Card& rhs) const
     * overloads the != operator to check two ranks being unequal

     input parms -  card to the right of operator

     output parms - returns true if the ranks aren't equal, false otherwise
    */
    bool operator != (const Card& rhs) const;



private:

    int myRank;
    Suit mySuit;


};


/* FUNCTION - ostream& operator << (ostream& out, const Card& c)
 * overloads the output operator to be able to print a card to screen

 input parms - card to be printed

 output parms - returns the corrected format to ostream
*/
ostream& operator << (ostream& out, const Card& c);



#endif