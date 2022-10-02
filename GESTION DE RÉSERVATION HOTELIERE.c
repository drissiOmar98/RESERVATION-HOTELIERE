
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//declaration des fonctions

void  add();
void list();
void delete1();
void search();
void edit();


FILE* view;
FILE *f;
FILE* enter;
char admin_entry[20] = {'y'};
char user_entry[20] = {'y'};


struct hotel
{
    char name[20];
    char roomnumber[20];
    char phonenumber[15];
	char nationality[15];
	char period[10];
	char arrivaldate[10];
}h;

int main(){ 

    int a,b,c;

     //Welcome screen

 	printf("\n\n\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*            WELCOME TO HOTEL                   *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n\n\n");

    printf("\n>>>>>>>>>>>>\tFor ADMIN access enter --> 1 \t\t\t<<<<<<<<<<<<");
    printf("\n>>>>>>>>>>>>\tFor USER access enter  --> 2 \t\t\t<<<<<<<<<<<<");
    printf("\n>> ");
     scanf("%d",&a);
     switch(a){
            case 1:{
                char pass[10];
                char filepass[10];
                int i;

                FILE *passw;
                passw = fopen("pass.txt","r");
                printf("\n Hello admin!\n Please enter the password to continue --> ");

                for(i=0; i<6; i++){
                    scanf("%s",pass);
                    fscanf(passw,"%s",filepass);
                    if (strcmp(filepass,pass) == 0) {
                        printf("\n\nAccess granted!\n");
                        fclose(passw);
                        break;
                    }
                    else{
                     printf("\nIncorrect password, please try again.");
                     printf("\nYou have %d trys left ",5-i-1);
                     printf("\n\nEnter password >> ");
                    }
                    if(i==4){
                        fclose(passw);
                        return 0;
                    }

               
                }
                
                while(admin_entry[0] =='y'){
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
	printf("\n               \xba   1-> RESERVER UNE CHAMBRE                   \xba");
	printf("\n               \xba   2-> AFFICHER LES INFORMATIONS DES CLIENTS  \xba");
	printf("\n               \xba   3-> SUPPRIMER UN CLIENT                    \xba");
	printf("\n               \xba   4-> RECHERCHER CHAMBRE DU CLIENT           \xba");
	printf("\n               \xba   5-> MODIFIER                               \xba");
	printf("\n               \xba   6-> CHECKOUT                               \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");

                
                printf(" \n TAPE YOUR CHOICE \n ");
                scanf("%d",&b);
                switch(b){
                	case 1:
				      add();break;
			        case 2:
				      list();break;
			        case 3:
				      delete1();break;
			        case 4:
				       search();break;
			        case 5:
				       edit();break;
			        case 6:
				        system("cls");
						printf("\n\n\t *****THANK YOU*****");
				        printf("\n\t FOR TRUSTING OUR SERVICE");
			       
				     exit(0);
				     break;
		          	default:
				         system("cls");
				         printf("Incorrect Input");
				         printf("\n Press any key to continue");
				         getch();
	           }
		
		        //enter again?
                printf("Would you like to continue? (y/n)\n");
                scanf("%s",admin_entry);

                }
                if(strcmp(admin_entry,"n") == 0){
                    printf("Exiting...\n");
                    printf("\e[1;1H\e[2J");
                    printf("\n >Exited<\n\n");
                    //system("clear");
                    return 0;
                }
                else{
                    printf("Wrong entry!\nExiting...\n");
                    return 0;
                }
                break;
            }
            
            case 2:{
                while(user_entry[0] =='y'){
                printf("\nHello user and welcome to Hotel!");
                printf("\n>>>>>>>>>>>>\tTo view available rooms --> 1 \t\t\t<<<<<<<<<<<<");
   	            printf("\n>>>>>>>>>>>>\tTo request booking of room --> 2 \t<<<<<<<<<<<<");
                printf("\n>> ");
                scanf("%d",&c);
                switch(c){
                  case 1:{
                        FILE* view;
                        view = fopen("rooms.txt","r");
                        printf("Available rooms are:\n");
                        while(fscanf(view,"%s",h.roomnumber) != -1){	
                        printf("%s \n",h.roomnumber);
                        }
                        fclose(view);
                        break;
                    }

                    case 2:{
                        printf("Enter your name: ");
                        scanf("%s",h.name);
                        printf("Enter room to book: ");
                        scanf("%s",h.roomnumber);
                        printf("Enter phonenumber ");
                        scanf("%s",h.phonenumber);
                        printf("Enter nationality: ");
                        scanf("%s",h.nationality);
                        printf("Enter period: ");
                        scanf("%s",h.period);
                        printf("Enter arrivaldate: ");
                        scanf("%s",h.arrivaldate);

                        enter = fopen("bookings.txt","a");

                        fprintf(enter,"%s %s %s %s",h.name,h.roomnumber,h.phonenumber,h.nationality,h.period,h.arrivaldate);
                        fprintf(enter,"\n");

                        printf("Succesfully requested booking\n");
                        fclose(enter);

                    }
                }
                printf("Would you like to continue? (y/n)\n");
                scanf("%s",user_entry);

                }
                if(strcmp(user_entry,"n") == 0){
                    printf("Exiting...\n");
                    printf("\e[1;1H\e[2J");
                    printf("\n >Exited<\n\n");
                    //system("clear");
                    return 0;
                }
                else{
                    printf("Wrong entry!\nExiting...\n");
                    return 0;
                }
                break;
            }
        }
}

