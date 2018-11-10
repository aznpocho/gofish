//
// Created by kevin on 11/8/2018.
//

#include "go_fish.h"
// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides write_file and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include <string>
/*
#include "card.h"
#include "player.h"
#include "deck.h"
 */
#include "go_fish.h"

using namespace std;

/* FUNCTION: void dealHand(Deck &d, Player &p, int numCards)
 * Deals a certain number of cards to a player.

   input - A deck, a player to deal to and number of cards to be dealt

   output - none
*/
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

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
int playGame(Player& p1, Player& p2, Deck& d, ofstream& write_file){
    Card card_played; // holds card played
    string card_played_rank; // string version of card played's rank
    Card card_dealt; // card obtained from deck
    bool card_in_hand; // dictates how long a player's turn is
    int turn = 1; // player turn, 1 begins
    bool continue_game = true; // dictates when game ends
    int size_b4_check_book; // to determine when to book

    // checks player hands for pairs
    p1.checkHandForBook();
    p2.checkHandForBook();


    // Play game while deck is not empty
    while (((p1.getBookSize() + p2.getBookSize()) < 26) && continue_game){

        // player 1's turn
        if (turn == 1) {
            card_in_hand = true;

            // continue while still player turn
            while (card_in_hand) {

                // show player hands
                write_file << endl << p1.getName() << " hand: " << p1.showHand() << endl;
                write_file << p2.getName() << " hand: " << p2.showHand() << endl;

                // player's turn and hand not empty
                if (p1.getHandSize() > 0) {

                    // ask opponent for card
                    card_played = p1.chooseCardFromHand();
                    card_played_rank = card_played.rankString(card_played.getRank());
                    write_file << "\n" << p1.getName() << " asks - Do you have a "
                               << card_played_rank << "? \n";


                    // opponent checks hand for requested card
                    write_file << p2.getName() << " says - ";


                    // if requested card in opponents hand:
                    // given to player, booked, and removed from
                    // opponents hand.
                    if (p2.cardInHand(card_played)) {

                        write_file << "Yes. I have a " << card_played_rank << ".\n";
                        write_file << p1.getName() << " books the " << card_played_rank << "... \n";
                        p1.bookCards(card_played, p2.removeCardFromHand(card_played));
                        p1.removeCardFromHand(card_played);
                        card_in_hand = true; // still player's hand while keeps guessing right
                    }



                    else {

                        // if requested card NOT in opponents hand:
                        // GoFish, places card in hand and checks if there's
                        // a pair. This ENDS player turn. The denied hand is
                        // moved to end of player hand.
                        if (d.size() > 0) { // deck not empty

                            card_dealt = d.dealCard();
                            write_file << "Go Fish\n" << p1.getName() << " draws " << card_dealt << "\n";
                            p1.addCard(card_dealt);
                            size_b4_check_book = p1.getHandSize();
                            p1.checkHandForBook();

                            // if found pair with NEW card, print booked card to console
                            if (p1.getHandSize() < size_b4_check_book) {
                                write_file << p1.getName() << " books the " << card_dealt.rankString(card_dealt.getRank())
                                           << "...\n";
                            }

                            // end player turn
                            card_in_hand = false;
                            p1.rotateHand(); // move denied card to end of hand
                            turn = 2; // player 2 turn
                        }

                            // Deck Empty, game ends.
                        else{
                            continue_game = false;
                            card_in_hand = false;
                        }
                    }
                }

                    // Still player's turn, but empty hand, so draw a card from deck before
                    // requesting a card from opponent.
                else{

                    if (d.size() > 0) {
                        card_dealt = d.dealCard();
                        p1.addCard(card_dealt);
                        write_file << p1.getName() << " draws " << card_dealt << endl;
                        turn = 2;
                    }

                        // empty deck, game ends
                    else {
                        continue_game = false;
                        card_in_hand = false;
                    }
                }
            }
        }










            // Player 2 turn.
        else{
            card_in_hand = true;

            // continue while still player turn
            while (card_in_hand) {

                // show player hands
                write_file << endl << p1.getName() << " hand: " << p1.showHand() << endl;
                write_file << p2.getName() << " hand: " << p2.showHand() << endl;


                // player's turn and hand not empty
                if (p2.getHandSize() > 0) {

                    // ask opponent for card
                    card_played = p2.chooseCardFromHand();
                    card_played_rank = card_played.rankString(card_played.getRank());
                    write_file << p2.getName() << " asks - Do you have a "
                               << card_played_rank << "? \n";


                    // opponent checks hand for requested card
                    write_file << p1.getName() << " says - ";



                    // if requested card in opponents hand:
                    // given to player, booked, and removed from
                    // opponents hand.
                    if (p1.cardInHand(card_played)) {

                        write_file << "Yes. I have a " << card_played_rank << ".\n";
                        write_file << p2.getName() << " books the " << card_played_rank << "... \n";
                        p2.bookCards(card_played, p1.removeCardFromHand(card_played));
                        p2.removeCardFromHand(card_played);
                        card_in_hand = true;
                    }


                    else {

                        // if requested card NOT in opponents hand:
                        // GoFish, places card in hand and checks if there's
                        // a pair. This ENDS player turn. The denied hand is
                        // moved to end of player hand.
                        if (d.size() > 0) { // deck not empty

                            card_dealt = d.dealCard();
                            write_file << "Go Fish\n" << p2.getName() << " draws " << card_dealt << endl;
                            p2.addCard(card_dealt);

                            size_b4_check_book = p2.getHandSize();
                            p2.checkHandForBook();

                            // if found pair with NEW card, print booked card to console
                            if (p2.getHandSize() < size_b4_check_book) {
                                write_file << p2.getName() << " books the " << card_dealt.rankString(card_dealt.getRank())
                                           << "...\n";
                            }

                            // end player turn
                            card_in_hand = false;
                            p2.rotateHand(); // move denied card to end of hand
                            turn = 1; // player 1 turn
                        }

                            // Deck Empty, game ends.
                        else {
                            continue_game = false;
                            card_in_hand = false;
                        }
                    }
                }


                    // Still player's turn, but empty hand, so draw a card from deck before
                    // requesting a card from opponent.
                else{
                    if (d.size() > 0) {
                        card_dealt = d.dealCard();
                        p2.addCard(card_dealt);
                        write_file << p2.getName() << " draws " << card_dealt << endl;
                        turn = 1;
                    }

                        // empty deck, game ends
                    else {
                        continue_game = false;
                        card_in_hand = false;
                    }
                }
            }
        }
    }


    // check who wins by comparing # of books
    if (p1.getBookSize() > p2.getBookSize()){
        return(1); // player 1 wins
    }
    else if (p1.getBookSize() < p2.getBookSize()){
        return(2); // player 2 wins
    }
    return(0); // tie
}


