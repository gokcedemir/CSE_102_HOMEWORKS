/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW02_141044067_part1_Gokce_Demir                                */ 
/* hw4-part2.c                                                     */
/* 21/03/2016  Gokce_Demir                                        */ 
/* Acıklama:                                                       */ 
/* Bu program kullanıcıdan pozitif sayı alarak ascii sanatıyla     */
/* ekrana degerinizi basar. Ayrıca kullanıcı kullanacagı karekteri */
/*  ve sınır sayısını kendi belirler.                              */                     
/*                                                                 */
/* --------------------------------------------------------------- */


#include <stdio.h>

/* girdileri alan fonksiyon */
void getInputs(int* num, int* borderWidth, char* borderChar);
/* rakamları ekrana yazan fonksiyon */
int printNumber(int num, int borderWidth, char borderChar);
void printNum(int num,int line,char ch);
void printZero(int line,char ch);
void printOne(int line,char ch);
void printTwo(int line,char ch);
void printThree(int line,char ch);
void printFour(int line,char ch);
void printFive(int line,char ch);
void printSix(int line,char ch);
void printSeven(int line,char ch);
void printEight(int line,char ch);
void printNine(int line,char ch);

int main()
{
    int num,borderWidth;
    char borderChar;
   
    getInputs(&num,&borderWidth,&borderChar);
    printNumber(num,borderWidth,borderChar);
    return(0);
    
    
}

void getInputs(int* num, int* borderWidth, char* borderChar)
{   /*girdileri alma */
    scanf("%d %d %c",num,borderWidth,borderChar);
    
}
int printNumber(int num, int borderWidth, char borderChar)
{
    int b1,b2,b3,b4,b5; /*basamak sayisi */
    int sayac,i,j,k,m; /*satir satir rakamları basmak icin sayas */
    int islem; /*basamak sayısına göre kenar kalınlığını bulma */
    
    if(num<0)
    {
        return 0;
    }
    if(num>=0 && num<10)
    {  
        /*basamak sayısına göre kenar kalınlığını bulma */
        islem=7+(2*borderWidth);
        for(m=1;m<=borderWidth;m++)   /*cerceveyi cizdirme */
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
	    for(sayac=1;sayac<8;sayac++) /*satir satir bastirma */
	    {
	        for(i=1;i<=borderWidth;i++)
	        {
	            printf("%c",borderChar);	            
	        }
	       
		    printNum(num,sayac,borderChar);
		    
		    for(j=1;j<=borderWidth;j++)
	        {
	                printf("%c",borderChar);
		    }
		    printf("\n");		    
	    } 
	    for(m=1;m<=borderWidth;m++)
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
	        
	    
}
    if(num>=10 && num<100)
    {
	   /*iki basamakli sayiyi rakamlarina ayirma */
	    b2=num%10;
	    b1=(num-b2)/10;
	    
       /*kenar kalinligini hesaplama */
	    islem=(7*2)+(2*borderWidth);
        for(m=1;m<=borderWidth;m++)
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
	    for(sayac=1;sayac<8;sayac++)
	    {
	        for(i=1;i<=borderWidth;i++)
	        {
	            printf("%c",borderChar);
	            
	        }
		    printNum(b1,sayac,borderChar);
		    printNum(b2,sayac,borderChar);
		    for(j=1;j<=borderWidth;j++)
	        {
	                printf("%c",borderChar);
		    }
		    printf("\n");		
	    }
	   
        for(m=1;m<=borderWidth;m++)
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
    }
    if(num>=100 && num<1000)
    {
	    /*uc sayiyi rakamlarina ayirma */
	    b3=num%10;
	    b2=((num-b3)/10)%10;
	    b1=(((num-b3)/10)-b2)/10;
	    
	    islem=(7*3)+(2*borderWidth);
        for(m=1;m<=borderWidth;m++)
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
	    for(sayac=1;sayac<8;sayac++)
	    {
	        for(i=1;i<=borderWidth;i++)
	        {
	            printf("%c",borderChar);
	            
	        }
		    printNum(b1,sayac,borderChar);
		    printNum(b2,sayac,borderChar);
		    printNum(b3,sayac,borderChar);
		    for(j=1;j<=borderWidth;j++)
	        {
	                printf("%c",borderChar);
		    }
		    printf("\n");		
	    }
	    
        for(m=1;m<=borderWidth;m++)
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
    }
    if(num>=1000 && num<10000) /*sayi dort basamaklı ise */
    {
	    /*dort basamakli sayiyi rakamlarina ayirma */
	    b4=num%10;
	    b3=((num-b4)/10)%10;
	    b2=((((num-b4)/10)-b3)/10)%10;
	    b1=(((((num-b4)/10)-b3)/10)-b2)/10;
	    
	    /*kenar kalinligini hesaplama */
	    islem=(7*4)+(2*borderWidth);
        for(m=1;m<=borderWidth;m++)
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
	    for(sayac=1;sayac<8;sayac++)
	    {
	        for(i=1;i<=borderWidth;i++)
	        {
	            printf("%c",borderChar);
	            
	        }
		    printNum(b1,sayac,borderChar);
		    printNum(b2,sayac,borderChar);
		    printNum(b3,sayac,borderChar);
		    printNum(b4,sayac,borderChar);
		    for(j=1;j<=borderWidth;j++)
	        {
	                printf("%c",borderChar);
		    }
		    printf("\n");		
	    }
	    
        for(m=1;m<=borderWidth;m++)
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
    }
    if(num>=10000 && num<=99999) /*sayi bes basamaklı ise */
    {	    
        /*bes basamakli sayiyi rakamlarina ayirma */
         b5=num%10;
         b4=((num-b5)/10)%10;
         b3=(((num-b5)/10)/10)%10;
         b2=((((num-b5)/10)/10)/10)%10;
         b1=((((num-b5)/10)/10)/10)/10;
	    
	    /*kenar kalinligini hesaplama */
	    islem=(7*5)+(2*borderWidth);
        for(m=1;m<=borderWidth;m++)
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
	    for(sayac=1;sayac<8;sayac++)
	    {
	        for(i=1;i<=borderWidth;i++)
	        {
	            printf("%c",borderChar);
	            
	        }
		    printNum(b1,sayac,borderChar);
		    printNum(b2,sayac,borderChar);
		    printNum(b3,sayac,borderChar);
		    printNum(b4,sayac,borderChar);
		    printNum(b5,sayac,borderChar);
		   
		    for(j=1;j<=borderWidth;j++)
	        {
	                printf("%c",borderChar);
		    }
		    printf("\n");		
	    }
	    
        for(m=1;m<=borderWidth;m++)
        {
            for(k=1;k<=islem;k++)
            {
            printf("%c",borderChar);
            }
        printf("\n");
        }
	}
	if(num>99999) /*eger sayi bes basamaklıdan buyuk ise cıkar */
	{
	    return 0;
	}
	return 1; /*eger sifirdan buyuk ve esitse ve de 99999 kucukse calistirir */
}


