//
// Created by kevin on 11/8/2018.
//

#include "card.h"

using namespace std;

// Default constructor
// Ace of Spades
Card::Card(){
    myRank = 1;
    mySuit = spades;
}

// Constructor
// input of rank and suit
Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

/* FUNCTION - string Card::toString() const
 * turns a card into a string

 input parms -  none

 output parms - returns a card as a string
*/
string Card::toString() const{
    string card_str = rankString(myRank)+suitString(mySuit);
    return(card_str);
}


/* FUNCTION - string Card::suitString(Suit s) const
 * turns a suit into a string

 input parms -  suit to be turned to string

 output parms - returns a suit as a string
*/
string Card::suitString(Suit s) const{
    if (s==spades){
        return("s");
    }
    else if (s==hearts){
        return("h");
    }
    else if (s==diamonds){
        return("d");
    }
    else{
        return ("c");
    }
}

/* FUNCTION - bool Card::sameSuitAs(const Card& c) const
 * checks whether two suits are the same

 input parms -  card whose suit is to be checked

 output parms - returns true if same, false otherwise
*/
bool Card::sameSuitAs(const Card& c) const{
    return (myRank == c.myRank);
}


/* FUNCTION - int Card::getRank() const
 * returns the rank of a card

 input parms -  none

 output parms - returns the number corresponding to card's rank
*/
int Card::getRank() const{
    return(myRank);
}


/* FUNCTION - string Card::rankString(int r) const
 * turns an integer to a rank

 input parms -  integer to be turned to rank

 output parms - returns a string with corresponding rank
*/
string Card::rankString(int r) const{
    if (r==1){
        return("A");
    }
    else if (r==11){
        return("J");
    }
    else if (r==12){
        return("Q");
    }
    else if (r==13){
        return("K");
    }
    else if (r==2){
        return("2");
    }
    else if (r==3){
        return("3");
    }
    else if (r==4){
        return("4");
    }
    else if (r==5){
        return("5");
    }
    else if (r==6){
        return("6");
    }
    else if (r==7){
        return("7");
    }
    else if (r==8){
        return("8");
    }
    else if (r==9){
        return("9");
    }
    else{
        return("10");
    }
}

/* FUNCTION - bool Card::operator ==(const Card& rhs) const
 * overloads the == operator to compare ranks

 input parms -  Card to the right of operator

 output parms - returns true if the ranks are equal, false otherwise
*/
bool Card::operator ==(const Card& rhs) const{
    return (myRank == rhs.myRank);
}

/* FUNCTION - bool Card::operator !=(const Card& rhs) const
 * overloads the != operator to check two ranks being unequal

 input parms -  card to the right of operator

 output parms - returns true if the ranks aren't equal, false otherwise
*/
bool Card::operator !=(const Card& rhs) const{
    return (myRank != rhs.myRank);
}

/* FUNCTION - ostream& operator << (ostream& out, const Card& c)
 * overloads the output operator to be able to print a card to screen

 input parms - card to be printed

 output parms - returns the corrected format to ostream
*/
ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return(out);
}