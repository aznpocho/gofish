//
// Created by kevin on 11/8/2018.
//

#include "player.h"

// Constructor
// gives player a default name, an empty hand, and empty book
Player::Player(){
    myName = "Player";
}

// Constructor name given
// gives player desired name, an empty hand, and empty book
Player::Player(string name){
    myName = name;
}


/* FUNCTION - void Player::addCard(Card c)
 * adds a card to the player's hand

 input parms -  card to be added

 output parms - none
*/
void Player::addCard(Card c){
    myHand.push_back(c);
}


/* FUNCTION - void Player::bookCards(Card c1, Card c2)
 * Add a pair to the player's book

 precondition: The cards must match

 input parms -  cards to be booked

 output parms - none
*/
void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}



/* FUNCTION - Card Player::chooseCardFromHand() const();
 * chooses a card to ask the player for

 input parms -  none

 output parms - card to ask player for
*/
Card Player::chooseCardFromHand() const{
    return(myHand[0]);
}


/* FUNCTION - void Player::rotateHand()
 * if other player didn't have card asked for, put first
 * card in the back.

 input parms -  none

 output parms - none
*/
void Player::rotateHand() {

    Card temp = myHand[0];
    myHand.push_back(temp);
    myHand.erase(myHand.begin());
}


/* FUNCTION: bool Player::cardInHand(Card c) const()
 * check if player has requested card in hand

 input parms -  Card to look for

 output parms - whether card was found or not
*/
bool Player::cardInHand(Card c) const{
    bool found = false;
    int idx = 0;

    while (!found && (idx < myHand.size())){
        if (myHand[idx] == c){
            found = true;
        }
        idx ++;
    }


    return(found);
}


/* FUNCTION: Card Player::removeCardFromHand(Card c)
 * remove found card from players hand

 pre-condition: card to be removed must be in player's hand

 input parms -  Card to remove

 output parms - returns removed card
*/
Card Player::removeCardFromHand(Card c){
    bool found = false;
    vector<Card>::iterator iter;
    Card erased_card;

    for (iter = myHand.begin(); (iter != myHand.end()) && !found; iter ++){
        if (*iter == c){
            found = true;
            erased_card = *iter;
            myHand.erase(iter);
        }
    }
    return (erased_card);
}


/* FUNCTION - string Player::showHand() const
 * Creates and returns a string with the players hand

 input parms - none

 output parms - returns a string with player's hand
*/
string Player::showHand() const{
    vector<Card>::const_iterator iter;
    string hand_str;

    //iterates through hand and adds it to string
    for(iter = myHand.begin(); iter != myHand.end(); iter++){
        hand_str = hand_str + (*iter).toString() + " ";
    }
    return (hand_str);
}

/* FUNCTION - string Player::showBooks() const
 * Creates and returns a string with the player's book

 input parms - none

 output parms - returns a string with player's book
*/
string Player::showBooks() const{
    vector<Card>::const_iterator iter;
    string book_str;
    for(iter = myBook.begin(); iter != myBook.end(); iter += 2){
        book_str = book_str + (*iter).toString() + " ";
        book_str = book_str + (*(iter + 1)).toString() + "\n";
    }
    return (book_str);
}

/* FUNCTION - int Player::getHandSize() const
 * Check how many cards in a player's hand

 input parms - none

 output parms - returns hand size
*/
int Player::getHandSize() const{
    return(myHand.size());
}

/* FUNCTION - int Player::getBookSize() const
 * Check player's book size

 input parms -  none

 output parms - returns book size
*/
int Player::getBookSize() const{
    return(myBook.size()/2);
}

/* FUNCTION - void checkHandForBook();
 * Find pairs within players hand and book them

 input parms -  none

 output parms - none
*/
void Player::checkHandForBook(){
    int i = 0;
    while ((getHandSize() > 1) && (i < getHandSize() - 1)){
        int j = i + 1;
        while ((j < getHandSize()) && (myHand[i]!=myHand[j])){
            j++;
        }
        if ((myHand[i]==myHand[j]) && (i < getHandSize()-1) && (j < getHandSize())){
            bookCards(myHand[i],myHand[j]);
            removeCardFromHand(myHand[i]);
            removeCardFromHand(myHand[j-1]);
            i=0;
        }
        else{
            i++;
        }
    }
}