int main( )
{
    ofstream write_file("gofish_results.txt");

    int numCards = 7; // cards to deal for 2 players

    // create two players
    Player p1("Ana");
    Player p2("Kevin");

    // new, ordered deck
    Deck d;

    // shuffle deck
    d.shuffle();

    // deal 7 cards to each player
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    // show player hands
    write_file << p1.getName() <<" has : " << p1.showHand() << endl;
    write_file << p2.getName() <<" has : " << p2.showHand() << endl;


    // play game and return winner
    int winner = playGame(p1, p2, d, write_file);

    // print winner to console with winner & loser books.
    // print if there's a tie too.
    if (winner == 1){
        write_file << endl << p1.getName() << " wins!!! \nWinner Book:\n" << p1.showBooks() << endl;
        write_file << "Loser Book: \n" << p2.showBooks() << endl;
    }
    else if (winner == 2){
        write_file << p2.getName() << " wins!!! \nWinner Book:\n" << p2.showBooks() << endl;
        write_file << "Loser Book: \n" << p1.showBooks() << endl;
    }
    else{
        write_file << "It's a tie! :o \n" << p1.getName() << " Final Book :\n" << p1.showBooks() << endl;
        write_file << p2.getName() << " Final Book :\n" << p2.showBooks() << endl;
    }
    return EXIT_SUCCESS;
}






