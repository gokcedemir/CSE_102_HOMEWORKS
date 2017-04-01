/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW07_141044067_Gokce_Demir                                      */ 
/* hw7_part2.c                                                     */
/*  14/04/2016 tarihinde olusturuldu.                              */ 
/* Acıklama :                                                      */ 
/*  Yetistiremediğim icin yaptigim kadarini gonderiyorum,          */
/*   kusura bakmayin.                                              */       
/* --------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265

int reflection(int angle);
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth);
int randNumber(int angle);

int main()
{
    int rest;
    rest=kickDisc(10, 26, 2, 45, 1, 2);
    printf("%d",rest);
    return (0);
}

int reflection(int angle)
{

    angle=angle+(randNumber(angle)%11)-5;
    if(angle>175)
        angle=175;
    
    else if(angle<5)
        angle=5;

    return angle;
}

int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth)
{
    int result=0;
    int deltaH;
     
  
    if(ballRadius<=0)
        return result;
    if(walWidth<=0)
        return result;
    if(kickAngle>175 || kickAngle<5)
        return result;
    
    deltaH=wallHeight-((wallWidth-ballCenterX)*kickAngle);
    printf("%d",deltaH);
    kickAngle=tan((kickAngle*PI)/180);
    
    if(kickAngle==90 && (wallWidth-ballCenterX==wallWidth/2))
        result=1;
    else if(kickAngle==90 && (wallWidth-ballCenterX!=wallWidth/2))
        return result; 
    result=1;
} 
      
int randNumber(int angle)
{
    srand(angle);
    return rand();
}

/********************************************************************/
/*                        end of the hw7_part2.c                    */
/********************************************************************/












