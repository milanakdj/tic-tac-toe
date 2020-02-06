//
//#include "stdio.h"
//#include "stdlib.h"
//#include "string.h"
//
///*
//int board[25] = {
//	:,:,:,:,:,
//	:,O,-,X,:,
//	:,X,-,-,:,
//	:,-,-,-,:,
//	:,:,:,:,:,
//}
//*/
//
//enum { NOUGHTS, CROSSES, BORDER, EMPTY };
//enum { HUMANWIN, COMPWIN, DRAW };
//
//const int ConvertTo25[9] = {
//	6, 7, 8,
//	11,12,13,
//	16,17,18
//};
//
//void InitialiseBoard(int *board) {
//	int index = 0;
//	
//	for(index = 0; index < 25; ++index) {
//		board[index] = BORDER;
//	}
//	
//	for(index = 0; index < 9; ++index) {
//		board[ConvertTo25[index]] = EMPTY;
//	}	
//}
//
//void PrintBoard(const int *board) {
//	int index = 0;
//	char pceChars[] = "OX|-";
//	printf("\n\nBoard:\n\n");
//	for(index = 0; index < 9; ++index) {
//		if(index!=0 && index%3==0) {
//			printf("\n\n");
//		}
//		printf("%4c",pceChars[board[ConvertTo25[index]]]);
//	}
//	printf("\n");
//}
//
//int HasEmpty(const int *board) {
//	int index = 0;
//	
//	for(index = 0; index < 9; ++index) {
//		if( board[ConvertTo25[index]] == EMPTY) return 1;
//	}
//	return 0;
//}
//
//void MakeMove(int *board, const int sq, const side) {
//	board[sq] = side;
//}
//
//int GetHumanMove(const int *board) {
//	
//	char userInput[4];
//	
//	int moveOk = 0;
//	int move = -1;
//	
//	while (moveOk == 0) {
//	
//		printf("Please enter a move from 1 to 9:");		
//		fgets(userInput, 3, stdin);
//		fflush(stdin);
//		
//		if(strlen(userInput) != 2) {
//			printf("Invalid strlen()\n");
//			continue;			
//		}
//		
//		if( sscanf(userInput, "%d", &move) != 1) {
//			move = -1;
//			printf("Invalid sscanf()\n");
//			continue;
//		}
//		
//		if( move < 1 || move > 9) {
//			move = -1;
//			printf("Invalid range\n");
//			continue;
//		}
//		
//		move--; // Zero indexing
//		
//		if( board[ConvertTo25[move]]!=EMPTY) {
//			move=-1;
//			printf("Square not available\n");
//			continue;
//		}
//		moveOk = 1;
//	}
//	printf("Making Move...%d\n",(move+1));
//	return ConvertTo25[move];
//}
//
//void RunGame() {
//
//	int GameOver = 0;
//	int Side = NOUGHTS;
//	int LastMoveMade = 0;
//	int board[25];
//	
//	InitialiseBoard(&board[0]);
//	PrintBoard(&board[0]);
//	
//	while(!GameOver) {
//		if(Side==NOUGHTS) {	
//			GetHumanMove(&board[0]);
//			// get move from human, make move on board, change side
//		} else {
//			// get move from computer, make move on board, change side
//			PrintBoard(&board[0]);
//		}
//		
//		// if three in a row exists Game is over
//
//		// if no more moves, game is a draw	
//		
//		
////		GameOver = 1; // REMOVE ME !!
//	}
//}
//
//int main() {		
//	
//	srand(time(NULL));
//	RunGame();
//		
//	return 0;
//}
//
//
//

#include <stdio.h>
#include <conio.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();

int main()
{
    int player = 1, i, choice;

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);
    
    board();
    
    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    getch();

    return 0;
}

/*********************************************

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

