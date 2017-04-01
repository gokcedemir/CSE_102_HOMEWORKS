/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW06_141044067_Gokce_Demir                                      */ 
/* hw6.c                                                           */
/*  06/04/2016 tarihinde olusturuldu.                              */ 
/* Acıklama :                                                      */ 
/*  Bu program her bir karekterin string icinde kac kez gectigini   */
/*  bulur ve harflerdeki buyuk ve kucuk hassasiyetini goz ardı     */
/*  eder.                                                          */                                                      
/* --------------------------------------------------------------- */


#include <stdio.h>

/*fonksiyonun prototipi */
void freq(char* str,int* fr);

int main()
{
    int i,j;
    int fr[37];
    freq("abCd Ef ghIj kLM nopr stuv yzwxq 123 4 5 6 7 890 00 ?? |",fr);
    
    printf("\nFrequency of all characters  \n");  
    for(i=0; i<26; i++)  
    {  
        
            printf("%c = %d\n",(i+65),fr[i]);          
    }
   for(i=0;i<10;i++)
    {
                      printf("%d = %d\n",i,fr[i+26]);          
    }
    
    printf("others=%d",fr[36]);
    
     
        return 0;  
} 
 
void freq(char* str,int* fr)
{
    int i;
    
     /* Her karekterin frekansini sifirdan baslatir         */  
    for(i=0; i<37; i++)  
    {  
        fr[i] =0;  
    }  
    for(i=0;str[i]!='\0';i++)  
    {  
     /*  Eger karekter kucuk harf ise */  
        if(str[i]>='a' && str[i]<='z')  
        {  
       /* ascii degerini cevirme (97- a harfinin ascii degeri */
            fr[(int)str[i] - 97]++;             
        } 
      /* Eger karekter buyuk harf ise */ 
        else if(str[i]>='A' && str[i]<='Z')  
        {  /* 65- A harfinin ascii degeri                  */ 
            fr[(int)str[i] - 65]++;   
        }  
        /* Eger karekter 0-9 arasinda ise */
        else if(str[i]>='0' && str[i]<='9')
        {
            fr[(int)(str[i]-'0')+26]++;          
        } 
        /*  Diger karekterler icin         */
        else
            fr[36]++;       
    }  
}

        
/********************************************************************/
/*                        end of the hw6.c                          */
/********************************************************************/

