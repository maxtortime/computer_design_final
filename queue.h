\#ifndef QUEUE_H
#define QUEUE_H
#include "card.h"

void initQueue(void);
void enqueue(CARD* decks,CARD card);
CARD dequeue(CARD* decks);
int isEmpty(void);
int isFull(void);

#endif // QUEUE_H
