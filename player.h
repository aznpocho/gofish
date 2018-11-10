//
// Created by kevin on 11/8/2018.
//

#ifndef GOFISH_PLAYER_H
#define GOFISH_PLAYER_H

#endif //GOFISH_PLAYER_H

// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "deck.h"
using namespace std;


class Player
{
public:

    // Constructor
    // gives player a default name, an empty hand, and empty book
    Player();

    // Constructor name given
    // gives player desired name, an empty hand, and empty book
    Player(string name);

    //returns player's name
    string getName() const {
        return myName;
    }

    /* FUNCTION - void Player::addCard(Card c)
     * adds a card to the player's hand

     input parms -  card to be added

     output parms - none
    */
    void addCard(Card c);


    /* FUNCTION - void Player::bookCards(Card c1, Card c2)
     * Add a pair to the player's book

     precondition: The cards must match

     input parms -  cards to be booked

     output parms - none
    */
    void bookCards(Card c1, Card c2);


    /* FUNCTION - Card Player::chooseCardFromHand() const();
     * chooses a card to ask the player for

     input parms -  none

     output parms - card to ask player for
    */
    Card chooseCardFromHand() const;


    /* FUNCTION: bool Player::cardInHand(Card c) const()
     * check if player has requested card in hand

     input parms -  Card to look for

     output parms - whether card was found or not
    */
    bool cardInHand(Card c) const;


    /* FUNCTION: Card Player::removeCardFromHand(Card c)
     * remove found card from players hand

     pre-condition: card to be removed must be in player's hand

     input parms -  Card to remove

     output parms - returns removed card
    */
    Card removeCardFromHand(Card c);


    /* FUNCTION - string Player::showHand() const
     * Creates and returns a string with the players hand

     input parms - none

     output parms - returns a string with player's hand
    */
    string showHand() const;


    /* FUNCTION - string Player::showBooks() const
     * Creates and returns a string with the player's book

     input parms - none

     output parms - returns a string with player's book
    */
    string showBooks() const;

    /* FUNCTION - int Player::getHandSize() const
     * Check how many cards in a player's hand

     input parms - none

     output parms - returns hand size
    */
    int getHandSize() const;

    /* FUNCTION - int Player::getBookSize() const
     * Check player's book size

     input parms -  none

     output parms - returns book size
    */
    int getBookSize() const;

    /* FUNCTION - void Player::rotateHand()
     * if other player didn't have card asked for, put first
     * card in the back.

     input parms -  none

     output parms - none
    */
    void rotateHand();

    /* FUNCTION - void checkHandForBook();
     * Find pairs within players hand and book them

     input parms -  none

     output parms - none
    */
    void checkHandForBook();



    /*
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    bool rankInHand(Card c) const;

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

    bool sameRankInHand(Card c) const;
    */


private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};


#endif
