/*
 Author:    Joseph Herkness
 Date:      2014-12-1
 Objective: Modify the program in Fig. 7.24 so that the card-dealing function deals a five-card poker hand. Then write the following additional functions:
            a) Determine whether the hand contains a pair.
            b) Determine whether the hand contains two pairs.
            c) Determine whether the hand contains three of a kind (e.g., three jacks).
            d) Determine whether the hand contains four of a kind (e.g., four aces).
            e) Determine whether the hand contains a flush (i.e., all five cards of the same suit).
            f) Determine whether the hand contains a straight (i.e., five cards of consecutive face values).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define PLAYERS 3

// prototypes
void shuffle( unsigned int wDeck[][ FACES ] );
void deal(int hands[][5], unsigned int wDeck[][ FACES ], const char *wFace[], const char *wSuit[] );
int onePair(int hand[], const char *wFace[]);
int twoPair(int hand[], const char *wFace[]);
int threeOfAKind(int hand[], const char *wFace[]);
int fourOfAKind(int hand[], const char *wFace[]);
int flush(int hand[], const char *wSuit[]);
int straight(int hand[], const char *wface[]);

int main( void ){
    const char *suit[ SUITS ] = { "Hearts", "Diamonds", "Clubs", "Spades" }; // initialize suit array
    
    const char *face[ FACES ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };// initialize face array

    unsigned int deck[ SUITS ][ FACES ] = {0}; // initialize deck array
    
    srand((unsigned int)time(NULL)); // seed random-number generator
    
    shuffle(deck); // shuffle the deck
    
    int hands[PLAYERS][5]; // initialize and array of hands
    
    deal(hands, deck, face, suit); // deal hands
    
    return 0;
}

// shuffle cards in deck
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

// deal cards in deck
void deal(int hands[][5], unsigned int wDeck[][FACES], const char *wFace[],const char *wSuit[]){
    size_t card; // card counter
    size_t row; // row counter
    size_t column; // column counter
    
    for(int player = 0; player < PLAYERS; player++){
        printf("Player %d: \n\n", player + 1);
        // deal each of the cards
        for ( card = 0; card < 5; card++ ) {
            // loop through rows of wDeck
            for ( row = 0; row < SUITS; ++row ) {
                // loop through columns of wDeck for current row
                for ( column = 0; column < FACES; column++ ) {
                    // if slot contains current card, display card
                    if ( wDeck[ row ][ column ] == card + 1 + (player * 5)) {
                        printf( "%5s of %-8s\n", wFace[column], wSuit[row]);
                        hands[player][card] = (int)((column) + (row * FACES));
                    }
                }
            }
        }
        
        printf("\n"); //Spacer
        if(straight(hands[player], wFace) == 1){
            printf("[You have a striaght]\n");
        }else if(flush(hands[player], wSuit) == 1){
            printf("[You have flush]\n");
        }else if(fourOfAKind(hands[player], wFace) == 1){
            printf("[You have four of a kind]\n");
        }else if(threeOfAKind(hands[player], wFace) == 1){
            printf("[You have three of a kind]\n");
        }else if(twoPair(hands[player], wFace) == 1){
            printf("[You have two pairs]\n");
        }else if(onePair(hands[player], wFace) == 1){
            printf("[You have a pair]\n");
        }else{
            printf("[You have nothing]\n");
        }
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
