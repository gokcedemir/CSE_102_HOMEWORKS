#include <stdio.h>
#include <stdlib.h>

/*fonksiyon prototipleri */
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
int isKingMovable(char *board, char sourceCol, int sourceRow, 
                  char targetCol, int targetRow);                   
void printBoard(char *board);

/* satrancin elemanlarini diziye atamaya saglayan fonksiyon */
void initBoard(char *board)
{
    int i=0;  
    char printBoard[]={'r','n','b','q','k','b','n','r',
                    ' ','p','p','p','p','p','p','p',
                    ' ','r','r',' ',' ',' ',' ',' ',
                    ' ','n',' ','b',' ',' ',' ',' ',
                    ' ',' ',' ','n',' ',' ',' ',' ',
                    ' ',' ','R',' ','q','r',' ','R',
                    'P','P','P',' ','P','P','P','P',
                    'R','N','B','Q','K','B','N','R'};
    
    /* dizinin elemanlarini tek tek basma */                             
    for( i=0; i < 64 ; ++i )
    {
        board[i] = printBoard[i];   
    }     
}                                                                         
void emptyBuffer()
{
	while ( getchar() != '\n' );
}

int main()
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
	return (0);
}


/* satranc tahtasini ekrana basmaya yarayan fonksiyon */
void printBoard(char *board)
{
    int i,j,k,m; /* for dongusu icin sayaclar */
    char temp[8][8];
                    
                    
     printf("  a b c d e f g h\n");
     printf("  - - - - - - - -\n");
     
	 k=0;
     for(i=0;i<8;i++)
     {
        for(j=0;j<8;j++)
        {
            temp[i][j]=board[k];           
            k++;
        }
     }
     k=0;
     for(i=8;i>0;i--)
     {
        printf("%d|",i);
        for(j=0;j<8;j++)
        {   
            if(j<7)
            {
                 printf("%c ",temp[k][j]);
            }
            else
                 printf("%c",temp[k][j]);           
        }
        ++k;
        printf("|\n");
     }
              
printf("  - - - - - - - -\n");

}

/*  sutun ve satir kontrolu yapan fonksiyon 
    fonsiyon integer deger return edecek, return edecegi deger sutun ve satir 
    sartına baglı olarak degisecek                                           */
int isValidCell(char col, int row)
{
    if(col=='a' && col=='b' && col=='c' && col=='d' && col=='e' 
            && col=='f' && col=='g' && col=='h' && row>0 && row<9)
    
        return 1;
     else
        return 0;
}   
/*  satir ve sutun girdiler alma  */       
void getPosition(char *col, int *row)
{
    scanf(" %c",col);
    scanf("%d",row);
}    
/*  kullanicidan aldigi sutun ve satir girdilerini kontrol eder ve o 
    koordinattaki tasin indeksini ve ilerleyecegini hedefindeki koordinatin 
    degerlerini integer bi degere cevirir, daha sonrasinda gelen karekter 
    degerine bagli olarak gerekli fonksiyonlari cagirir.
    return degeri: integer deger dondurur, bu deger fonsiyonlarin dondurdugu
    degere gore degisir.                                                  */    
