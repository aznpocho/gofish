//
// Created by kevin on 11/8/2018.
//

#include "deck.h"

//Default Constructor
// place 52 ordered cards in the deck.
Deck::Deck(){

    int rank = 1;
    for (int idx = 1; idx < 50; idx += 4){
        myCards[idx - 1] = Card(rank, Card::spades);
        myCards[idx] = Card(rank, Card::hearts);
        myCards[idx + 1] = Card(rank, Card::diamonds);
        myCards[idx + 2] = Card(rank, Card::clubs);
        rank = rank + 1; }

    myIndex = 0;

    // seeding the random number generator
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator
}


/* FUNCTION - int Deck::size()
 * returns current size of deck

 input parms -  none

 output parms - current size of deck
*/
int Deck::size() const{
    return(SIZE-myIndex);
}


/* FUNCTION - void Deck::shuffle()
 * shuffles the deck

 precondition - the deck must have at least 3 cards to shuffle

 input parms -  none

 output parms - none
*/
void Deck::shuffle() {
    int idx1, idx2;

    // shuffle only when appropriate
    if (size() > 2) {
        for (int i = 0; i < size() * 2; i++) {
            //choose random indexes
            idx1 = (rand() % size()) + myIndex;
            idx2 = (rand() % size()) + myIndex;


            //swap
            Card temp = myCards[idx1];
            myCards[idx1] = myCards[idx2];
            myCards[idx2] = temp;
        }
    }
}


/* FUNCTION - Card Deck::dealCard()
 * deals a card to player

 pre-condition - there's a card to deal

 input parms -  none

 output parms - card dealt
*/
Card Deck::dealCard() {
    if (myIndex < 52) {
        myIndex = myIndex + 1;
        return (myCards[myIndex - 1]);
    }
}
