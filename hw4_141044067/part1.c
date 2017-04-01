/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW02_141044067_part1_Gokce_Demir                                */ 
/* hw4-part1.c                                                     */
/* Created on 21/03/2016 by Gokce_Demir                            */ 
/* Description                                                     */ 
/* This program gets the degree and n then Taylor series to        */
/*    calculate sine and cosine.                                   */
/* --------------------------------------------------------------- */




#include <stdio.h>
#define PI 3.14

double cosine(int degree, int n);
double sine(int degree, int n);
void getInputs(int* degree, int* n, int* exit);

int main()
{   
    int a,b,c;
    double x,y;
    
    getInputs(&a,&b,&c);   
    
    
    
    
    return (0);
}

void getInputs(int* degree, int* n, int* exit)/*kullanıcıdan girdi alan fonk.*/
{   
    int status; /* E tusuna basınca cıkmayı saglamak icin gecici degiskenler*/
    char junk;  
    
    *exit = 0; 
    
    status = scanf("%d", degree);
    
        if(status == 0)
        {
            scanf("%c", &junk);
            
            if(junk == 'e' || junk=='E') /*yalnızca e harfi icin cıkıs yap*/
            {   *exit = 1;
                 return;
            } 
            
        }
        scanf("%d",n);
        
        
        sine(*degree,*n);
        cosine(*degree,*n);
       
}

double sine(int degree, int n)
{
    double rad=0.0,result; 
    int i,j,k,fact,y,count; /*sayaclar ve faktoriyel icin degisken */
    int flag=0;     /* derecenin buldugunu bölgeye göre isaret belirleyici */
    double x,value=0.0; /* gecici radyan degiskeni ve ulasılan deger */

    /*bolgelere gore isaret belirleme ve dar acıya cevirme */
    y=degree;
    if(y>90 && y<=180)
    {
        y=180%y;
             
    }
    else if(y>180 && y<360)
    {
        y=y%180;
        flag=1;       
    }  
    else if(y>=270)
    {
        y=y%180;
    }
    else if(y==360)
    {
        y=y%180;
    }
    rad=y*(PI/180); /*dereceyi radyana cevirme */
    
   
    i=1;
    k=1;
    while(k<n) /*girilen n degerine kadar donguyu calıstır */
    {
        /* ust bulma */
        x=rad;
        result=1;
        for(j=1;j<=(2*k+1);j++)
        {
            result=result*x;           
        }
        /*faktoriyel hesaplama */
        fact=1;
        for(count=1;count<=(2*k+1);count++)
        {   
            fact=fact*count;                        
        }     
        i*=-1;   
        /*kuvvetleri bulunan radyanın faktoriyele bolumu */
        value+=(i*(result/fact));

        k++;

        }

        value+=rad;
        if(flag==1) /*ucuncu ve dorduncu bolge icin isaret degistirme */
        {
            value*=-1;
        }
    printf("sin(%d) where n is %d = %.4f\n",degree,n,value);

    return value;

    }
    


double cosine(int degree, int n)
{
    double rad,result;
    int y,i,j,k,fact=0,count,flag=0;
    double x,value=0.0;    
    
    /*bolgelere gore isaret belirleme ve dar acıya cevirme */
    y=degree;
    if(y>90 && y<180)
    {
        y=180%y;
        flag=1;
       
    }
    else if(y==180)
    {
        y=y%180;
        flag=1;
    }
    else if(y>180 && y<=270)
    {
        y=y%180;
        flag=1;
    }
    else if(y>270)
    {
        y=y%180;
    }
    rad=y*(PI/180);        
      
    i=1;
    k=1;
    while(k<n) /*girilen n degerine kadar donguyu calıstır */
    {   /* ust bulma */
        x=rad;
        result=1;
        for(j=1;j<=(2*k);j++)
        {
            result=result*x;           
        }
        /*faktoriyel hesaplama */
        fact=1;
        for(count=1;count<=(2*k);count++)
        {   
            fact=fact*count;                        
        }     
        i*=-1;   
        /*kuvvetleri bulunan radyanın faktoriyele bolumu */
        value+=(i*(result/fact));
        
        k++;
    
    }
    
        value+=1;
        if(flag==1) /*ikinci ve ucuncu bolge icin isaret belirleyici */
        {
            value*=-1;
        }
        
    printf("cos(%d) where n is %d = %.4f\n",degree,n,value);
    
    return value;
    
}

/********************************************************************/
/*                        end of the part1.c                        */
/********************************************************************/   
               
        
        
    


        
       
             
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