int isPieceMovable(char *board)
{
    int index,i,result=0; /*board arrayindeki indeksleri bulma */
    char sourceCol, targetCol;
    int sourceRow,targetRow;
    char stone;
    
    /*kullanicidan bulundugu ve gidicegi yerin koordinatlarini alma */
    getPosition(&sourceCol,&sourceRow);
    
    getPosition(&targetCol,&targetRow);
    
    /* girilen komuta gore board arrayindeki indeksleri bulma */
    index=((int)sourceCol-97)+((8-sourceRow)*8);
   
    stone=board[index];
        /*indekse baglı olarak switch case yapisiyla fonksiyonlar cagirma */
        switch (stone)
        {
            case 'r': 
            case 'R':
                      result=isRookMovable(board,sourceCol,sourceRow,
                      targetCol,targetRow);  
                      break;
            case 'n':
            case 'N':
                        result=isKnightMovable(board,sourceCol,sourceRow, 
                        targetCol,targetRow);
                        break;
            case 'b':
            case 'B':
                        result=isBishopMovable(board,sourceCol,sourceRow, 
                        targetCol,targetRow);
                        break;
            case 'q':
            case 'Q':
                        result=isQueenMovable(board,sourceCol,sourceRow, 
                        targetCol,targetRow);
                        break;                       
            case 'k':
            case 'K':
                        result=isKingMovable(board,sourceCol,sourceRow, 
                        targetCol,targetRow);
                        
                        break;                        
            case 'p':
            case 'P':
                        result=isPawnMovable(board,sourceCol,sourceRow, 
                        targetCol,targetRow);
                        
                        break; 
            default:
                       
                        break;                       
            
         }
     
     return result; /*fonksiyonlarin dondurugu degeri gore */
} 
/* piyon: capraz kontrol ve bir adım sonraki adimina gerekli kosullar 
    dogrultusunda (rakip takimin tasi veya kendi tasini test etme )
    bir adım ilerisini kontrol etme. 
    return degeri : fonskiyon integer dondurur, bu integer targetteki hedefe
    ulasıp ulasamayacaginin kontrolu olarak belirtilebilir.             */                          
int isPawnMovable(char *board , char sourceCol,int sourceRow,
                  char targetCol, int targetRow)                  
{
    char stone;
    int i,targetIndex,index;
    int sart=0;  /* return degerini atama */
    /*girilen koordinatlara gore target ve source indeksi bulmada
                (ascii kod cevirme)                                 */
    targetIndex=((int)targetCol-97)+((8-targetRow)*8); 
    index=((int)sourceCol-97)+((8-sourceRow)*8);   
    stone=board[index];
    /*      eger tas beyaz ise(lowercase)                          */
    if(stone=='p')
    {   
        /*rakibin tasi varsa (siyah)                           */
        if(board[targetIndex]>='A' && board[targetIndex]<='Z')
        {   /*asagidaki ilk iki if koselerin kontorlunu saglayarak 
                        tahtanin disina cikmayi engeller */
            if(index%8==7) 
            {  
                sart=1;               
            }
            if(index%8==0)
            {
                sart=1;               
            }
            /*piyonun rakibi capraz yeme kosulu */
            if(board[index+9]!=' ' && index+9==targetIndex)
            {
                sart=1;               
            }
            if(board[index+7]!=' ' && index+7==targetIndex)
            {
                sart=1;               
            }
        }
        else 
            return sart;    
            
            
         /*onu bossa bi adim gitme kosulu */   
        if(board[index+8]==' ' && (index+8)==(targetIndex))
        { 
            sart=1;               
        }
        else 
            return sart;
      }
       /*      eger tas siyah ise(uppercase) yukaridaki 
                    kosullar siyah tas icinde gecerlidir                   */  
      if(stone=='P')
      {
    
        
            if(board[targetIndex]>='a' && board[targetIndex]<='z' 
                        && board[targetIndex]!=' ')
            {
                if(index%8==7)
                {  
                    sart=1;               
                }
                else if(index%8==0)
                {
                    sart=1;               
                }
                
                if(board[index-9]!=' ' || index-9==targetIndex)
                {
                    sart=1;               
                }
                if(board[index-7]!=' ' || index-7==targetIndex)
                {
                    sart=1;               
                }
             }  
          
      
        if(board[index-8]==' ' && index-8==targetIndex)
                sart=1;               
        else 
           return sart;
       }   
     sart=1;               
} 
/* at: l seklinde gidisi ve target indeksin bos veyahut dolu oldugunu kontrol
   etme.
   return degeri:fonskiyon integer deger dondurur, bu integer targetteki hedefe
    ulasıp ulasamayacaginin kontrolu olarak belirtilebilir.             */             
