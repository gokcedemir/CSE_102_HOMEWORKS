/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW06_141044067_part2_Gokce_Demir                                */ 
/* hw6-part2.c                                                     */
/*  09/04/2016 tarihinde olusturuldu.                              */ 
/* Acıklama :                                                      */ 
/*   Bu program yazilan fonksiyon yardimiyla alt dizide aranan     */
/*   kelimenin stringdeki tek indeksli karekterlerle  eslesip      */
/*   eslenmediklerine bakar.                                       */
/* Return Degeri:                                                  */                         
/*  Return degeri olarak karekter dondurur, bu deger eslesen       */
/* ilk harfin adresidir.                                           */
/*  Buldugu harfin indeksininden baslayarak stringin sonuna kadar  */
/*  ekrana bastirir. Eger eslesme yok ise NULL (return 0) dondurur.*/                                                    
/* --------------------------------------------------------------- */

#include<math.h>
#include <stdio.h>
#include <string.h>
char* matcher(char* haystack, char* needle);

int main()
{   
 	char  haystack[]="lorem ipsum amet";
	char needle[]="loremat";
     
     printf("%s",matcher(haystack,needle));
    return 0;
}

char* matcher(char* haystack, char* needle)
{
    int s1,s2;
    int eslik=0;
    
    /*Eger aranacak dizinin size buyuk ise null dondurur */   
    if(strlen(needle)>strlen(haystack))
    {
        return NULL;
    }
    
  
    for(s1=0;s1<strlen(haystack);s1++)
    {	
    /*eger ilk karekterler esitse tek indeksli karekerleri kontrol etmeye
		                devam eder   */
    	if(haystack[s1]==needle[0])
		{
            for(s2=0;s2<strlen(needle);s2+=2)
            {					
                if(haystack[s1+s2]==needle[s2])
                {
				    eslik++;										
                }
				else
				{											
					eslik=0;
                }                             			
            }	
	    }
	
	    if(eslik>=(strlen(needle))/2)
        {               /*eslesen ilk karekterin adresini return eder  */
                        return &haystack[s1];                    
        }
    }
	
    return NULL;
}

       
/********************************************************************/
/*                        end of the hw6-part2.c                    */
/********************************************************************/ 
 





