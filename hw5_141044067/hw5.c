#include <stdio.h>


int isKnightMovable(char *board, char sourceCol,
                     int sourceRow, char targetCol, int targetRow);
void getPosition(char *col, int *row);
int isValidCell(char col, int row);
int isPieceMovable(char *board);
int isKnightMovable(char *board, char sourceCol,
                    int sourceRow, char targetCol, int targetRow);
int isRookMovable(char *board , char sourceCol,
                     int sourceRow, char targetCol, int targetRow);
int isPawnMovable(char *board , char sourceCol,
                     int sourceRow, char targetCol, int targetRow);
int isBishopMovable(char *board , char sourceCol,
                    int sourceRow, char targetCol, int targetRow);
int isQueenMovable(char *board , char sourceCol,
                   int sourceRow, char targetCol, int targetRow);
                                                                           
void printBoard(char *board);
int initBoard(char *board);

int isValidCell(char col, int row)
{
    char ch[]={'a','b','c','d','e','f','g','h'};
    int num[]={1,2,3,4,5,6,7,8};
    int i,j;
    
    scanf("%c",&col);
    scanf("%d",&row);
    for(i=0;i<8;i++)
    {
        if(ch[i]==col)
        {
            return 1;
        }
    }
    if(ch[i]!=col)
        return 0;
        
    
    for(j=0;j<8;j++)
    {
        if(num[j]==num)
        {
            return 1;
        }
    }
    if(num[j]!=row)
        return 0;
        
}
            
}
    



void emptyBuffer()
{
	while ( getchar() != '\n' );
}
void printBoard(char *board)
{
    int i,j,k,m; /* for dongusu icin sayaclar */
    
    char chessBoard[64]={'r','n','b','q','k','b','n','r',
                    'p','p','p','p','p','p','p','p',
                    ' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',
                    'P','P','P','P','P','P','P','P',
                    'R','N','B','Q','K','B','N','R'};
                    
                    
       printf("  a b c d e f g h\n");
	          printf("  - - - - - - - -\n");
	          
	          printf("8|");
	          for(i=0;i<7;i++)
	          {
	                printf("%c ",chessBoard[i]);	                
              }
              printf("%c|\n",chessBoard[7]);
              
              printf("7|");
              for(i=8;i<15;i++)
	          {
	                printf("%c ",chessBoard[i]);	                
              }
              printf("%c|\n",chessBoard[15]);
              
              printf("6|");
              for(i=16;i<23;i++)
	          {
	                printf("%c ",chessBoard[i]);	                
              }
              printf("%c|\n",chessBoard[23]);
              
              printf("5|");
              for(i=24;i<31;i++)
	          {
	                printf("%c ",chessBoard[i]);	                
              }
              printf("%c|\n",chessBoard[31]);
              
              printf("4|");
              for(i=32;i<39;i++)
	          {
	                printf("%c ",chessBoard[i]);	                
              }
              printf("%c|\n",chessBoard[39]);
              
              printf("3|");
              for(i=40;i<47;i++)
	          {
	                printf("%c ",chessBoard[i]);	                
              }
              printf("%c|\n",chessBoard[47]);
              
              printf("2|");
              for(i=48;i<55;i++)
	          {
	                printf("%c ",chessBoard[i]);	                
              }
              printf("%c|\n",chessBoard[55]);
              
              printf("1|");
              for(i=56;i<63;i++)
	          {
	                printf("%c ",chessBoard[i]);	                
              }
              printf("%c|\n",chessBoard[63]);
              	          
              printf("  - - - - - - - -\n");
}
                    

void main()
{
	char board [64];
	int initComplete = 0;
	char empty;
	
	
	         
	         
	         
	         
	         
	         
	         
	         

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
}