int isKnightMovable(char *board, char sourceCol,
                    int sourceRow, char targetCol, int targetRow)                    
{
    char stone;
    int i,targetIndex,index,sart=0;
 /*sutun ve satir konumuna gore target ve source colun indekisinin bulunmasi */ 
    targetIndex=((int)targetCol-97)+((8-targetRow)*8); 
    index=((int)sourceCol-97)+((8-sourceRow)*8);   
    stone=board[index];
    /*beyaz tas(lowercase) icin hareket kontrolu */
    if(stone=='n')
    { /* targetteki indekste rakibin tasi varsa 15 veya 17 adim gitme kosulu*/   
         if(board[targetIndex]>='A' && board[targetIndex]<='Z' 
                        && board[targetIndex]!=' ')
         {
            if(index%8==7)
            {  
                sart=1;               
            }
            else if(index%8==0)
            {
                sart=1;               
            }
             
            if(board[index+15]!=' ' && index+15==targetIndex)
            {
                sart=1;               
            }
            if(board[index+17]!=' ' && index+17==targetIndex)
            {
                sart=1;               
            }
             
            if(board[index-15]!=' ' && index-15==targetIndex)
            {
                sart=1;               
            }
            if(board[index-17]!=' ' && index-17==targetIndex)
            {
                sart=1;               
            }
         } 
         else
           return sart;
         /* hedef koordinatim bos ise 15 veya 17 adim gitme kosulu */  
         if(board[index+15]==' ' && index+15==targetIndex)
             sart=1;               
         else if(board[index+17]==' ' && index+17==targetIndex)
             sart=1;               
         else if(board[index-15]==' ' && index-15==targetIndex)
             sart=1;               
         else if(board[index-17]==' ' && index-17==targetIndex)
             sart=1;               
         else 
           return sart;
    }    
    /*eger siyah tas(uppercase) var ise, yukaridaki durumlarin 
                aynisi gecerlidir */
    if(stone=='N')
    {
      
         if(board[targetIndex]>='a' && board[targetIndex]<='z' 
                        && board[targetIndex]!=' ')
         {
            if(index%8==7)
            {  
                sart=1;               
            }
            else if(index%8==0)
            {
                sart=1;               
            }
             
            if(board[index+15]!=' ' && index+15==targetIndex)
            {
                sart=1;               
            }
            if(board[index+17]!=' ' && index+17==targetIndex)
            {
                sart=1;               
            }
             
            if(board[index-15]!=' ' && index-15==targetIndex)
            {
                    sart=1;               
            }
            if(board[index-17]!=' ' && index-17==targetIndex)
            {
                sart=1;               
            }
         } 
         else
            return sart; 
            
         if(board[index+15]==' ' && index+15==targetIndex)
                sart=1;               
         else if(board[index+17]==' ' && index+17==targetIndex)
                sart=1;               
         else if(board[index-15]==' ' && index-15==targetIndex)
                sart=1;               
         else if(board[index-17]==' ' && index-17==targetIndex)
                sart=1;               
         else 
                return sart;
               
    }    
     
    return 1;
}
/* fil capraz hareket eder ve istedigi sayida adim atabilir. bunu bulurkende
    target col ve source col ve row karsılastırmalari yaptim. 
    return degeri:fonskiyon integer deger dondurur, bu integer 
    targetteki hedefe ulasıp ulasamayacaginin kontrolu olarak belirtilebilir.*/                
