#include<stdio.h>
#include<conio.h>


char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int win();
void ground();

int main()
{
	int player=1;
	int i=-1;
	char mark;
	int choice;
	do {
		ground();
		
		player= player%2?1:2;
		printf(" player %d enter which place you want to choose: ",player);
		scanf("%d",&choice);
		player%2?mark='X':mark='O';
		
		
		if (choice==1 && square[1]=='1')
			square[1]=mark;
		else if (choice==2 && square[2]=='2')
			square[2]=mark;
		else if (choice==3 && square[3]=='3')
			square[3]=mark;
		else if (choice==4 && square[4]=='4')
			square[4]=mark;
		else if (choice==5 && square[5]=='5')
			square[5]=mark;
		else if (choice==6 && square[6]=='6')
			square[6]=mark;
		else if (choice==7 && square[7]=='7')
			square[7]=mark;
		else if (choice==8 && square[8]=='8')
			square[8]=mark;
		else if (choice==9 && square[9]=='9')
			square[9]=mark;
		else 
			{
				printf("invalid input \n");
				getch();
				player--;
			}
			
		i=win();
		if (i==0)
		{
			printf("draw\n");
		}
		else if(i==1)
		{
			printf("player %d wins !!!",player);
			break;
		}
		player++;
	}while(i==-1);
	getch();
	return 0;
}

int win()
{
	// return 1 if win and -1 if nothing and 0 if draw for the variable 'i'
	
	if (square[1]==square[2] && square[1]==square[3])
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
		
	else if (square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' && square[5]!='5' && square[6]!='6' && square[7]!='7' && square[8]!='8'&& square[9]!='9')
		return 0;
		
	else 
		return -1;
}

void ground()
{
	printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    
	printf("   |   |   \n");
	printf(" %c | %c | %c \n",square[1],square[2],square[3]);
	printf("___|___|___\n");
	printf("   |   |   \n");
	printf(" %c | %c | %c \n",square[4],square[5],square[6]);
	printf("___|___|___\n");
	printf("   |   |   \n");
	printf(" %c | %c | %c \n",square[7],square[8],square[9]);
	
}
