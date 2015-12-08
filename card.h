#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

enum ERROR {EMPTY = -2, USED = -1}; // ī�尡 �������� ������ enum ���
enum RESULT {WINP1 = 1, WINP2 = 2, DRAW = 0}; // ���� ���� ���
enum CRITERIA {RANKS, SUITS}; // ���� ���� ����
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

char* get_suit(SUIT); // card ���� ���̸� ������ �Լ�
char* get_rank(RANK); // card ���� ���ڸ� ������ �Լ�
void info(CARD); // �ش� ī�� ���
CARD* create_deck(void); // ī�� �� ����
void shuffle_card(CARD cards[]); // ī�� ����
void print_deck(CARD cards[]);  // ī�� �� ���
void swap_card(CARD*,CARD*); // ������ �� ī�� ��ġ ����
CARD get_card(CARD* deck, int idx); // ī�带 �� �徿 ����

void card_quicksort(CARD* cards, int size, int criteria); // ī�带 ����Ʈ �ϴ� �Լ�
int decideWinner(CARD* p, CARD* c); // ���и� �����ϴ� �Լ�

#endif // CARD_H
