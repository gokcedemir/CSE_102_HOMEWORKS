/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW01_141044067_part1_Gokce_Demir                                */ 
/* hw1-part1.c                                                     */
/* Created on 17/02/2016 by Gokce_Demir                            */ 
/* Description                                                     */ 
/* This program gets the weights and grades then calculated the    */
/* final grade.                                                    */

/* --------------------------------------------------------------- */

#include <stdio.h>
int main()
{ 
    int midtermWeight1,midtermWeight2,midtermWeight3,homeworkWeight1,
                    homeworkWeight2,finalWeight;
    
    double midtermGrade1,midtermGrade2,midtermGrade3,homeworkGrade1,
                    homeworkGrade2,finalGrade;
    
    double midtermTotalGrade,homeworkTotalGrade,finalTotalGrade;
    
  
  /* Taken midterm first weight */
  printf("Please enter the 1. midterm weight:");
  scanf("%d",&midtermWeight1);
  
  /* Taken midterm second weight */
  printf("Please enter the 2. midterm weight:");
  scanf("%d",&midtermWeight2);
  
  /* Taken midterm third weight */
  printf("Please enter the 3. midterm weight:");
  scanf("%d",&midtermWeight3);
  
  /* Taken homework first weight */
  printf("Please enter the 1. homework weight:");
  scanf("%d",&homeworkWeight1);
  
  /* Taken howework second weight */
  printf("Please enter the 2. homework weight:");
  scanf("%d",&homeworkWeight2);
  
  /* Taken final exam weight */
  printf("Please enter the final exam weight:");
  scanf("%d",&finalWeight);
  
  /* Taken midterm first grade */
  printf("Please enter the 1. midterm grade:");
  scanf("%lf",&midtermGrade1);
  
  /* Taken midterm second grade */
  printf("Please enter the 2. midterm grade:");
  scanf("%lf",&midtermGrade2);
  
  /* Taken midterm third grade */
  printf("Please enter the 3. midterm grade:");
  scanf("%lf",&midtermGrade3);
  
  /* Taken homework first grade */
  printf("Please enter the 1. homework grade:");
  scanf("%lf",&homeworkGrade1);
  
  /* Taken homework second grade */
  printf("Please enter the 2. homework grade:");
  scanf("%lf",&homeworkGrade2);
  
  /* Taken final exam grade */
  printf("Please enter the final exam grade:");
  scanf("%lf",&finalGrade);
  
   midtermTotalGrade= (midtermGrade1 * midtermWeight1/100)+
                      (midtermGrade2 * midtermWeight2/100)+
                      (midtermGrade3 * midtermWeight3/100);
             
   homeworkTotalGrade= (homeworkGrade1 * homeworkWeight1/100)+
                       (homeworkGrade2 * homeworkWeight2/100);
  
  /* Calculated the final total grade */
  
   finalTotalGrade =(finalGrade * finalWeight/100)+midtermTotalGrade+ 
                        homeworkTotalGrade;
  
  printf("Your final grade is: %f \n",finalTotalGrade);
  
  return(0);
}


/********************************************************************/
/*                        end of the part1.c                         */
/********************************************************************/   
        
        
        
        
        











  
