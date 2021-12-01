#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
struct{
	int bid;
	char name[25];
	char location1[25];
	char location2[25];
	char timing[15];
	char date[15];
}bus1;

struct{
	int busno,ID;
	int Maleadult;
	int Femaleadult;
	int children;
	char date[25];
	char time[25];		
}booking1;

struct{
	int sno,busid;
}seat;

char ch[32][100]={'\0'};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0},busno,anumber;
char info[500];

void Add();
void bus();	//for list of bus
void seat_name(int booking,char numstr[100]);
void booking();	//for booking the tickets
int read_bus_seat();	//for reading the number from the file
void read_bus_name();	//for reading the name from the file
void status();	//for printing the status by user input
void bus_seat();//for printing the status while booking ticket
void cancel();
void login();

FILE *busrecord;
FILE *busbooking;
FILE *busseat;
FILE *fp2;
FILE *temp2;

int main()
	{
		login();	
    	int num,i;
    	do
		{
    	system("cls");
    	{
			time_t t;
			time(&t);
			printf("\n\t\t\t\t\tToday Date and Time is %s",ctime(&t));
		}
   		printf("\n============================================ WELCOME TO BUS RESERVATION SYSTEM ========================================");
   		printf("\n\t\t\t\t\t======== WELCOME TO ROYAL TRANSPORT ======== ");
    	printf("\n\t\t\t\t\t-------------------------------------------\n");
		printf("\t\t\t\t\t| S.No | Setup Process                    |\n");
    	printf("\t\t\t\t\t-------------------------------------------\n");
    	printf("\t\t\t\t\t| [1]  | => Add Bus Details		  |\n");
    	printf("\t\t\t\t\t| [2]  | => View Bus Details		  |\n");
    	printf("\t\t\t\t\t| [3]  | => Searching and Booking Ticket  |\n");
    	printf("\t\t\t\t\t| [4]  | => Bus Status Board		  |\n");
    	printf("\t\t\t\t\t| [5]  | => Cancel Booking		  |\n");
    	printf("\t\t\t\t\t| [6]  | => Exit			  |\n");
    	printf("\t\t\t\t\t-------------------------------------------\n");
    	printf("=======================================================================================================================\n\n");
    	printf("\t\t\tEnter Your Choice:: ");
    	scanf("%d",&num);
    	switch(num)
    	{
    		case 1:
        		Add();
        		break;
    		case 2:
        		bus();
        		break;
    		case 3:
        		booking();
        		break;
    		case 4:
        		status();
        		break;
    		case 5:
        		cancel();	
    			break;
    	}
    	getch();
		}
		while(num != 6);
    	printf("\t----------------------------------------------------------------------------------------------------------\n");
    	printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    	printf("\t----------------------------------------------------------------------------------------------------------\n");
    	return 0;
	}

