/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW01_141044067_part2_Gokce_Demir                                */ 
/* part2.c                                                         */
/* Created on 17/02/2016 by Gokce_Demir                            */ 
/* Description                                                     */ 
/* This program gets the birthdate and current date, then          */
/*  calculate the how many days user lived. Also, another planet.  */
/* --------------------------------------------------------------- */

#include <stdio.h>
int main()
{
        int currentYear,currentMonth,currentDay;
        int birthYear,birthMonth,birthDay;
        int totalCurrentDays,totalCurrentMonths,totalCurrentYears;
        int livedYears,livedMonths,livedDays;
        int totalLivedDays;
        int anotherPlanetHours,anotherPlanetMonths,anotherPlanetDays;
        int anotherPlanetLivedDays,anotherPlanetLivedMonths,
        anotherPlanetLivedYears,anotherPlanetTotalDays; 
        
        /* Taken the current date. */
       
        printf("Please enter the current date.\n");
        
        printf("Year:");
        scanf("%d",&currentYear);
        
        printf("Month:");
        scanf("%d",&currentMonth);
        
        printf("Day:");
        scanf("%d",&currentDay);
        
        /* Taken the birthdate. */
        
        printf("Please enter your birthday.\n");
        
        printf("Year:");
        scanf("%d",&birthYear);
        
        printf("Month:");
        scanf("%d",&birthMonth);
        
        printf("Day:");
        scanf("%d",&birthDay);
        
        /* Calculated the total current days. */
        
        totalCurrentYears=currentYear*365;
        
        totalCurrentMonths=currentMonth*30;
        
        totalCurrentDays=currentDay+totalCurrentYears+totalCurrentMonths;
        
        /* Calculated the total years, months and days. */
        
        livedYears=birthYear*365;
        
        livedMonths=birthMonth*30;
        
        livedDays=birthDay+livedYears+livedMonths;
        
        /* Calculated the total lived days. */
       
        totalLivedDays=totalCurrentDays-livedDays;
        
        printf("You have lived %d days.\n",totalLivedDays);
        
        
        
        
        
        /* Taken the time of another planet. */
        
        printf("Please enter about the time of another planet\n");
        
        printf("How many hours is a day?");
        scanf("%d",&anotherPlanetHours);
        
        printf("How many days is a month?");
        scanf("%d",&anotherPlanetDays);
        
        printf("How many months is a year?");
        scanf("%d",&anotherPlanetMonths);
        
        
        
        
        /* Calculated the lived days,months and years. */
        
        anotherPlanetTotalDays=(totalLivedDays*24/anotherPlanetHours);
        
        anotherPlanetLivedDays=((totalLivedDays*24/anotherPlanetHours)%
                                (anotherPlanetDays));
        
        anotherPlanetLivedMonths=(((totalLivedDays*24/anotherPlanetHours)/
                                 (anotherPlanetDays))%(anotherPlanetMonths)) ;
        
        
        anotherPlanetLivedYears=((anotherPlanetTotalDays)/
                                (anotherPlanetDays*anotherPlanetMonths));
         
       
       printf("If you lived in a planet where a day ");
      
       printf("is %d hours, ",anotherPlanetHours);
      
       printf("a month is %d days ",anotherPlanetDays);
      
       printf("and a year is %d months: ",anotherPlanetMonths);
      
       printf("you were %d years, ",anotherPlanetLivedYears);
      
       printf("%d months and ",anotherPlanetLivedMonths);
      
       printf("%d days old\n",anotherPlanetLivedDays);
       
     
        return(0);
       
}
        
/********************************************************************/
/*                        end of the part2.c                         */
/********************************************************************/   
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
