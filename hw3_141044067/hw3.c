/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW03_141044067_Gokce_Demir                                      */ 
/* hw3.c                                                           */
/* Created on 06/03/2016 by Gokce_Demir                            */ 
/* Description:                                                    */ 
/* This program which asks users for an integer and checks if the  */
/*  number is and odd, a factorial or a narcissistic number,       */
/*  depending on the user choice.                                  */                                                      
/*                                                                 */
/* --------------------------------------------------------------- */

#include <stdio.h>     /* printf, scanf definitions */
#include <math.h>      /* definition of pow */

/*Function prototypes */
void oddNumber(int positiveNum); /* function of odd number */
void factorialNumber(int positiveNum); /*function of factorial number */
void narcissisticNumber(int positiveNum); /*function of narcissistic number */

int main()
{   
    int positiveNum; /* input - get an integer number */
    int select=0;      /* input - choose of operation */
    char selection;  /* input - character choose end or continue */
   
    
    /* Prints output message of welcome. */
      
    printf("*****************************************************");
    printf("\n*              WELCOME!                             *");
    printf("\n*  This program checks whether the given number     *");
    printf("\n* is an odd, a factorial or a narcissistic number   *");
    printf("\n*                                                   *");
    printf("\n*****************************************************\n");
        
    selection='Y';    
    while(selection=='Y'|| selection=='y')
        {   /*Enter your a positive number */
            printf("Please enter a positive integer :  ");
            scanf("%d",&positiveNum);
            
                if(positiveNum<=0)
                {
                    printf("The entered number is not positive.\n");
                     
                    printf("Do you want to continue(y/n)? ");
                    scanf(" %c",&selection);
                    
                    if(selection== 'N' || selection =='n')
                    {
                        printf("Goodbye !\n"); 
                        return 0;                         
                    }                  
                    else if(selection !='y' && selection !='Y')              
                    {
                         printf("Invalid characters.\n");
                         return 0;
                             
                    }
                    
                }        
                else 
                {   /* Asks user of operation */                            
                    printf("Which property would you like to check?\n");
                    printf("1)Odd number\n");
                    printf("2)Factorial number\n");
                    printf("3)Narcissistic number\n");
                    printf("Please enter(1/2/3): ");
                    scanf("%d",&select);
                                    
                    if(select==1)
                    {  /*Called function of odd number*/
                       oddNumber(positiveNum);
                       printf("Do you want to continue(y/n)? ");
                       scanf(" %c",&selection);      
                       
                       if(selection== 'N' || selection =='n')
                       {
                            printf("Goodbye !\n"); 
                            return 0;                         
                       } 
                       if(selection!='y' && selection !='Y')                     
                       {
                            printf("Invalid characters.\n");
                            return 0;
                             
                       }
                    }
                    else if(select==2)                   
                    {   /*Called function of factorial number */
                        factorialNumber(positiveNum);
                        printf("Do you want to continue(y/n)? ");
                        scanf(" %c",&selection);   

                        if(selection== 'N' || selection =='n')
                        {
                            printf("Goodbye !\n"); 
                            return 0;                         
                        }
                        if(selection !='y' && selection !='Y')                     
                        {
                            printf("Invalid characters.\n");
                            return 0;                           
                       }
                    
                    }
                    else if(select==3)
                    {   /*Called function of narcissistic number */
                        narcissisticNumber(positiveNum);
                        printf("Do you want to continue(y/n)? ");
                        scanf(" %c",&selection);   
                        
                        if(selection== 'N' || selection =='n')
                        {
                            printf("Goodbye !\n"); 
                            return 0;                                                      
                        }
                        if(selection !='y' && selection !='Y')                     
                        {
                             printf("Invalid characters.\n");
                             return 0;                       
                        }
                    }
                    else if(select!=1 && select!=2 && select!=3)
                    {
                        printf("Error!\n");
                        return 0;
                    } 
                }    
          }           
    return(0);
}

void oddNumber(int positiveNum)
{   /* Check odd numbers */
    if(positiveNum%2==0)
    {   /*Display message based on odd number */
        printf("%d is not an odd number !\n",positiveNum);                
    }
    else
    {
        printf("%d is an odd number !\n",positiveNum);
    }    
}                                                       
        
void factorialNumber(int positiveNum)
{
    int count;        /*counter for factorial number */
    int fact;        /* output - compute factorial number */
     
    /*Calculate the factorial of number */   
    fact=1;
    for(count=1;fact<positiveNum;count++)
    {
        fact=fact*count;
       
    }     
    if(fact==positiveNum)
    {   /*Display message based on factorial number */
        printf("%d is a factorial number !\n",positiveNum);
    }
    else
    {
        printf("%d is not a factorial number !\n",positiveNum);
    }           
                         
}                           

void narcissisticNumber(int positiveNum)
{
    int i,  /* counter for narsistic of number  */
        sonuc,  /*calculate narcissistic number */
        x,y,    /* assignment of positive number */
        mod,     
        digitPlace=0; /* digits of number */

    sonuc=0;                                                            
    x=positiveNum;  /* assignment of positive number */             
    while(x>0)
    {       /*Find digits of number */
        digitPlace++;
        x=x/10;
    }              
               
    y=positiveNum;   /* assignment of positive number */

    for(i=1;i<=digitPlace;i++)
    {   
    mod=y%10;
    y=y/10;
    /*Calculate the narsistic number */                    
    sonuc=sonuc+pow(mod,digitPlace);              
    }

    if(sonuc==positiveNum)
    {    /*Display message based on narcissistic number */
    printf("%d is narcissistic number !\n",positiveNum);
    }
    else
    {
    printf("%d is not narcissistic number !\n",positiveNum);         
    }                                        
    }               
            
        
/********************************************************************/
/*                        end of the hw3.c                          */
/********************************************************************/   
                                           
                            
                            
                            
                            
                            
                            
                            
                            
                            
                        
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
