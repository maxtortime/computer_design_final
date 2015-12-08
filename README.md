# Computer Program Design 2015 Fall
## Final Assignment - Simple Poker game

### 201122037 김태환

### Program source list
> 소스 코드 별 자세한 기능은 아래에 설명되어 있습니다.
* main.c // main 함수가 있어서 실제로 컴퓨터와 포커를 하는 기능이 구현되어 있음
* card.c // 포커를 하기 위해 사용되는 다양한 function이 구현되어 있음
* card.h // 카드 족보나 패를 정의하는 enum 상수, player, card 구조체, 함수 정의
* README.md // 보고서
* Makefile // 프로그램 빌드를 위한 Makefile

### 실행 방법
#### 프로그램 빌드
1. Codeblocks -> Press F9 or Build->Build and run click
2. bash shell (UNIX, Mac, Linux)
```sh
tkim@tkim-laptop:~/computer_design_final$ make
gcc -c main.c
gcc -o main main.o card.o
tkim@tkim-laptop:~/computer_design_final$ ./main
3. Windows terminal
프로젝트 폴더로 찾아가면 Debug\ 디렉토리에 실행 파일이 존재함.
```

#### 프로그램 동작