void printNum(int num,int line,char ch) /*rakamları yazdıran fonksiyon */
{  
    if(num==0)
    {
	    printZero(line,ch);
    }
    if(num==1)
    {
	    printOne(line,ch);
    }
    if(num==2)
    {
	    printTwo(line,ch);
    }
    if(num==3)
    {
	    printThree(line,ch);
    }
    if(num==4)
    {
	    printFour(line,ch);
    }
    if(num==5)
    {
	    printFive(line,ch);
    }
    if(num==6)
    {
	    printSix(line,ch);
    }
    if(num==7)
    {
	    printSeven(line,ch);
    }
    if(num==8)
    {
	    printEight(line,ch);
    }
    if(num==9)
    {
	    printNine(line,ch);
    }
}
 
void printZero(int line,char ch)
{   
   
    if(line==1)
    {   
        printf("       "); 
    }
    else if(line==2)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==3)
    {
        printf("  %c %c  ",ch,ch);
    }
    else if(line==4)
    {
        printf("  %c %c  ",ch,ch);
    }
    else if(line==5)
    {
        printf("  %c %c  ",ch,ch);  
    }
    else if(line==6)
    {  
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==7)
    {
        printf("       ");
    }
          
}  

void printOne(int line,char ch)
{         
 
    if(line==1)
    {   
        printf("       ");  
    }
    else if(line==2)
    {  
        printf("   %c   ",ch);
    }
    else if(line==3)
    {
        printf("  %c%c   ",ch,ch);
    }
    else if(line==4)
    { 
        printf("   %c   ",ch);
    } 
    else if(line==5)
    {
        printf("   %c   ",ch);
    }
    else if(line==6)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==7)
    {
        printf("       ");
    }
}

