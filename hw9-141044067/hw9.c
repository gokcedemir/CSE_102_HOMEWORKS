/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW09_141044067_Gokce_Demir                                      */ 
/* hw9.c                                                           */
/* 28/04/2016 tarihinde olusturuldu.                               */ 
/* Acıklama :                                                      */ 
/*  Bu program ulkelerin bilgilerini tutuyor, bu bilgileri (a)     */
/*  sıkkında alır.Bunlar ulkenin ismi, ordu sayisi, nufusu,yuzey   */
/*  alani ve en fazla 10 tane komsu ulkesidir.(b) seceneginde      */
/*  istenilen ulkeyi komsuları ve komsularının komsularıyla        */
/*  kıyaslarak en fazla sahip olunan asker sayisini bulur.         */
/*  (c)seceneginde ise en buyuk ulkeyi bulur. (e)secenegi kullanici*/   
/*  cikmak istediginde e'ye basar.Butun bu bilgiler struct         */
/*  icinde tutulur.                                                */                                
/* --------------------------------------------------------------- */


#include <stdio.h>
#include <string.h>

/* global struct prototipi */
typedef struct {
    char name[25];
    int pop;
    double area;
    int soldiers;
    char neighbors[10][25];
    } country;

int main()
{
    char choice;
    country cntry[100];
    int i,j,count=0,max,sayac=0;
    int counter=0,flag=0;
    double largest;
    
    while(1)
    {
        printf("Make your choice:\n");
        scanf(" %c",&choice);
        switch(choice)
        {
            
            case 'a':
                  scanf("%s",cntry[sayac].name);
                  
                  scanf("%d",&cntry[sayac].pop);
                 
                  scanf("%lf",&cntry[sayac].area);
                        
                  scanf("%d",&cntry[sayac].soldiers);
                  
                  flag=0;
                  for(i=0;i<10 && flag!=1;i++)
                  {
                      scanf("%s",cntry[sayac].neighbors[i]);
                      count++;   
    /* kullanici sentinel deger olan -1'i girdiginde a seceneginden cikar */
                      if(strcmp(cntry[sayac].neighbors[i],"-1")==0)
                                                 
                           flag=1;
                  }
                  sayac++;
                  break;  
                  
            case 'b':
                   
                    scanf("%s",cntry[sayac].name);
                    max=cntry[0].soldiers;
                    for(i=0;i<count;i++)
                    {
                      
                         
                            if((cntry[i].soldiers)>=max)
                            {
                                max=cntry[i].soldiers;
                                counter=i;
                            }
                                                            
                    }                   
                    printf("<output>%s\n",cntry[counter].name);               
                    break;
                    
            case 'c':
                    scanf("%s",cntry->name);
                    largest=cntry[0].area;
                    for(i=0;i<count;i++)
                    {
                        if(cntry[i].area>=largest)
                        {
                            largest=cntry[i].area;
                            counter=i;
                        }
                    }
                    printf("<output>%s\n",cntry[counter].name);
                    break;
            case 'd':
                    
                    break;
            case 'e':
                    printf("<output>Good Bye\n");
                    return 0;
                    break;
         }
         
     }
     
     return 0;
}


/********************************************************************/
/*                        end of the hw9.c                          */
/********************************************************************/            
                    
                    
                    
                    
                    
                    
                    
                    
