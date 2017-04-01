/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW02_141044067_part2_Gokce_Demir                                */ 
/* hw2-part2.c                                                     */
/* Created on 28/02/2016 by Gokce_Demir                            */ 
/* Description                                                     */ 
/* This program gets the width,height and radius then calculated   */
/* the Circle's,Square's,Rectangle's area and perimeter            */                                                 
/*                                                                 */
/* --------------------------------------------------------------- */







#include <stdio.h>
#define PI 3.14

/*/* Function prototypes */
int areaOfRectangle(int width, int height);
int perimeterOfRectangle(int width, int height);
int areaOfSquare(int edgeLength);
int perimeterOfSquare(int edgeLength);
double areaOfCircle(int radius);
double perimeterOfCircle(int radius);

int main()
{       int width,height,radius,edgeLength;
        int result1,result2,result3,result4;
        double result5,result6;
        
        printf("Please enter the width of the rectangle:");
        scanf("%d",&width);
        
        printf("Please enter the height of the rectangle:");
        scanf("%d",&height);
        
        result1=areaOfRectangle(width,height);
        printf("The area of the rectangle is: %d\n",result1);
        
        
        result2=perimeterOfRectangle(width,height);
        printf("The perimeter of the rectangle is: %d\n",result2);
        
        printf("Please enter the edgeLength of the square:");
        scanf("%d",&edgeLength);
        
        result3=areaOfSquare(edgeLength);
        printf("The area of the square is: %d\n",result3);
        
        
        result4=perimeterOfSquare(edgeLength);
        printf("The perimeter of the square is: %d\n",result4);
        
        printf("Plese enter the radius of the circle:");
        scanf("%d",&radius);
        
        result5=areaOfCircle(radius);
        printf("The area of the circle is: %.2f\n",result5);
        
        result6=perimeterOfCircle(radius);
        printf("The perimeter of the circle is: %.2f\n",result6);
        
        return(0);
}

/*Function definition */
int areaOfRectangle(int width, int height)
{       
        int area;
        area=width*height; /*Calculated the area of rectangle */
        
        return(area);
}
/*Function definition */                        
int perimeterOfRectangle(int width, int height)
{       
        int perimeter;
        perimeter=2*(width+height); /*Calculated the perimeter of rectangle */
        
        return(perimeter);
}
/*Function definition */       
int areaOfSquare(int edgeLength) 
{
        int area;
        area=edgeLength*edgeLength; /*Calculated the area of square */
        
        return(area);        
}
/*Function definition */
int perimeterOfSquare(int edgeLength)
{
        int perimeter;
        perimeter=4*edgeLength; /*Calculated the perimeter of square */
      
        return(perimeter);
}
/*Function definition */
double areaOfCircle(int radius)
{
        double area;
        area=PI*radius*radius; /*Calculated the area of circle */
      
        return(area);
}
/*Function definition */
double perimeterOfCircle(int radius)
{       
        double perimeter;
        perimeter=2*PI*radius; /*Calculated the perimeter of circle */
        
        return(perimeter);
        
}       
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
 