int isBishopMovable(char *board , char sourceCol,
                    int sourceRow, char targetCol, int targetRow)
{
    char stone;
    int i,j,sart=0; /*donguler icin sayaclar */
    int targetIndex,index; /*koordinatlarin indeks degiskenleri */
   
    /*ascii kodu yardımıyla chari inte(indeks degerine ) cevirme */
    targetIndex=((int)targetCol-97)+((8-targetRow)*8); 
    index=((int)sourceCol-97)+((8-sourceRow)*8);   
    stone=board[index];
 
    /*beyaz tas(lowercase) icin hareket kontrolu */
    if(stone=='b')
    {       /*hedefte rakibin tasi varsa                */
            if(board[targetIndex]<='Z' && board[targetIndex]>='A')
            {            
                if(targetCol>=sourceCol)
                {            
                    if(index%9==targetIndex%9)
                    {
                        sart=1;               
                    }           
            }           
            else if(targetCol<=sourceCol)
            {           
                if(index%7==targetIndex%7)
                {               
                    sart=1;               
                }           
            }        
            }
            else if(board[targetIndex]==' ')
            {        
                if(targetCol>=sourceCol)
                {            
                    if(index%9==targetIndex%9)
                    {
                         sart=1;
                    }            
                }           
                else if(targetCol<=sourceCol)
                {
                    if(index%7==targetIndex%7)
                    {
                       sart=1;                    
                    }
                    else
                         sart=0;        
                }
           }
     else
          sart=0;  
    }
   /*siyah tas(uppercase) icin hareket kontrolu */
    else if(stone=='B')
    {  
        if(board[targetIndex]<='z' && board[targetIndex]>='a'){
            
            if(targetCol>=sourceCol)
            {
                if(index%7==targetIndex%7)
                {
                     sart=1;               
                }            
            }    
        
            else if(targetCol<=sourceCol)
            {           
                if(index%9==targetIndex%9)
                {
                     sart=1;              
                }           
            }
                
         else if(board[targetIndex]==' ')
         {         
            if(targetCol>=sourceCol)
            {           
                if(index%7==targetIndex%7)
                  sart=1;           
            }            
            else if(targetCol<=sourceCol)
            {
                if(index%9==targetIndex%9)
                  sart=1;
            }
               else
                   sart=0;       
         }
     }
                
   }
     else
        sart=0;
       
    return sart;
} 
/* sah bir adim ileri veya geri, veyahut carpraz hareket edebilme ozelligine
    sahip, bu fonksiyonda girilen target indeksine gore hedefe ulasıp ulasmama
    kosulunu test eder.8 adim ileri veya geri, 9 ve 7 adim ise carpraza gitme
    durumuna gore degisir.
    return degeri: fonskiyon integer deger dondurur, bu integer 
    targetteki hedefe ulasıp ulasamayacaginin kontrolu olarak belirtilebilir.*/
                                                
int isKingMovable(char *board, char sourceCol, int sourceRow, 
                  char targetCol, int targetRow)
{
    char stone;
    int i,targetIndex,index,sart=0;
    
    targetIndex=((int)targetCol-97)+((8-targetRow)*8); 
    index=((int)sourceCol-97)+((8-sourceRow)*8);   
    stone=board[index];

    if(stone=='k')
    {        
        if( (board[targetIndex]>='A' && board[targetIndex]<='Z')
                 || board[targetIndex==' '])
        {             
                if(index+9==targetIndex)
                {
                    sart=1;
                }
                else if(index-9==targetIndex)
                {
                    sart=1;
                }  
                else if(index-7==targetIndex)
                {
                    sart=1;
                }  
                else if(index+7==targetIndex)
                {
                    sart=1;
                }
                else if(index-8==targetIndex)
                {
                    sart=1;
                }
                else if(index+8==targetIndex)
                {
                    sart=1;
                }   
                else if(index+1==targetIndex)
                {
                    sart=1;
                }
                else if(index+1==targetIndex)
                {
                    sart=1;
                }                    
       }
       else
           sart=0;     
}
    /*siyah tas(uppercase) icin hareket kontrolu */
    else if(stone=='K')
    {        
        if( (board[targetIndex]>='a' && board[targetIndex]<='z')
             || board[targetIndex]==' ')
        {           
                if(index+9==targetIndex)
                {
                    sart=1;
                }
                else if(index-9==targetIndex)
                {
                    sart=1;
                }  
                else if(index-7==targetIndex)
                {
                    sart=1;
                }  
                else if(index+7==targetIndex)
                {
                    sart=1;
                }
                else if(index-8==targetIndex)
                {
                    sart=1;
                }
                else if(index+8==targetIndex)
                {
                    sart=1;
                }   
                else if(index-1==targetIndex)
                {
                    sart=1;
                }
                else if(index+1==targetIndex)
                {
                    sart=1;
                }                    
        }        
        else
            sart=0;     
 }

    return sart;
}
/* kale düz hareket eder ve istedigi kadar adim ilerler. yukari veya asagi gitme
    durumu, ya da saga sola istegi kadar gitme durumu hesaplama ve de onunde
    kendi tasinin oldugu durumu test etme.
    return degeri:fonskiyon integer deger dondurur, bu integer 
    targetteki hedefe ulasıp ulasamayacaginin kontrolu olarak belirtilebilir.*/  
