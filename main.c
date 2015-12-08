#include "card.h"
#define NUM_CARDS 5
//#define QUICK_DEBUG

int main()
{
    int choice = 1; // 플레이어의 선택
    int idx;
    int i;
    int curIdx = 0; // 현재 카드 위치
    int whoWins = 0;

    // PLAYER 초기화
    PLAYER player, computer;
    player.numOfWins = 0; player.numOfLoss = 0; player.numOfDraw = 0;
    computer.numOfWins = 0; computer.numOfLoss = 0; computer.numOfDraw = 0;

    printf("Welcome to simple poker game...\n\n");
    CARD* cards = create_deck(); // 카드 덱 선언

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

            // 카드를 번갈아가면서 한장씩 분배
            for (idx = 0 ; idx < NUM_CARDS ;  idx++) {
                player.userCards[idx] =  get_card(cards,curIdx*2);
                computer.userCards[idx] =  get_card(cards,curIdx*2+1);
                printf("Your card %d is ",idx); info(player.userCards[idx]);
                curIdx++;
            }

            if(curIdx >=25) { // 어느 정도 카드를 사용하면 카드를 다시 섞음
                cards= create_deck();
                printf("Creating deck is success...\n\n");
                shuffle_card(cards);
                printf("Shuffling cards is success...\n\n");

                curIdx = 0;
                break;
            }

            // 승패 판정
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
        case SHUFFLE: // 카드를 다시 섞음
            curIdx = 0;
            cards = create_deck();
            shuffle_card(cards);
            break;
        case QUIT: // 게임 종료시 결과 출력
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

