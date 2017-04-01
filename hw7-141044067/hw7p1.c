/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW07_141044067_Gokce_Demir                                      */ 
/* hw7_part1.c                                                     */
/*  12/04/2016 tarihinde olusturuldu.                              */ 
/* Acıklama :                                                      */ 
/*  Bu program, recursive fonksiyon kullanilarak string içinde     */
/*  palindrom buluyor. Bu string noktalama işaretleri, rakam veya  */
/*  harf içerebilir.Palindrom durumu için ise sadece harflere      */
/*  bakiyor.Buyuk kucuk harfe duyarlı değil.                       */
/*                                                                 */                                                      
/* --------------------------------------------------------------- */

#include <stdio.h>

int findOfStringSize(char* str);
int isPalindrome(char* str);
char lower(char* low);

int main()
{
    isPalindrome("ab-*ba");
    printf("%d\n",isPalindrome("ab-*ba"));
    return (0);
}

int isPalindrome(char * str)
{
    int i,j=0;
    int size;
    int result;
    char swap[200];
    
    /* sadece harflerin bulundugu swap isimli yeni bir string olusturdum.  */
    for(i=0;str[i]!='\0';i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            swap[j]=str[i];
            j++;                     
        }        
    }
    swap[j]='\0'; 
 /*buyuk kucuk harf duyarliligini ortadan kaldırmak icin cagirdigim fonksiyon */
    lower(swap);
    /* olusan yeni stringin boyunu bulmak icin findOfStringSize
                     fonksiyonu kullandim. */
    size=findOfStringSize(swap);  
   
    
    if(swap==NULL)
    {
        return 0;       
    }
    
    if (swap[0]!=swap[size-1])
    {
        return 0;
    }
    if(size==1 || size==0) 
    {
        return 1;
    }
    if(swap[0]==swap[size-1])
    {
        swap[size-1]='\0';
        
        result=isPalindrome(&swap[1]);
       
        return result;
    }
    return 1;      
}
/*Harf hassasiyetini kaldırmak için kullandigim fonksiyon.
  Return Degeri: Return degeri karekter arrayi dondurur. */
char lower(char* low)
{
    int i;   
    for(i=0;low[i]!='\0';i++)
    {
        if(low[i]>='a' && low[i]<='z')
        {
            low[i]=(int)low[i]-32;
        }      
    }
    return *low;
}

/*  Recursive ile stringin uzunlugunu buldugum fonksiyon.
    Return degeri: integer bir deger return eder, bu deger stringin uzunluguna
     gore degisir.                         */
int findOfStringSize(char *str)
{
    if(str[0]=='\0')
		return 0;
    else
		return findOfStringSize(&str[1])+1;
    return 1;    
}
      
/********************************************************************/
/*                        end of the hw7_part1.c                    */
/********************************************************************/
















