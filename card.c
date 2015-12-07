#include "card.h"

char* get_suit(SUIT suit) {
    char* clubs = "♣";
    char* diamonds = "◆";
    char* hearts = "♥";
    char* spades = "♠";

    switch (suit) {
    case CLUBS:
        return clubs;
    case DIAMONDS:
        return diamonds;
    case HEARTS:
        return hearts;
    case SPADES:
        return spades;
    case EMPTY:
        return "EMPTY";
    case USED:
        return "USED";
    default:
        return "E"; // means error
    }
}

char* get_rank(RANK rank) {
    switch (rank) {
    case ACE:
        return "A";
    case JACK:
        return "J";
    case QUEEN:
        return "Q";
    case KING:
        return "K";
    case TWO:
        return "2";
    case THREE:
        return "3";
    case FOUR:
        return "4";
    case FIVE:
        return "5";
    case SIX:
        return "6";
    case SEVEN:
        return "7";
    case EIGHT:
        return "8";
    case NINE:
        return "9";
    case TEN:
        return "10";
    case EMPTY:
        return "EMPTY";
    case USED:
        return "USED";
    default:
        return "E"; // means error
    }
}

void info(CARD card) {
    printf("%s%s\n",get_suit(card.suit),get_rank(card.rank)); // 카드 무늬를 문자열로 받아서 그대로 출력
}

CARD* create_deck(void) {
    int suit = 0;
    int i;
    CARD *decks = (CARD *) malloc(sizeof(CARD) * DECK_SIZE); // 카드 갯수만큼 덱 생성

    for (i = 0 ; i < DECK_SIZE ; i++) {
        decks[i].rank = i % 13 + 1;
        decks[i].suit = suit;

        if ((i+1) % 13 == 0) suit++; // 13번 째 카드마다 무늬를 바꿔줌
    }

    return decks;
}

void print_deck(CARD cards[]) {
    int i;

    for (i = 0; i< DECK_SIZE ;  i++) {
        printf("No.%d) ",i+1);
        info(cards[i]);
    }
}

void shuffle_card(CARD cards[]) {
    srand(time(0));
    int i;
    int a,b;

    for(i = 0; i < DECK_SIZE; i++){
        a = rand() % DECK_SIZE;
        b = rand() % DECK_SIZE;

        swap_card(&cards[a], &cards[b]);
    }
}