void login()
{
	int a=0,i=0;
   	char uname[10],c=' '; 
   	char pword[10],code[10];
   	char user[10]="user";
   	char pass[10]="pass";
    do
	{
	system("cls");
	printf("\n  =========================  LOGIN FORM  =========================  ");
    printf("\n\t\t==== WELCOME TO ROYAL TRANSPORT ====  ");
    printf("\n\tNOTE : Only Admin / User can Login in this Page.....");
    printf(" \n\n\t\tENTER USERNAME: ");
	scanf("%s", &uname); 
	printf(" \t\tENTER PASSWORD: ");
	while(i<10)
	{
    	pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0; 
	if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
		printf("  \n\n\n\t\t\tWELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
		printf("\n\n\n\t\t\t\tPress any key to continue...");
		getch();//holds the screen
		break;
	}
	else
	{
		printf("\n\n\n\t\t\tSORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();//holds the screen
	}
	}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for three times!!!");
		getch();
	
	}
	else
	{
		system("cls");
	}
}

void Add()
{
    int i;
    busrecord = fopen("busrecord.txt","a+");
    printf("\n\t\tEnter The uniqueid of The Bus (Integer): ");
	scanf("%d",&bus1.bid);
    printf("\t\tEnter Name of the Bus :");
    scanf("%s",bus1.name);
    printf("\t\tEnter the Name of Location 1 :");
    scanf("%s",bus1.location1);
    printf("\t\tEnter the Name of Location 2 :");
    scanf("%s",bus1.location2);
    printf("\t\tEnter Bus Timing :");
    scanf("%s",bus1.timing);
    printf("\t\tEnter Date :");
    scanf("%s",bus1.date);
    
    fprintf(busrecord,"\n%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s",bus1.bid,bus1.name,bus1.location1,bus1.location2,bus1.timing,bus1.date);
    fclose(busrecord);
    printf("\n\t\t (' ' ) A New Bus has been Added Successfully...");
}
void bus()
{
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ==================================================\n\n\n");
    printf("\n*********************************************************************************************************************");
	printf("\n\t\t\t\t\t S.No | Type of Bus Avability in Company |");
	busrecord = fopen("busrecord.txt","a+");
    printf("\n\n\nUnique ID\tName\t\tLocation 1\tLocation 2\t\tTiming\t\tDate",info);
    do
    {
        fgets(info,500,busrecord);
        printf("%s\n",info);
    }while(!feof(busrecord));
    fclose(busrecord);
	printf("\n*********************************************************************************************************************");
	printf("\n\t\tPress any key to continue");
}

void booking()
{
	int Found=0,Found1=0,Found2=0,Target,getid,getid2=0,tempid=0,conti,n,Maleadult, Femaleadult,children,bank_name, payment_name, price, gst=0, total=0,i=0, j,amt=500,totamt,bookedbusno;
	char from[10],stats[3], to[10], Serviceclass[10],date[15], time[10],Y[5],a[20],cvv_number[3],numstr[100];
	system("cls");
	printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering train number
	bus();
    if((busrecord=fopen("busrecord.txt","r"))==NULL)
    {
		printf(" ! The File is Empty...\n\n");
        getch();	
    }
    else
    {
        printf("\n\n\tEnter The Unique ID Of Bus : ");
        scanf("%d",&Target);
        while(!feof(busrecord) && Found==0)
        {
        	fscanf(busrecord,"%d  %s  %s  %s  %s  %s",&bus1.bid,bus1.name,bus1.location1,bus1.location2,bus1.timing,bus1.date);
        	if(bus1.bid == Target)
			{
          		Found=1; 
			}                   
       	}
        if(Found)
        {
        	printf("\n\tThe Unique ID of The Bus:  %d\n\tThe Name of Bus is:  %s\n\tThe 1st Location is:  %s\n\tThe 2nd Location is:  %s\n\tThe Bus Timing is:  %s\n\tThe Journey Date is:%s\n",bus1.bid,bus1.name,bus1.location1,bus1.location2,bus1.timing,bus1.date);      
            busbooking = fopen("busbooking.txt","r");
			printf("\tEnter Bookign ID(User Reference): ");
			scanf("%d",&getid);
			tempid=tempid+getid;
			while(!feof(busbooking) && Found2==0){
				fscanf(busbooking,"%d %d %s %s %d %d %d",&booking1.busno,&booking1.ID,booking1.date,booking1.time,&booking1.Maleadult,&booking1.Femaleadult,&booking1.children);
				if(getid != booking1.ID){
			     	Found2 = 0;
				}
				else{
				Found2 = 1;
		    	}	
		}		
		if(Found2){
				printf("Sorry!!......The Bookinng ID already exists....\nPlease try another ID :");
			     	scanf("%d",&getid2);
			     	tempid = getid2;
		}
		else if(!Found2){
			tempid = tempid;
		}	
		fclose(busbooking);
	
			printf("\tEnter No of Adult Male	: ");
			scanf("%d",&booking1.Maleadult);
			printf("\tEnter No of Adult Female	: ");
			scanf("%d",&booking1.Femaleadult);	
			printf("\tEnter No of Children : ");
			scanf("%d",&booking1.children);
			strcpy(booking1.date,bus1.date);
			strcpy(booking1.time,bus1.timing);
			booking1.busno = Target;
			booking1.ID = tempid;
			busbooking = fopen("busbooking.txt","a+");
			fprintf(busbooking,"\n%d\t%d\t%s\t%s\t%d\t%d\t%d\t",booking1.busno,booking1.ID,booking1.date,booking1.time,booking1.Maleadult,booking1.Femaleadult,booking1.children);
			fclose(busbooking);  
		 	busrecord=fopen("busrecord.txt","r");
     		while(!feof(busrecord) && Found==0)
        	{
        	fscanf(busrecord,"%d  %s  %s  %s  %s  %s", &bus1.bid,bus1.name,bus1.location1,bus1.location2,bus1.timing,bus1.date);
        	    if(bus1.bid == Target)
				{
            		Found=1; 
				}                   
    	    }
        	if(Found)
        	{
        		printf("~---------------------------------------------------~\n");
				printf("| Search And Book Tickets	   		    |\n");
				printf("|---------------------------------------------------|\n");
				printf("| Booking ID : %d                                    \n",booking1.ID);
				printf("| From :         |	%s	         	    \n",bus1.location1);
				printf("| To   :         |	%s		\n",bus1.location2);
				printf("|---------------------------------------------------|\n");
				printf("| Journey Date : |%s	|Time:%s             \n",bus1.date,bus1.timing);
				printf("|---------------------------------------------------|\n");
				printf("| Adult:         | Male/s: %d	      Female/s: %d   |\n",booking1.Maleadult,booking1.Femaleadult);
				printf("| Children:      |                 %d                |\n",booking1.children);
				printf("|---------------------------------------------------|\n");
				printf("Press any key to continue...");
				getch();
			}
				system("cls");
		printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting coach
		
 		FILE *f1, *fopen();//for reading the seats from the user.
 		char str1[80]="32",str2[4],str3[4];
 		int seat1,seat2,booking=0;
 		
 		
 		
 		
 		
 		
 		
 		
		f1 = fopen("tr1.txt","r+");
		fgets(str1,80,f1);
		fclose(f1);	
				
		seat1=atoi(str1);//atoi is a function that converts a string into an integer 
		if(seat1 <= 0)
		{
 			printf("There is no blank seat in this bus ");
		}
		else
		{
			booking = booking1.Maleadult + booking1.Femaleadult + booking1.children;
            printf("Total number of Tickets Booked = %d\n",booking);
			seat1=seat1-booking;
			itoa(busno,numstr,10);
			seat_name(booking,numstr);
			itoa(seat1, str1, 10);
			//for reading the seats from the user.
			f1 = fopen("tr1.txt","w");
			fputs(str1,f1);
			fclose(f1);
		}
		
		
	
		printf("\n\n\n\t\t\t\t\t Bill");
   		printf("\n\t\t*******************************************");
		printf("\n\t\tCost of a ticket is Rs.500");
		totamt = 500*booking;
		printf("\n\t\tEnter the Bank Name : ");
		scanf("%s",&bank_name);
		printf("\n\t\t|*******************************************\n");
		printf("\t\t|Enter the Name of Card Holder: ");
		scanf("%s",&a);
		printf("\t\t|Total Amount : %d",totamt);
		printf("\n\t\t|Enter CVV no:");
		for(j=0;j<2;j++) 
  		{ 
   			cvv_number[j]=getch(); 
  			printf("*");   	 
  		} 
  		cvv_number[j]='\0'; 
		scanf("%d",&cvv_number);
		printf("\t\t|*******************************************\n");
		gst = ((totamt/100)*5);
		total = totamt + gst;
		printf("\n\n\t\t Billing Address Payment Receipt ");
		printf("\n\t\t*******************************************");
		printf("\n\t\t Name		Price		GST		TOTAL ");
		printf("\n\t\t %s		%d		 %d		 %d", a,totamt,gst,total);
		printf("\n\t\t*******************************************\n");
		printf("\n\t\t Thank you! Visit it again ! Have a Safe journey 2021 ! \n");
		printf("\n\t\t\t\t // POWERED BY\n");
		printf("\t\t\t\t ||| BILLDESK Ltd..,\n");
		}
        else if(!Found)
		{
            printf("! There is no such Entry...\n");
		}  
		fclose(busrecord); 
    	}
}   
    
void status()
{
	bus();
	busrecord = fopen("busrecord.txt","r");	
	busbooking = fopen("busbooking.txt","r");
    int i=0,k=0,busno,index=0,j,Target2,tot = 0;
    int tempname[33];
	char A[100];
	char tempstr[10];
  const char EOL = '\n';
  int value;
    printf("Enter the number of bus:---->");
    scanf("%d",&Target2);   
    system("cls");
	printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
	while(!feof(busbooking)){
	fscanf(busbooking,"%d %d %s %s %d %d %d",&booking1.busno,&booking1.ID,booking1.date,booking1.time,&booking1.Maleadult,&booking1.Femaleadult,&booking1.children);
    if(feof(busbooking)){
    	break;
	}
	else{
		if (Target2 == booking1.busno){
		tot = tot + booking1.Maleadult + booking1.Femaleadult + booking1.children;
	}
	}
	
	
	
	}	
	for(k=0;k<=32;k++){
		if(k<=tot){
		tempname[k]= 1;
		}
		else{ 
			tempname[k] = 0;
		}
		
	}

			
	
    for(i=0; i<8; i++)
    {
        printf("\t\t\t");
        for(j=0; j<4; j++)
        {
        	if (tempname[index+1]==1){
        		strcpy(tempstr,"Booked");
			}
			else{
				strcpy(tempstr,"Empty ");
			}
        	printf("%d.%s\t",index+1,tempstr);
        	index++;
        }
            printf("\n");
    }	
		
		
		
	
	
    printf("____________________________________________________________________________________________________________________\n");
    printf("____________________________________________________________________________________________________________________\n");
 
    fclose(busbooking);
    fclose(busrecord);
}

void bus_seat()
{
    int i,index=0,j;
    j=read_bus_seat(bus1.bid);
    read_bus_name(bus1.bid);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
    	strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
       	printf("\t\t\t\t");
       	for(j=0; j<4; j++)
        {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
       	}
        printf("\n");
	}
}

