#include "card.h"
#define NUM_CARDS 5
//#define QUICK_DEBUG

int main()
{
    int choice = 1; // �÷��̾��� ����
    int idx;
    int i;
    int curIdx = 0; // ���� ī�� ��ġ
    int whoWins = 0;

    // PLAYER �ʱ�ȭ
    PLAYER player, computer;
    player.numOfWins = 0; player.numOfLoss = 0; player.numOfDraw = 0;
    computer.numOfWins = 0; computer.numOfLoss = 0; computer.numOfDraw = 0;

    printf("Welcome to simple poker game...\n\n");
    CARD* cards = create_deck(); // ī�� �� ����

    printf("Creating deck is success...\n\n");
    shuffle_card(cards);

    #ifdef QUICK_DEBUG
        print_deck(cards);
        card_quicksort(cards,DECK_SIZE,SUITS);
        print_deck(cards);
    #endif // QUICK_DEBUG

    printf("Shuffling cards is success...\n\n");

    while(1) {
        printf("What want to do?\n 1) Keep playing 2) Shuffle deck 3) Quit ");
        scanf("%d",&choice);
        fflush(stdin);

        switch (choice) {
        case PLAYING:
            printf("\nNow Playing...\n\n");

            // ī�带 �����ư��鼭 ���徿 �й�
            for (idx = 0 ; idx < NUM_CARDS ;  idx++) {
                player.userCards[idx] =  get_card(cards,curIdx*2);
                computer.userCards[idx] =  get_card(cards,curIdx*2+1);
                printf("Your card %d is ",idx); info(player.userCards[idx]);
                curIdx++;
            }

            if(curIdx >=25) { // ��� ���� ī�带 ����ϸ� ī�带 �ٽ� ����
                cards= create_deck();
                printf("Creating deck is success...\n\n");
                shuffle_card(cards);
                printf("Shuffling cards is success...\n\n");

                curIdx = 0;
                break;
            }

            // ���� ����
            whoWins = decideWinner(player.userCards,computer.userCards);
            if(whoWins == WINP1) {
                player.numOfWins++;
                computer.numOfLoss++;
            }
            else if(whoWins == DRAW) {
                player.numOfDraw++;
                computer.numOfDraw++;
            }
            else if(whoWins == WINP2) {
                player.numOfLoss++;
                computer.numOfWins++;
            }

            break;
        case SHUFFLE: // ī�带 �ٽ� ����
            curIdx = 0;
            cards = create_deck();
            shuffle_card(cards);
            break;
        case QUIT: // ���� ����� ��� ���
            printf("Game quits..\n");
            printf("Player Wins: %d, Player Draws: %d, Player Loss: %d\n",player.numOfWins,player.numOfDraw,player.numOfLoss);
            printf("Computer Wins: %d, Computer Draws: %d, Computer Loss: %d\n",computer.numOfWins,computer.numOfDraw,computer.numOfLoss);
            exit(1);
            break;
        default:
            printf("You input wrong number...\n");
            fflush(stdin);
            break;
        }
    }

    return 0;
}