void swap_card(CARD *a, CARD *b) {
    CARD tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

CARD get_card(CARD* decks, int idx) {
    if (idx < DECK_SIZE) {
        CARD result = decks[idx];

        // if rand or suit is -1. That card is used.
        decks[idx].rank = -1;
        decks[idx].suit = -1;

        return result;
    }
    else {
        CARD noCard = {-2,-2}; // means deck is empty
        return noCard;
    }
}

int decideWinner(CARD* p, CARD* c)
{
    int i;
    int player = 0, computer = 0; // 각 플레이어 족보값
    int ifPlushP = 1, ifPlushC = 1;  // 플러시인지 판정하기 위한
    int ifStraightP = 1, ifStraightC = 1; //  스트레이트인지 판정하기 위한

    // 무늬 별로 정렬
    card_quicksort(p,5,SUITS);
    card_quicksort(c,5,SUITS);

    // 플러시 판정
    for (i = 1 ; i < 5; i++) {
        // 플레이어 플러시 판정
        if(p[0].suit != p[i].suit) ifPlushP = 0;
        // 컴퓨터 플러시 판정
        if(c[0].suit != c[i].suit) ifPlushC = 0;
    }

    card_quicksort(p,5,RANKS);
    card_quicksort(c,5,RANKS);

    for (i = 1 ; i < 5; i++) {
        // 플레이어 스트레이트 판정
        if(p[0].rank+i != p[i].rank) ifStraightP = 0;
        // 컴퓨터 스트레이트 판정
        if(c[0].rank+i != c[i].rank) ifStraightC = 0;
    }

    if (ifPlushP && ifStraightP)
        player = STRAIGHTFLUSH;
    else if ((p[0].rank == p[1].rank == p[2].rank == p[3].rank)
        || (p[1].rank == p[2].rank == p[3].rank == p[4].rank))
        player = FOURCARD;
    else if(((p[0].rank == p[1].rank == p[2].rank) && (p[3].rank == p[4].rank)) ||
        ((p[2].rank == p[3].rank == p[4].rank) && (p[0].rank == p[1].rank)))
        player = FULLHOUSE;
    else if (ifPlushP)
        player = FLUSH;
    else if (ifStraightP)
        player = STRAIGHT;
    else if (!ifPlushP && !ifStraightP && (p[0].rank == p[1].rank == p[2].rank) || (p[1].rank == p[2].rank == p[3].rank)
    || (p[2].rank == p[3].rank == p[4].rank))
        player = TRIPLE;
    else if (!ifPlushP && !ifStraightP && (p[0].rank==p[1].rank && p[2].rank==p[3].rank) || (p[1].rank==p[2].rank && p[3].rank==p[4].rank) ||
             (p[0].rank==p[1].rank && p[3].rank==p[4].rank))
        player = TWOPAIR;
    else if (!ifPlushP && !ifStraightP && ((p[0].rank==p[1].rank) || (p[1].rank==p[2].rank) || (p[2].rank==p[3].rank) || (p[3].rank==p[4].rank)))
        player = ONEPAIR;
    else
        player = NOT;


    if (ifPlushC && ifStraightC)
        computer = STRAIGHTFLUSH;
    else if ((c[0].rank == c[1].rank == c[2].rank == c[3].rank)
        || (c[1].rank == c[2].rank == c[3].rank == c[4].rank))
        computer = FOURCARD;
    else if(((c[0].rank == c[1].rank == c[2].rank) && (c[3].rank == c[4].rank)) ||
        ((c[2].rank == c[3].rank == c[4].rank) && (c[0].rank == c[1].rank)))
        computer = FULLHOUSE;
    else if (ifPlushC)
        computer = FLUSH;
    else if (ifStraightC)
        computer = STRAIGHT;
    else if (!ifPlushC && !ifStraightC && (c[0].rank == c[1].rank == c[2].rank) || (c[1].rank == c[2].rank == c[3].rank)
    || (c[2].rank == c[3].rank == c[4].rank))
        computer = TRIPLE;
    else if (!ifPlushC && !ifStraightC && (c[0].rank==c[1].rank && c[2].rank==c[3].rank) || (c[1].rank==c[2].rank && c[3].rank==c[4].rank) ||
             (c[0].rank==c[1].rank && c[3].rank==c[4].rank))
        computer = TWOPAIR;
    else if (!ifPlushP && !ifStraightP && ((c[0].rank==c[1].rank) || (c[1].rank==c[2].rank) || (c[2].rank==c[3].rank) || (c[3].rank==c[4].rank)))
        computer = ONEPAIR;
    else
        computer = NOT;


    if (player > computer) {
        printf("Player Win! %d %d\n",player, computer);
        return 1;
    }
    else if (player == computer) {
        printf("Draw! %d %d\n",player, computer);
        return 0;
    }
    else {
        printf("Computer Win %d %d\n",player, computer);
        return -1;
    }
}

void card_quicksort(CARD* cards, int size, int criteria)
{
    int i, j;
    CARD p, t;

    if (size < 2)
        return;

    p = cards[size/ 2];

    for (i = 0, j = size - 1;; i++, j--) {

        if (criteria == SUITS) {
            while (cards[i].suit < p.suit) i++;
            while (p.suit < cards[j].suit) j--;
        }
        else {
            while (cards[i].rank < p.rank) i++;
            while (p.rank < cards[j].rank) j--;
        }

        if (i >= j)
            break;

        t = cards[i];

        cards[i] = cards[j];
        cards[j] = t;
    }
    card_quicksort(cards, i, criteria);
    card_quicksort(cards + i, size - i,criteria);
}

