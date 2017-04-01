/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW06_141044067_part3_Gokce_Demir                                */ 
/* hw6-part3.c                                                     */
/*  09/04/2016 tarihinde olusturuldu.                              */ 
/* Acıklama :                                                      */ 
/*  Bu program her bir karekterin string icinde kac kez gectigini  */
/*  bulur bunu yaparken sadece tek indeksleri goz onunde           */
/*  bulundurur ve harflerdeki buyuk ve kucuk hassasiyetini goz ardı*/
/*  eder.                                                          */
/* Return Degeri: Integer deger dondurur, bu deger string icinde   */
/* kac kez aranan kelimenin gectigini bulan fonskiyonun dondurdugu */
/*   degerdir.                                                     */                                                   
/* --------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
int count(char* str,char* substr);

int main()
{   
   
     count("ecececece","ece");
     printf("%d", count("ecececece","ece"));
    return 0;
}
/* Aranan karekterin sadece tek indekslerinin string icinde kac kez gectigini
  bulur.                                                                 */
int count(char* str,char* substr)
{
    int s1,s2,i;
    int eslik=0;
    int counter=0;
    
    if(strlen(substr)>strlen(str))
    {
        return 0;
    }
       
    for(s1=0;s1<strlen(str);s1++)
    {
        if(str[s1]==substr[0])
        {
            for(s2=0;s2<strlen(substr);s2+=2)
            {
               eslik=0; if(str[s1+s2]==substr[s2])
                {
                    eslik++;
                }
                else
		        {
		            eslik=0;
		            
		        }
                if(eslik==s2/2)
                {
                    counter++;
                    eslik=0;
                }
             }
         }
    }
 
    /* Kelimenin kac kez gectigini ineteger bir deger olarak return eder   */      
    return counter ;
}

        
/********************************************************************/
/*                        end of the hw6-part3.c                    */
/********************************************************************/