void cancel()
{
 	int seat_no,i,j,tot1,totcancel,Found,Target4;
 	char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 	printf("\n\t\t\tEnter Booking ID :");
 	scanf("%d",&Target4);
 	fp2=fopen("fp2.txt","w");
    if((temp2=fopen("busbooking.txt","r"))==NULL)
    { 
		printf(" ! The file is empty...\n\n");
		getch();
	}
    else
    {
        while(!feof(temp2))
        {
            fscanf(temp2,"%d %d %s %s %d %d %d",&booking1.busno,&booking1.ID,booking1.date,booking1.time,&booking1.Maleadult,&booking1.Femaleadult,&booking1.children);
            if(Target4==booking1.ID)
			{
              	Found=1;
			}
			else
			{
				Found=0;
			}
            if(Found)
            {
                tot1 = booking1.Maleadult + booking1.Femaleadult + booking1.children;
                printf("\n\t\t\tNumber of Tickets Booked : %d",tot1);
                printf("\n\t\t\tEnter the Number of Tickets to be Cancelled : " );
                scanf("%d",&totcancel);
                for (i=0;i<totcancel;i++)
				{                      
				    if(booking1.children>0)
					{
                      	booking1.children--;
					}
					else
					{
						if(booking1.Femaleadult>0)
						{
							booking1.Femaleadult--;
						}
						else
						{
							booking1.Maleadult--;
						}	
					}
				}
                fprintf(fp2,"\n%d\t%d\t%s\t%s\t%d\t%d\t%d\t",booking1.busno,booking1.ID,booking1.date,booking1.time,booking1.Maleadult,booking1.Femaleadult,booking1.children);
                break;
			}
            else if(!Found)
			{
                fprintf(fp2,"\n%d\t%d\t%s\t%s\t%d\t%d\t%d\t",booking1.busno,booking1.ID,booking1.date,booking1.time,booking1.Maleadult,booking1.Femaleadult,booking1.children);
			}
            if(feof(temp2))
			{
				break;
            }
        }
        fclose(temp2);
        fclose(fp2);
        fclose(busbooking);
        remove("busbooking.txt");
        rename("fp2.txt","busbooking.txt");
 	printf("\n======================================================================================================\n");
 	printf("\t\t\t\tRupees %d has been Returned\t\t\t\n",500*totcancel);
    printf("======================================================================================================\n");
}
}
void seat_name(int booking,char numstr[100])
{
	char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
	int number,target,Found=0,i=0;
    FILE *a,*b;
   	strcat(numstr,".txt");
   	strcat(tempstr1,numstr);
   	strcat(tempstr2,numstr);
   	busseat = fopen("busseat.txt","a+");
   	a = fopen(tempstr1,"a");//for open the file to write the name in the file
   	b = fopen(tempstr2,"a");//for open the file for writing the number in the file
   	printf("\nThe uniqueid of The Bus (Integer)is:%d",bus1.bid );        
    seat.busid =bus1.bid;   
    busseat = fopen("busseat.txt","a+");
	fprintf(busseat,"\n%d",seat.busid) ;   
	for(i=0; i<booking; i++)
	{
		itoa(number, tempstr, 10);
      	fprintf(a,"%s ",name[number-1]);
      	fprintf(b,"%s ",tempstr);
	}
	fclose(busseat);
	fclose(a);
	fclose(b);
}