void printTwo(int line,char ch)
{
    
    if(line==1)
    {   
        printf("       "); 
    }
    else if(line==2)
    {   
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==3)
    {
        printf("    %c  ",ch);
    }
    else if(line==4)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==5)
    {
        printf("  %c    ",ch);
    }
    else if(line==6)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==7)
    {
        printf("       ");
    }
}

void printThree(int line,char ch)
{
   
    if(line==1)
    {   
        printf("       ");    
    }
    else if(line==2)
    { 
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==3)
    {         
        printf("    %c  ",ch);
    }
    else if(line==4)
    {
        printf("   %c%c  ",ch,ch);
    }
    else if(line==5)
    {
        printf("    %c  ",ch);    
    }
    else if(line==6)
    {    
        printf("  %c%c%c  ",ch,ch,ch);   
    }
    else if(line==7)   
    {
        printf("       ");  
    }

}
        
void printFour(int line,char ch)
{
    
    if(line==1)
    {   
        printf("       "); 
    }
    if(line==2)
    {        
        printf("  %c %c  ",ch,ch);
    }
    else if(line==3)
    {
        printf("  %c %c  ",ch,ch);
    }
    else if(line==4)
    {
        printf("  %c%c%c  ",ch,ch,ch);  
    }
    else if(line==5)
    {
        printf("    %c  ",ch); 
    }
    else if(line==6)
    {              
        printf("    %c  ",ch);
    }
    else if(line==7)
    {
        printf("       "); 
    }
}

void printFive(int line,char ch)
{
   
    if(line==1)
    {   
        printf("       "); 
    }
    else if(line==2)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==3)
    {
        printf("  %c    ",ch);
    }
    else if(line==4)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==5)
    {
        printf("    %c  ",ch);   
    }
       else if(line==6)
    {     
        printf("  %c%c%c  ",ch,ch,ch);                     
    }
    else if(line==7)
    {     
        printf("       ");     }
}

void printSix(int line,char ch)
{
    
    if(line==1)
    {   
        printf("       "); 
    }
    else if(line==2)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==3)
    {
        printf("  %c    ",ch);
    }
    else if(line==4)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==5)
    {  
        printf("  %c %c  ",ch,ch);
    }
    else if(line==6)
    {
        printf("  %c%c%c  ",ch,ch,ch); 
    }
    else if(line==7)
    {                                 
        printf("       ");     }
}

void printSeven(int line,char ch)
{
    
    if(line==1)
    {   
        printf("       "); 
    }
    else if(line==2)
    {
        printf("  %c%c%c  ",ch,ch,ch); 
    }
    else if(line==3)
    {
        printf("    %c  ",ch);
    }
    else if(line==4)
    {
        printf("    %c  ",ch);
    }
    else if(line==5)
    {
        printf("    %c  ",ch);    
    }
    else if(line==6)
    {    
        printf("    %c  ",ch);
    }
    else if(line==7)
    {
        printf("       "); 
    }
}

void printEight(int line,char ch)
{
    
    if(line==1)
    {   
        printf("       "); 
    }
    else if(line==2)
    { 
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==3)
    {
        printf("  %c %c  ",ch,ch);
    }
    else if(line==4)
    {
        printf("  %c%c%c  ",ch,ch,ch); 
    }
    else if(line==5)
    {   
        printf("  %c %c  ",ch,ch); 
    }
    else if(line==6)
    {      
        printf("  %c%c%c  ",ch,ch,ch);  
    }
    else if(line==7)
    {                              
        printf("       "); 
    }
}

void printNine(int line,char ch)
{
 
    if(line==1)
    {  
        printf("       ");  
    }
    else if(line==2)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==3)
    {
        printf("  %c %c  ",ch,ch);
    }
    else if(line==4)
    {
        printf("  %c%c%c  ",ch,ch,ch); 
    }
    else if(line==5)
    {
        printf("    %c  ",ch);
    }
    else if(line==6)
    {
        printf("  %c%c%c  ",ch,ch,ch);
    }
    else if(line==7)
    {    
        printf("       "); 
    }                
                                                         
}

/********************************************************************/
/*                        end of the part2.c                        */
/********************************************************************/   

