/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW02_141044067_part1_Gokce_Demir                                */ 
/* hw2-part1.c                                                     */
/* Created on 28/02/2016 by Gokce_Demir                            */ 
/* Description                                                     */ 
/* This program gets the weights and grades then calculated the    */
/* final grade with function.                                      */
/* --------------------------------------------------------------- */

#include <stdio.h>

void calculateLastGrade();  /* Function prototypes */

int main()
{       
        /*Called funtion */
        calculateLastGrade();
        calculateLastGrade();
        calculateLastGrade();
        return(0);
}

void calculateLastGrade()
{       
        /*input- one midterm,one homework and one final exam weight*/
        int midtermWeight,homeworkWeight,finalWeight; 
       
        /*input- one midterm,one homework and one final exam grade */
        double midtermGrade,homeworkGrade,finalGrade;
        
        /*output- final grade */
        double midtermTotalGrade,homeworkTotalGrade,finalTotalGrade;
        
        /*Taken the midterm weight */
        printf("Please enter the 1. midterm weight:");
        scanf("%d",&midtermWeight);
        
        /*Taken the homework weight */
        printf("Please enter the 1. homework weight:");
        scanf("%d",&homeworkWeight);
        
        /*Taken the final exam weight */
        printf("Please enter the final exam weight:");
        scanf("%d",&finalWeight);
        
        /*Taken the 1. midterm grade */
        printf("Please enter the 1.midterm grade:");
        scanf("%lf",&midtermGrade);
        
        /*Taken the 1.homework grade */
        printf("Please enter the 1.homework grade:");
        scanf("%lf",&homeworkGrade);
        
        /*Taken the final exam grade */
        printf("Please enter the final exam grade:");
        scanf("%lf",&finalGrade);
        
        /*Calculated the midterm total grade */
        midtermTotalGrade= (midtermGrade * midtermWeight/100);
        
        /*Calculated the homework total grade */
        homeworkTotalGrade= (homeworkGrade * homeworkWeight/100);
        
        /*Calculated the grade of the student */
        finalTotalGrade =(finalGrade * finalWeight/100)+midtermTotalGrade+ 
                        homeworkTotalGrade;
                        
        printf("Your final grade is: %f \n",finalTotalGrade);
        
}        
        
        
/********************************************************************/
/*                        end of the part1.c                        */
/********************************************************************/   
               
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
           