int read_bus_seat()//for putting the numeric value in the array
{
	char tempstr[100],tempstr2[12]="number";
	FILE *a,*b;
	char numstr[100];
	int i=0,j=0,k;
	itoa(bus1.bid,numstr,10);
	strcat(numstr,".txt");
	strcat(tempstr2,numstr);
	a = fopen(tempstr2,"a+");//for open the file to write the name in the file
   	while(!feof(a))//The C busrary function int feof(FILE *stream) tests the end-of-file indicator for the given stream.
   	{
    	number[i][j] = fgetc(a);
		if(number[i][j] == ' ')
      	{
        	j=0;
        	i++;
		}
		else
		{
      		j++;
		}
   }
   k=i;
   for(i=0;i<k;i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}

void read_bus_name()//for putting the numeric value in the array
{
	fopen("busrecord","a+");
	char tempstr1[12]="status";
	FILE *b;
	char numstr[100];
	int i=0,j=0,k=0;
	itoa(bus1.bid,numstr,10);
	strcat(numstr,".txt");
	strcat(tempstr1,numstr);
	b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   	while(!feof(b))//The C library function int feof(FILE *stream) tests the end-of-file indicator for the given stream.
   	{	
		name[i][j] = fgetc(b);
		if(name[i][j] == ' ')
      	{
        	j=0;
          	i++;
        }
		else
		{
        	j++;
		}
	}
   	name[i][j]='\0';
   	k=i;
   	fclose(b);
}