int isRookMovable(char *board , char sourceCol,
                     int sourceRow, char targetCol, int targetRow)
                     
{
    char stone;
    int i,targetIndex,index,sart=0;
    
    targetIndex=((int)targetCol-97)+((8-targetRow)*8); 
    index=((int)sourceCol-97)+((8-sourceRow)*8);   
    stone=board[index];
    /*beyaz tas(lowercase) icin hareket kontrolu */
    if(stone=='r')
    {        
               
        if(board[targetIndex]>='A' && board[targetIndex]<='Z')
                
        
        { /*for dongusu ile gidecegi hedefe kadar onunu bos olup olmadıgının
 kontrol edilmesi ve hedefte rakip tas varsa yiyebilme(hedefe gidebilme kosulu*/
            for(i=1;i<=(abs(targetIndex-index)/8);i++)
            {
                if(board[index+(8*i)]!=' ' && targetIndex==index+(8*i))
                    sart=1;                       
                if(board[index-(8*i)]!=' ' && targetIndex==index-(8*i))
                    sart=1;              
            }
            /*saga ya da sola gidebilmeyi test etme */
            for(i=1;i<=abs(targetIndex-index);i++)
            {
                if(board[index+i]!=' ' && targetIndex==index+i)
                {
                    sart=1;
                }
                else if(board[index-i]!=' ' && targetIndex==index-i)
                {
                    sart=1;
                }             
            }
        } 
        if(board[targetIndex]==' ')
        {   
            for(i=1;i<=(abs(targetIndex-index)/8);i++)
            {
                if(board[index+(8*i)]==' ' && targetIndex==index+(8*i))
                {
                    sart=1;
                }                                    
                if(board[index-(8*i)]==' ' && targetIndex==index-(8*i))
                {
                    sart=1;
                }
                
            }
            for(i=1;i<=abs(targetIndex-index);i++)
            {
                if(board[index+i]==' ' && targetIndex==index+i)
                {
                    sart=1;
                }            
            }
            for(i=1;i<=abs(targetIndex-index);i++)
            {
                if(board[index-i]==' ' && targetIndex==index-i)
                {
                    sart=1;
                }
             
            }
        return sart;
       }  
       /*siyah tas(uppercase) icin hareket kontrolu */
    if(stone=='R')
    {        
               
        if(board[targetIndex]>='a' && board[targetIndex]<='z')
                 
        
        {
            for(i=1;i<=(abs(targetIndex-index)/8);i++)
            {
                if(board[index+(8*i)]!=' ' && targetIndex==index+(8*i))
                {
                    sart=1;
                }             
            }
            for(i=1;i<=(abs(targetIndex-index)/8);i++)
            {
                if(board[index-(8*i)]!=' ' && targetIndex==index-(8*i))
                {
                    sart=1;
                }               
            }
            for(i=1;i<=abs(targetIndex-index);i++)
            {
                if(board[index+i]!=' ' && targetIndex==index+i)
                {
                    sart=1;
                }
                else if(board[index-i]!=' ' && targetIndex==index-i)
                {
                    sart=1;
                }               
            }
        } 
        if(board[targetIndex]==' ')
        {   
            for(i=1;i<=(abs(targetIndex-index)/8);i++)
            {
                if(board[index+(8*i)]==' ' && targetIndex==index+(8*i))
                {
                    sart=1;
                }              
            }
            for(i=1;i<=(abs(targetIndex-index)/8);i++)
            {
                if(board[index-(8*i)]==' ' && targetIndex==index-(8*i))
                {
                    sart=1;
                }
                
            }
            for(i=1;i<=abs(targetIndex-index);i++)
            {
                if(board[index+i]==' ' && targetIndex==index+i)
                {
                    sart=1;
                }            
            }
            for(i=1;i<=abs(targetIndex-index);i++)
            {
                if(board[index-i]==' ' && targetIndex==index-i)
                {
                    sart=1;
                }
             
            }
       }   
     }  
        
}
    return sart;
                  
}          
 int isQueenMovable(char *board , char sourceCol,
                   int sourceRow, char targetCol, int targetRow)
                   
{
    return 0;
}
             
            
            
            
            
    