void add()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",h.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",h.name);
		printf("Enter Phone Number:\n");
		scanf("%s",h.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",h.nationality);
		
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&h.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&h.arrivaldate);
		fwrite(&h,sizeof(h),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}
void list()
{
	FILE *f;
	
	int i;
	if((f=fopen("add.txt","r"))==NULL ) 
		exit(0);
	system("cls");
	printf("ROOM    ");
	printf("NAME\t ");
	printf("\tPHONENUMBER ");
	printf("\tNATIONALITY ");
	printf("\t\t  PERIOD ");
	printf("\t ARRIVALDATE \n");

	for(i=0;i<100;i++)
		printf("-");
	while(fread(&h,sizeof(h),1,f)==1 ) 
	{
	
		printf("\n%s \t%s \t\t%s \t\t%s \t\t%s  \t\t%s  \t    ",h.roomnumber, h.name  , h.phonenumber ,h.nationality ,h.period,  h.arrivaldate);
	}
	printf("\n");
	for(i=0;i<100;i++)
		printf("-");

	fclose(f);
	getch();
}
void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Room Number of the room to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&h,sizeof(h),1,f)==1)
	{
		if(strcmp(h.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&h,sizeof(h),1,t);
	}
	if(i==1)
	{
		printf("\n\n Records of Customer in this  Room number is not found!!");
		//remove("E:/file.txt");
	   //rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}
void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&h,sizeof(h),1,f)==1)
	{
		if(strcmp(h.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",h.roomnumber);
			printf("\nName:\t%s",h.name);
			printf("\nPhone number:\t%s",h.phonenumber);
			printf("\nNationality:\t%s",h.nationality);	
			printf("\nPeriod:\t%s",h.period);
			printf("\nArrival date:\t%s",h.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}
void edit()
{
	FILE *f;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(h);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%s",roomnumber);
	fflush(stdin);
	while(fread(&h,sizeof(h),1,f)==1)
	{
		if(strcmp(h.roomnumber,roomnumber)==0)
		{
			k=0;
			printf("\nEnter Room Number     :");
			gets(h.roomnumber);
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s",&h.name);
			printf("\nEnter Phone number :");
			scanf("%f",&h.phonenumber);
			printf("\nEnter Nationality :");
			scanf("%s",&h.nationality);
			printf("\nEnter Period :");
			scanf("%h",&h.period);
			printf("\nEnter Arrival date :");
			scanf("%h",&h.arrivaldate);
			fseek(f,size,SEEK_CUR);  //to go to desired position infile
			fwrite(&h,sizeof(h),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();
}
}
                    


