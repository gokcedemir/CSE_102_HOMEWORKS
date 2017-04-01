/* --------------------------------------------------------------- */
/*                                                                 */ 
/* HW010_141044067_Gokce_Demir                                     */ 
/* hw10.c                                                          */
/* 05/05/2016 tarihinde olusturuldu.                               */ 
/* Acıklama :                                                      */ 
/*  Gelen binary bir dosyadan verileri okuma ve bu veriler		   */
/*	arasinda gerekli baglantılar kururarak iliskili sekilde 	   */
/*	txt dosyayına yazdıran program.								   */
/*  Return Degeri: integer bir deger return eder 		  		   */	
/* 																   */                                
/* --------------------------------------------------------------- */



#include <stdio.h>
#include <string.h>

/* global struct prototipleri  */

typedef struct
{
    int id;
    char name[30];
    char surname[30]; 
} students;

typedef struct
{	
    char degree[30];
    int id;
    char name[30];
    char surname[30]; 
} lecturers;

typedef struct
{
    int code; 
    char lectureName[30];
    int id;   
    
} lectures;

typedef struct
{
	char className[30];
	char day[30];
    int startTime;
    int duration;
    int code;
   
} schedules;

typedef struct 
{

	int id;
	int code;
	
} takenStudents;

students student[20];
lecturers lecturer[20];
lectures lecture[20];
schedules schedule[20];
takenStudents takenStu[20];

int main()
{
	int countArr[20]={0};  
    int i, j, k, m,a,size,tem=0;
    int studentNum,lecturerNum,lectureNum,scheduleNum,takenStuNum;
    char temp[30];		/* gunleri tutmak icin olusturulan gecici string */

    FILE *read;
    FILE *write;


    read=fopen("input.dat","rb"); /*binary dosyayi okuma */
    write=fopen("output.txt","w");  /*txt dosyasına yazdirma */	
	
/* Acilmak istenen dosya yok ise veya acilamayacak sekilde ise NULL degerini 
					dondurur.         */
    if(read==NULL)
        printf("Error message!\n");

    else
    {
		/*Binary dosyadan gerekli bilgileri okuma */

        fread(&studentNum,sizeof(int),1,read);
        fread(student,sizeof(students),studentNum,read);
        

        fread(&lecturerNum,sizeof(int),1,read);
        fread(lecturer,sizeof(lecturers),lecturerNum,read);
       

        fread(&lectureNum,sizeof(int),1,read);
        fread(lecture,sizeof(lectures),lectureNum,read);
        

        fread(&scheduleNum,sizeof(int),1,read);
        fread(schedule,sizeof(schedules),scheduleNum,read);
        
   
   		fread(&takenStuNum,sizeof(int),1,read);
        fread(takenStu,sizeof(takenStudents),takenStuNum,read);
        
       
            if(write==NULL)
                printf("Error message!\n");

            else 
            {
	/* binary dosyadan okunan bilgileri "output.txt" dosyasına yazdırma */
                fprintf(write,"Lecture-Lecturer\n");
                for (i = 0; i <takenStuNum ; ++i) 
                {
                    for (j = 0; j<takenStuNum;j++)
                    {
					 /* countArr u hesaplamak icin*/
                       if (takenStu[j].code==lecture[i].code)
                       {
                           countArr[i]++;
                       }                    
                    }
                }
                for(i=0;i<lectureNum;i++)         
                {
                    for(j=0; j<lecturerNum ;j++)
                    {
                        if(lecture[i].id == lecturer[j].id)     
                          fprintf(write,"%s %s %s %d\n",lecture[i].lectureName,
						 lecturer[j].name, lecturer[j].surname, countArr[i]);                            
                    }                    
                }
                fprintf(write,"\n");
                fprintf(write,"Student-Lecture\n");
                for(i=0;i<studentNum;i++)
                {
                    for(j=0;j<studentNum;j++)
                    {   if(student[j].id==takenStu[i].id)
                            countArr[i]++;
                    }
                }
                for (i = 0; i < studentNum; ++i)
                {
                   fprintf(write,"%d %s %s %d \n",student[i].id,student[i].name,
								 student[i].surname,countArr[i]);
                }

                fprintf(write,"\n");
				fprintf(write,"Student-Day\n");
                for(i=0;i<studentNum;i++)
                {
                	strcpy(temp,"");
                	fprintf(write,"%d %s %s ",student[i].id,student[i].name, 
									student[i].surname );
                 	for(j=0;j<takenStuNum;j++)
                 	{	
                 		if(student[i].id==takenStu[j].id)
                 		{
                 			for(k=0; k<scheduleNum; k++)
	                 		{
	                 			if(takenStu[j].code==schedule[k].code)
	                 			{								 							
	                 			  	 strcat(temp,schedule[k].day);
	                 			  	 strcat(temp,",");	
	/* Bir günde birden fazla dersi olan ogrencinin gun sayisini bulma,	
	gun tekrarini kontrol etme */
								  for(m=0;m<strlen(temp);m++)
								  {
									if(strncmp(&temp[m],schedule[k].day,3)==0)
									{
										tem=1;
									}									
									if(tem==0)
									{																	 							
	                 			  	 	strcat(temp,schedule[k].day);
	                 			  	 	strcat(temp,",");
									}
	                 			  }	
	                 	        }
                 		    }
						}
                	}
                	size=strlen(temp);
                	temp[size-1]='\0';
                	fprintf(write,"%s\n",temp );
            	}
                fprintf(write,"\n");           
              }   
       }      

    fclose(read);  /*okuma yaptıgımız "input.dat" dosyasini kapama */
    fclose(write);	/* "output.txt" dosyasini kapama */

    return 0;
}

/********************************************************************/
/*                         hw10.c                         			*/
/********************************************************************/
