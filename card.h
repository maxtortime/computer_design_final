#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

enum ERROR {EMPTY = -2, USED = -1}; // 카드가 쓰였는지 여부의 enum 상수
enum RESULT {WINP1 = 1, WINP2 = 2, DRAW = 0}; // 승패 결정 상수
enum CRITERIA {RANKS, SUITS}; // 정렬 조건 설정
enum JOKBO {NOT, ONEPAIR, TWOPAIR, TRIPLE, STRAIGHT, FLUSH, FULLHOUSE, FOURCARD, STRAIGHTFLUSH};

typedef enum { CLUBS, DIAMONDS, HEARTS, SPADES} SUIT;
typedef enum { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} RANK;
enum {PLAYING = 1, SHUFFLE, QUIT};

typedef struct {
    SUIT suit;
    RANK rank;
} CARD;

typedef struct {
    int numOfWins;
    int numOfLoss;
    int numOfDraw ;
    CARD userCards[5];
}PLAYER;

char* get_suit(SUIT); // card 에서 무늬를 얻어오는 함수
char* get_rank(RANK); // card 에서 숫자를 얻어오는 함수
void info(CARD); // 해당 카드 출력
CARD* create_deck(void); // 카드 덱 생성
void shuffle_card(CARD cards[]); // 카드 섞기
void print_deck(CARD cards[]);  // 카드 덱 출력
void swap_card(CARD*,CARD*); // 셔플할 때 카드 위치 변경
CARD get_card(CARD* deck, int idx); // 카드를 한 장씩 빼줌

void card_quicksort(CARD* cards, int size, int criteria); // 카드를 퀵소트 하는 함수
int decideWinner(CARD* p, CARD* c); // 승패를 결정하는 함수

#endif // CARD_H
