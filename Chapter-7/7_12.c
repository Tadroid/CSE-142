/*
 Author:    Joseph Herkness
 Date:      2014-12-6
 Objective: Use the functions developed in Exercise 7.12 to write a program that deals two five-card poker hands, evaluates each, and determines which is the better hand.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle( unsigned int wDeck[][ FACES ] );
void deal(int hand[], unsigned int wDeck[][ FACES ], const char *wFace[], const char *wSuit[] );
int onePair(int hand[], const char *wFace[]);
int twoPair(int hand[], const char *wFace[]);
int threeOfAKind(int hand[], const char *wFace[]);
int fourOfAKind(int hand[], const char *wFace[]);
int flush(int hand[], const char *wSuit[]);
int straight(int hand[], const char *wFace[]);

int main( void ){
    const char *suit[ SUITS ] = { "Hearts", "Diamonds", "Clubs", "Spades" }; // initialize suit array
    
    const char *face[ FACES ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };// initialize face array
    
    unsigned int deck[ SUITS ][ FACES ] = {0}; // initialize deck array
    
    srand((unsigned int)time(NULL)); // seed random-number generator
    
    shuffle(deck); // shuffle the deck
    
    int hand[5]; // initialize and array of hands
    
    deal(hand, deck, face, suit); // deal hand
    
    return 0;
}

/**
 *  Takes a deck and filles it with randomized cards
 *
 *  @param wDeck array (with each element initialized to 0)
 */
void shuffle( unsigned int wDeck[][FACES]){
    size_t row; // row number
    size_t column; // column number
    size_t card; // counter
    
    // for each of the cards, choose slot of deck randomly
    for (card = 1; card <= CARDS; card++) {
        
        // choose new random location until unoccupied slot found
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while( wDeck[ row ][ column ] != 0 );
        
        // place card number in chosen slot of deck
        wDeck[row][column] = (int)card;
    }
}

/**
 *  Takes a array array of cards and distributes them among each player
 *
 *  @param hands array of hands to be filled
 *  @param wDeck array of cards
 *  @param wFace character array representing face names
 *  @param wSuit character array representing suit names
 */
void deal(int hand[5], unsigned int wDeck[][FACES], const char *wFace[],const char *wSuit[]){
    size_t card; // card counter
    size_t row; // row counter
    size_t column; // column counter
    
    // deal each of the cards
    for ( card = 0; card < 5; card++ ) {
        // loop through rows of wDeck
        for ( row = 0; row < SUITS; ++row ) {
            // loop through columns of wDeck for current row
            for ( column = 0; column < FACES; column++ ) {
                // if slot contains current card, display card
                if ( wDeck[ row ][ column ] == card + 1) {
                    printf( "%5s of %-8s\n", wFace[column], wSuit[row]);
                    hand[card] = (int)((column) + (row * FACES));
                }
            }
        }
    }
        
    printf("\n"); //Spacer
    if(straight(hand, wFace) == 1){
        printf("> [You have a striaght]\n\n");
    }else if(flush(hand, wSuit) == 1){
        printf("> [You have flush]\n\n");
    }else if(fourOfAKind(hand, wFace) == 1){
        printf("> [You have four of a kind]\n\n");
    }else if(threeOfAKind(hand, wFace) == 1){
        printf("> [You have three of a kind]\n\n");
    }else if(twoPair(hand, wFace) == 1){
        printf("> [You have two pairs]\n\n");
    }else if(onePair(hand, wFace) == 1){
        printf("> [You have a pair]\n\n");
    }else{
        printf("> [You have nothing]\n\n");
    }
}

int onePair(int hand[], const char *wFace[]){
    int count[FACES] = {0};
    int card;
    int hold;
    
    for(card = 0; card < 5; card++) {
        hold = hand[card] % FACES;
        count[hold] += 1;
    }
    for(card = 0; card < FACES; card++) {
        if(count[card] == 2){
            return 1;
        }
    }
    return 0;
}

int twoPair(int hand[], const char *wFace[]){
    int count[FACES] = {0};
    int card;
    int hold;
    int counter = 0;
    
    for(card = 0; card < 5; card++) {
        hold = hand[card] % FACES;
        count[hold] += 1;
    }
    for(card = 1; card <= FACES; card++) {
        if(count[card] == 2){
            counter ++;
        }
        if(counter == 2){
            return 1;
        }
    }
    return 0;
}

int threeOfAKind(int hand[], const char *wFace[]){
    int count[FACES] = {0};
    int card;
    int hold;
    
    for(card = 0; card < 5; card++) {
        hold = hand[card] % FACES;
        count[hold] += 1;
    }
    for(card = 0; card < FACES; card++) {
        if(count[card] == 3){
            return 1;
        }
    }
    return 0;
}

int fourOfAKind(int hand[], const char *wFace[]){
    int count[FACES] = {0};
    int card;
    int hold;
    
    for(card = 0; card < 5; card++) {
        hold = hand[card] % FACES;
        count[hold] += 1;
    }
    for(card = 0; card < FACES; card++) {
        if(count[card] == 4){
            return 1;
        }
    }
    return 0;
}

int flush(int hand[], const char *wSuit[]){
    int count[SUITS] = {0};
    int card;
    int hold;
    
    for(card = 0; card < 5; card++) {
        hold = hand[card] / FACES;
        count[hold] += 1;
    }
    for(card = 0; card < SUITS; card++) {
        if(count[card] == 5){
            return 1;
        }
    }
    return 0;
}

int straight(int hand[], const char *wFace[]){
    int count[FACES] = {0};
    int card;
    int hold;
    
    for(card = 0; card < 5; card++) {
        hold = hand[card] % FACES;
        count[hold] += 1;
    }
    
    int counter = 0;
    for(card = 0; card < FACES; card++){
        (count[card] != 0) ? (counter ++) : (counter = 0);
        if(counter == 5){
            return 1;
        }
    }
    return 0;
}
