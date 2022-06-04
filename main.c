#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

int valid = 0;
int chance = 3;
void title();
void gotoxy(int,int);
void login();
void signup();
void add_record();
void display_record();
void search_record();
void setcolor(int);
void back_frame(int x,int x1,int y, int y1,int bottomLineshadow_color,int topLineShadow_color,int line_color);
void main_menu_background();
void working_area_background();
void menu_option();
void edit_record();
void about();
void make_frame(int x,int x1,int y,int y1);

struct patient
{

    char gender;
    char age[5];
    char first_name[20];
    char last_name[10];
    char contact[12];
    char address[10];
    char email[15];
    char doctor_first_name[12];
    char doctor_last_name[8];
    char problem[10];
}patient,temp;


enum bool
{
    false,true
};


struct user
{

    char name[9];
    char pass[6];
};

int main()
{
    login();
    int x,x1,y,y1,x2,y2;
    char ch;
    menu:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),180|7);
    main_menu_background();
    working_area_background();
    back_frame(2,38,3,5,117,180,12);
    back_frame(40,109,3,5,117,180,12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252|4);
    gotoxy(17,4);
    printf("OPTIONS");
    x=3;
    x1=38;
    y=6;
    x2=6;
    reset:
        y1=y+2;
        y2=y+1;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117|1);
        if(x==3)
        {
            gotoxy(13,7);
            printf("Add Record");
            gotoxy(13,10);
            printf("Display Record");
            gotoxy(13,13);
            printf("Search Record");
            gotoxy(13,16);
            printf("Edit Record");
            gotoxy(13,19);
            printf("About");
            gotoxy(13,22);
            printf("Exit");
            setcolor(14);
            menu_option(x,x1,y,y1);
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225|9);
            if(y+1==7 && x==3)
            {
                gotoxy(13,7);
                printf("Add Record");
            }
            if(y+1==10 && x==3)
            {
                gotoxy(13,10);
                printf("Display Record");
            }
            if(y+1==13 && x==3)
            {
                gotoxy(13,13);
                printf("Search Record");
            }
            if(y+1==16 && x==3)
            {
                gotoxy(12,16);
                printf("Edit Record");
            }
            if(y+1==19 && x==3)
            {
                gotoxy(12,19);
                printf("About");
            }
            if(y+1==22 && x==3)
            {
                gotoxy(12,22);
                printf("Exit");
            }
        }
        gotoxy(x2,y2);
        printf("%c",249);
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117|14);
        rechoise:
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117|14);
        gotoxy(56,4);
        ch=getch();
        if(ch==-32)
        {
             ch=getch();

              if(ch==72 || ch==80)
                {
                   switch(ch)
                   {
                      case 72:
                      if(y>6 && y<=21)
                     {
                         gotoxy(x2,y2);
                         printf("%c",256);
                         setcolor(7);
                         menu_option(x,x1,y,y1);
                         y=y-3;
                         goto reset;
                     }
                     goto rechoise;
                     case 80:
                       if(y>=6 && y<21)
                     {
                         gotoxy(x2,y2);
                         printf("%c",256);
                         setcolor(7);
                         menu_option(x,x1,y,y1);
                         y=y+3;
                         goto reset;
                     }
                     goto rechoise;
                }
            }

        else
        {
            goto reset;
        }
    }


    else if(ch==13)
    {

        switch(y+1)
        {

        case 7:
               add_record();
               goto menu;
               break;


        case 10:
                 display_record();
                 getch();
                 system("cls");
                 system("COLOR ec");
                 goto menu;
                 break;


        case 13:
                  search_record();
                  goto menu;
                  break;


        case 16:
                   edit_record();
                   system("cls");
                   system("COLOR ec");
                   goto menu;
                   break;


        case 19:
                  about();
                  getch();
                  goto menu;
                  break;


        case 22:
                  exit(0);
                  break;
        }
    }
    getch();
 }



void login()
{

    Retry :
    back_frame(1,118,1,3,28,180,1);
    back_frame(1,118,28,30,28,180,1);
    char ch;
    char username[9];
    char password[6];
    system("COLOR ec");
    setcolor(8);
    make_frame(30,100,10,25);
    gotoxy(50,15);
    printf(" Enter Username     :   ");
    gotoxy(50,18);
    printf(" Enter Password     :   ");
    gotoxy(74,15);
    scanf("%s",username);
    gotoxy(74,18);
    scanf("%s",password);

    struct user temp;
    enum bool status;
    status=false;

    int i=5,flag;

    FILE *fp;
    fp=fopen("password.txt","rb+");
      if(fp==NULL)
           {
              printf("File not found\n");
              exit(1);
           }

            while(fread(&temp, sizeof( struct user),1,fp))
    {
      if(!(strcmp(username,temp.name) ) &&!(strcmp(password,temp.pass)))
        {
            system("cls");
        }

        else
        {
            system("cls");
            chance--;
            if(chance>0)
              {
                  make_frame(30,100,10,18);
                  gotoxy(40,14);
                  printf("Username And Password is Incorrect.");
                  gotoxy(40,16);
                  printf("%d Attempts are left\n",chance);
                  getch();
                  system("cls");
                  goto Retry;
              }
             system("cls");
             system("COLOR ec");
             make_frame(30,100,10,18);
             setcolor(25);
             gotoxy(35,14);
             printf("You have exceeded your attempts\n\n");
             gotoxy(35,16);
             printf(" Press Y or y in case you have forgot password\n");
             fflush(stdin);
             ch=getch();
             if(ch=='Y'  ||  ch=='y')
               {
                 char pet[20];
                 char check[20];
                 system("cls");
                 make_frame(30,100,10,19);
                 gotoxy(35,13);
                 printf("Answer your security question");
                 gotoxy(35,15);
                 printf("Enter your pet name");
                 gotoxy(35,18);
                 scanf("%s",&pet);

                fp=fopen("security.txt","r");
                 if(fp==NULL)
                  {
                      system("cls");
                      make_frame(30,100,10,17);
                      gotoxy(40,13);
                      printf("File not Found");
                      exit(1);
                  }
                fread(&check,sizeof(check),1,fp);
                if(!strcmp(pet,check))
                signup();
                else
                {
                system("cls");
                make_frame(30,100,10,16);
                gotoxy(40,12);
                printf("Security answer is wrong");
                gotoxy(40,14);
                printf("You cannot change your password");
                getch();
                exit(0);

               }
            }
          }
        }
    fclose(fp);
    system("cls");
}

void signup()
{

    FILE *fp;
    system("cls");
    make_frame(30,100,10,18);
    gotoxy(40,13);
    printf("Username can be maximum of 9 characters");
    gotoxy(40,15);
    printf("Password can be maximum of 6 characters");
    getch();
    system("cls");
    back_frame(1,118,1,3,28,180,1);
    back_frame(1,118,28,30,28,180,1);
    system("COLOR ec");
    setcolor(8);
    make_frame(30,100,10,25);
    gotoxy(10,5);
    printf("\nSetting up with new username or password\n");
    struct user temp;
    gotoxy(50,15);
    printf("Set your username    :   ");
    gotoxy(50,18);
    printf("Set your Password    :   ");
    gotoxy(75,15);
    scanf("%s",&temp.name);
    gotoxy(75,18);
    scanf("%s",&temp.pass);

   fp=fopen("password.txt","wb+");
    if(fp==NULL)
     {
        printf("File not Found\n");
        exit(1);
     }

   fwrite(&temp,sizeof(temp),1,fp);
   fclose(fp);
   system("cls");
   make_frame(30,100,10,18);
   gotoxy(35,13);
   printf("Account  password updated Successfully");
   gotoxy(35,15);
   printf("Any key to continue............");
   getch();
   system("cls");
}

void add_record()
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),90|7);
 char ch;
 int i,j;
 FILE *fp;
 fp=fopen("record.txt","a");
 gotoxy(40,6);
 printf("NAME               :");
 gotoxy(40,8);
 printf("SURNAME            :");
 gotoxy(40,10);
 printf("GENDER             :");
 gotoxy(40,12);
 printf("AGE                :");
 gotoxy(40,14);
 printf("MOBILE             :");
 gotoxy(40,16);
 printf("E-MAIL             :");
 gotoxy(40,18);
 printf("ADDRESS            :");
 gotoxy(40,20);
 printf("PROBLEM            :");
 gotoxy(40,22);
 printf("DOCTOR NAME        :");
 gotoxy(40,24);
 printf("DOCTOR SURNAME     :");






                gotoxy(65,6);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,8);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,10);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,12);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,14);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,16);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,18);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,20);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,22);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,24);
                for(j=0;j<30;j++)
                printf("%c",32);




 A:
 gotoxy(40,6);
 printf("NAME               :");
 gotoxy(68,6);
 scanf("%s",&patient.first_name);
 patient.first_name[0]=toupper(patient.first_name[0]);
 for(i=0;i<strlen(patient.first_name);i++)
 {
   if(!isalpha(patient.first_name[i]))
     {
        gotoxy(68,6);
        for(i=0;i<strlen(patient.first_name);i++)
        printf("%c",32);
        goto A;
     }
 }

 B:


 gotoxy(40,8);
 printf("SURNAME            :");
 gotoxy(68,8);
 scanf("%s",&patient.last_name);
 patient.last_name[0]=toupper(patient.last_name[0]);
 for(i=0;i<strlen(patient.last_name);i++)
 {

     if(!isalpha(patient.last_name[i]))
     {
         gotoxy(68,8);
         for(i=0;i<strlen(patient.last_name);i++)
         printf("%c",32);
         goto B;
     }
 }


 C:

       gotoxy(40,10);
       printf("GENDER             :");
       gotoxy(68,10);
       fflush(stdin);
       scanf("%c",&patient.gender);
         if(!(toupper(patient.gender)=='M'  ||  toupper(patient.gender)=='F'))
           {
               gotoxy(68,10);
               for(i=0;i<5;i++)
               printf("%c",32);
               goto C;

          }


 D:

     gotoxy(40,12);
     printf("AGE                :");
     gotoxy(68,12);
     scanf("%s",&patient.age);
     for(i=0;i<strlen(patient.age);i++)
     {
         if(!isdigit(patient.age[0]))
         {

             gotoxy(68,12);
             for(i=0;i<strlen(patient.age);i++)
             printf("%c",32);
             goto D;

         }

     }



 E:



     gotoxy(40,14);
     printf("MOBILE             :");
     gotoxy(68,14);
     scanf("%s",&patient.contact);
     if(strlen(patient.contact)==10)
     {
          for(i=0;i<strlen(patient.contact);i++)
          {
              if(!isdigit(patient.contact[i]))
              {
                 gotoxy(68,14);
                 for(i=0;i<strlen(patient.contact);i++)
                 printf("%c",32);
                 goto E;
              }
          }
     }
     else
     {
         gotoxy(68,14);
         for(i=0;i<strlen(patient.contact);i++)
         printf("%c",32);
         goto E;
     }



     gotoxy(40,16);
     printf("E-MAIL             :");
     gotoxy(68,16);
     fflush(stdin);
     gets(patient.email);



     gotoxy(40,18);
     printf("ADDRESS            :");
     gotoxy(68,18);
     fflush(stdin);
     gets(patient.address);
     patient.address[0]= toupper(patient.address[0]);


     gotoxy(40,20);
     printf("PROBLEM            :");
     gotoxy(68,20);
     fflush(stdin);
     gets(patient.problem);
     patient.problem[0]=toupper(patient.problem[0]);




   F:


        gotoxy(40,22);
        printf("DOCTOR NAME        :");
        gotoxy(68,22);
        scanf("%s",&patient.doctor_first_name);
        patient.doctor_first_name[0]=toupper(patient.doctor_first_name[0]);
        for(i=0;i<strlen(patient.doctor_first_name);i++)
              {

                 if(!isalpha(patient.doctor_first_name[i]))
                       {
                           gotoxy(68,22);
                           for(i=0;i<strlen(patient.first_name);i++)
                           printf("%c",32);
                           goto F;
                       }
              }


 G:

        gotoxy(40,24);
        printf("DOCTOR SURNAME     :");
        gotoxy(68,24);
        scanf("%s",&patient.doctor_last_name);
        patient.doctor_last_name[0]=toupper(patient.doctor_last_name[0]);
        for(i=0;i<strlen(patient.doctor_last_name);i++)
              {

                 if(!isalpha(patient.doctor_last_name[i]))
                       {
                           gotoxy(68,24);
                           for(i=0;i<strlen(patient.first_name);i++)
                           printf("%c",32);
                           goto G;
                       }
              }


       fprintf(fp," %s %s %c %s %s %s %s %s %s %s\n",patient.first_name,patient.last_name,patient.gender,patient.age,patient.address,patient.contact,patient.email,patient.problem,patient.doctor_first_name,patient.doctor_last_name);
       gotoxy(40,27);
       printf("....................Record inserted successfully......................");
       getch();
       fclose(fp);
       gotoxy(42,30);
       printf("If wanted to add more patient details");
       gotoxy(42,31);
       printf("Press Y or y");
       fflush(stdin);
       ch=getch();
       if(toupper(ch)=='Y')
       {


         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),180|7);
         working_area_background();

         back_frame(2,38,3,5,117,180,12);
         back_frame(40,109,3,5,117,180,12);
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252|4);
         gotoxy(17,4);
         printf("OPTIONS");
         add_record();
       }
       else
       {
           gotoxy(45,32);
           printf("Thank You");
           getch();
       }

}


void gotoxy(int x,int y)
{
 COORD c;
 c.X=x;
 c.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


void display_record()
{
    system("cls");
    int row;
    system("COLOR 12");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),28|15);
    title();
    FILE *ek;
    ek=fopen("record.txt","r");
    gotoxy(1,15);
    printf("FULL NAME");
    gotoxy(30,15);
    printf("Gender");
    gotoxy(42,15);
    printf("Age");
    gotoxy(48,15);
    printf("Address");
    gotoxy(75,15);
    printf("contact");
    gotoxy(90,15);
    printf("Email");
    printf("\n========================================================================================================================\n");
    row=19;
    struct patient patient={0};

   while(fscanf(ek,"%s %s %c %s %s %s %s %s %s %s\n",patient.first_name,patient.last_name,&patient.gender,patient.age,patient.address,patient.contact,patient.email,patient.problem,patient.doctor_first_name,patient.doctor_last_name)!=EOF)
  {
    {
    gotoxy(1,row);
    printf("%s %s",patient.first_name,patient.last_name);
    gotoxy(30,row);
    printf("%c",patient.gender);
    gotoxy(42,row);
    printf("%s",patient.age);
    gotoxy(48,row);
    printf("%s",patient.address);
    gotoxy(75,row);
    printf("%s",patient.contact);
    gotoxy(90,row);
    printf("%s",patient.email);
    row++;

   }
 }
    fclose(ek);
    getch();
}


void title()
{
        printf("\n------------------------------------------------------------------------------------------------------------------------");
        printf("\n-----------------------------------------------CITY HOSPITAL------------------------------------------------------------");
        printf("\n------------------------------------------------------------------------------------------------------------------------");

}


void search_record()
{

    char ch;
    char name[20];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),180|7);
    working_area_background();
    back_frame(40,109,3,5,117,180,12);
    FILE *ek;
    ek=fopen("record.txt","r");
    gotoxy(40,6);
    printf("PATIENT NAME     :");
    gotoxy(60,6);
    scanf("%s",&name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    while(fscanf(ek,"%s %s %c %s %s %s %s %s %s %s\n",patient.first_name,patient.last_name,&patient.gender,patient.age,patient.address,patient.contact,patient.email,patient.problem,patient.doctor_first_name,patient.doctor_last_name)!=EOF)
    {

       if(strcmp(patient.first_name,name)==0)
        {
     printf("\n\n\n\n");
     gotoxy(40,10);
     printf("FULL NAME         :");
     gotoxy(60,10);
     printf("%s %s",patient.first_name,patient.last_name);
     gotoxy(40,11);
     printf("GENDER            : ");
     gotoxy(60,11);
     printf("%c",patient.gender);
     gotoxy(40,12);
     printf("AGE               :");
     gotoxy(60,12);
     printf("%s",patient.age);
     gotoxy(40,13);
     printf("ADDRESS           :");
     gotoxy(60,13);
     printf("%s",patient.address);
     gotoxy(40,14);
     printf("CONTACT           :");
     gotoxy(60,14);
     printf("%s",patient.contact);
     gotoxy(40,15);
     printf("EMAIL             :");
     gotoxy(60,15);
     printf("%s",patient.email);
     gotoxy(40,16);
     printf("PROBLEM           :");
     gotoxy(60,16);
     printf("%s",patient.problem);
     gotoxy(40,17);
     printf("PRESCRIBED DOCTOR :");
     gotoxy(60,17);
     printf("%s %s",patient.doctor_first_name,patient.doctor_last_name);
     fclose(ek);
     break;
    }
 }


 if(strcmp(patient.first_name,name)!=0)
 {
   gotoxy(40,10);
   printf("RECORD NOT FOUND\n");
   getch();
 }
 fclose(ek);

 gotoxy(40,22);
 printf("Do you want to search for other record");
 gotoxy(40,23);
 printf("Press Y or y  :");
 fflush(stdin);
 gotoxy(60,23);
 ch=getch();

 if(ch=='Y' || ch=='y')
 {
  search_record();
 }
 else
 {
     gotoxy(40,25);
   printf("-----------------------THANK YOU-----------------------");
   return;
 }
 }



 void edit_record()
{
    FILE *ek,*ft;
    int i,b,j;
    char ch;
    char name[20];
    Try :
    system("cls");
    ft=fopen("temp.txt","w+");
    ek=fopen("record.txt","r");

    if(ek==NULL)
    {
        printf("File Not Found\n");
        getch();
        return;
    }
    setcolor(4);
    gotoxy(15,4);
    printf("!!!!!!!!!!!!!Edit Patient Record!!!!!!!!!!!!!!!!!");
    gotoxy(12,7);
    printf("Enter the first name of the patient to be edited");;
    gotoxy(5,10);
    printf("NAME            :");
    gotoxy(23,10);
    scanf("%s",&name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(25,15);
    if(ft==NULL)
    {
        printf("File Cannot Open");
        getch();
        return;
    }

    system("cls");
    system("COLOR 28");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),180|7);
    main_menu_background();
    working_area_background();
    back_frame(2,38,3,5,117,180,12);
    back_frame(40,109,3,5,117,180,12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252|68);

     while(fscanf(ek,"%s %s %c %s %s %s %s %s %s %s\n",patient.first_name,patient.last_name,&patient.gender,patient.age,patient.address,patient.contact,patient.email,patient.problem,patient.doctor_first_name,patient.doctor_last_name)!=EOF)
    {

       if(strcmp(patient.first_name,name)==0)
        {
          valid=1;
          printf("\n\n\n\n");
          gotoxy(4,7);
          printf("FULL NAME         :");
          gotoxy(4,8);
          printf("%s %s",patient.first_name,patient.last_name);
          gotoxy(4,10);
          printf("GENDER            : ");
          gotoxy(4,11);
          printf("%c",patient.gender);
          gotoxy(4,13);
          printf("AGE               :");
          gotoxy(4,14);
          printf("%s",patient.age);
          gotoxy(4,16);
          printf("ADDRESS           :");
          gotoxy(4,17);
          printf("%s",patient.address);
          gotoxy(4,19);
          printf("CONTACT           :");
          gotoxy(4,20);
          printf("%s",patient.contact);
          gotoxy(4,22);
          printf("EMAIL             :");
          gotoxy(4,23);
          printf("%s",patient.email);
          gotoxy(4,25);
          printf("PROBLEM           :");
          gotoxy(4,26);
          printf("%s",patient.problem);
          gotoxy(4,28);
          printf("PRESCRIBED DOCTOR :");
          gotoxy(4,29);
          printf("%s %s",patient.doctor_first_name,patient.doctor_last_name);


                gotoxy(40,7);
                printf("NAME              :");
                gotoxy(40,9);
                printf("SURNAME           :");
                gotoxy(40,11);
                printf("GENDER            : ");
                gotoxy(40,13);
                printf("AGE               :");
                gotoxy(40,15);
                printf("ADDRESS           :");
                gotoxy(40,17);
                printf("CONTACT           :");
                gotoxy(40,19);
                printf("EMAIL             :");
                gotoxy(40,21);
                printf("PROBLEM           :");
                gotoxy(40,23);
                printf("PRESCRIBED DOCTOR :");




                gotoxy(65,7);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,9);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,11);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,13);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,15);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,17);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,19);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,21);
                for(j=0;j<30;j++)
                printf("%c",32);
                gotoxy(65,23);
                for(j=0;j<30;j++)
                printf("%c",32);


 A:
 gotoxy(65,7);
 scanf("%s",&patient.first_name);
 patient.first_name[0]=toupper(patient.first_name[0]);
 for(i=0;i<strlen(patient.first_name);i++)
 {
   if(!isalpha(patient.first_name[i]))
     {
        gotoxy(65,7);
        for(i=0;i<strlen(patient.first_name);i++)
        printf("%c",32);
        goto A;
     }
 }

 B:


 gotoxy(65,9);
 scanf("%s",&patient.last_name);
 patient.last_name[0]=toupper(patient.last_name[0]);
 for(i=0;i<strlen(patient.last_name);i++)
 {

     if(!isalpha(patient.last_name[i]))
     {
        gotoxy(65,9);
        for(i=0;i<strlen(patient.last_name);i++)
        printf("%c",32);
        goto B;
     }
 }


 C:

       gotoxy(65,11);
       fflush(stdin);
       scanf("%c",&patient.gender);
         if(!(toupper(patient.gender)=='M'  ||  toupper(patient.gender)=='F'))
           {
               gotoxy(65,11);
               for(i=0;i<5;i++)
               printf("%c",32);
               goto C;

          }


 D:

     gotoxy(65,13);
     scanf("%s",&patient.age);
     for(i=0;i<strlen(patient.age);i++)
     {
         if(!isdigit(patient.age[0]))
         {
             gotoxy(65,13);
             for(i=0;i<strlen(patient.age);i++)
             printf("%c",32);
             goto D;

         }

     }





     gotoxy(65,15);
     fflush(stdin);
     gets(patient.address);
     patient.address[0]= toupper(patient.address[0]);




 E:



     gotoxy(65,17);
     scanf("%s",&patient.contact);
     if(strlen(patient.contact)==10)
     {
          for(i=0;i<strlen(patient.contact);i++)
          {
              if(!isdigit(patient.contact[i]))
              {
                  gotoxy(65,17);
                  for(i=0;i<strlen(patient.contact);i++)
                  printf("%c",32);
                  goto E;
              }
          }
     }
     else
     {
         gotoxy(65,17);
         for(i=0;i<strlen(patient.contact);i++)
         printf("%c",32);
         goto E;
     }



     gotoxy(65,19);
     fflush(stdin);
     gets(patient.email);



     gotoxy(65,21);
     fflush(stdin);
     gets(patient.problem);
     patient.problem[0]=toupper(patient.problem[0]);







   F:


        gotoxy(65,23);
        scanf("%s",&patient.doctor_first_name);
        patient.doctor_first_name[0]=toupper(patient.doctor_first_name[0]);
        for(i=0;i<strlen(patient.doctor_first_name);i++)
              {

                 if(!isalpha(patient.doctor_first_name[i]))
                       {
                           gotoxy(65,23);
                           for(i=0;i<strlen(patient.doctor_first_name);i++)
                           printf("%c",32);
                           goto F;
                       }
              }



 G:
        scanf("%s",&patient.doctor_last_name);
        patient.doctor_last_name[0]=toupper(patient.doctor_last_name[0]);
        for(i=0;i<strlen(patient.doctor_last_name);i++)
              {

                 if(!isalpha(patient.doctor_last_name[i]))
                       {
                           for(i=0;i<strlen(patient.doctor_last_name);i++)
                           printf("%c",32);
                           goto F;
                       }
              }


     gotoxy(45,25);
     printf("Enter U to complete updation process :");
     fflush(stdin);
     ch=getch();
     if(ch=='u'  ||  ch=='U')
     {
       fprintf(ft," %s %s %c %s %s %s %s %s %s %s\n",patient.first_name,patient.last_name,patient.gender,patient.age,patient.address,patient.contact,patient.email,patient.problem,patient.doctor_first_name,patient.doctor_last_name);
       gotoxy(45,27);
       printf("Record updated successfully");

     }
  }

  else
  {

       fprintf(ft," %s %s %c %s %s %s %s %s %s %s\n",patient.first_name,patient.last_name,patient.gender,patient.age,patient.address,patient.contact,patient.email,patient.problem,patient.doctor_first_name,patient.doctor_last_name);
  }

}

if(!valid)
{

    char ch;
    system("cls");
    make_frame(30,100,10,19);
    gotoxy(50,13);
    printf("No Record Found\n");
    gotoxy(50,15);
    printf("Do you want to try again");
    gotoxy(50,16);
    printf("Press Y or y");
    gotoxy(50,17);
    fflush(stdin);
    ch=getch();

    if(ch == 'y' ||  ch=='Y')
    {
     goto Try;
    }
    system("cls");

}

fclose(ft);
fclose(ek);
remove("record.txt");
rename("temp.txt","record.txt");
getch();
}



void a_alpha(int x,int y)
{
     setcolor(28);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c        %c%c",219,219,219,219);
    gotoxy(x,y+2);
    printf("%c%c        %c%c",219,219,219,219);
    gotoxy(x,y+3);
    printf("%c%c        %c%c",219,219,219,219);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+5);
    printf("%c%c        %c%c",219,219,219,219);
    gotoxy(x,y+6);
    printf("%c%c        %c%c",219,219,219,219);
    gotoxy(x,y+7);
    printf("%c%c        %c%c",219,219,219,219);
    gotoxy(x,y+8);
    printf("%c%c        %c%c",219,219,219,219);
    gotoxy(x,y+9);
}


void make_frame(int x,int x1,int y,int y1)
{
    int i;
    y--;
    for(i=x;i<=x1;i++)
    {
        gotoxy(i,y);
        printf("%c",220);
        gotoxy(i,y1);
        printf("%c",220);
    }
    y++;
    for(i=y;i<=y1;i++)
    {
        gotoxy(x,i);
        printf("%c",219);
        gotoxy(x1,i);
        printf("%c",219);
    }
}



void back_frame(int x,int x1,int y, int y1,int bottomLineshadow_color,int topLineShadow_color,int line_color)
{
    int i;
    for(i=x;i<=x1;i++)
    {
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),topLineShadow_color|line_color);
        gotoxy(i,y);
        printf("%c",220);
        gotoxy(i,y+1);
        printf("%c",219);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),bottomLineshadow_color|line_color);
        gotoxy(i,y1);
        printf("%c",4);
    }
}

void working_area_background()
{
    gotoxy(40,6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,21);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,22);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,23);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,25);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,26);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,27);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,29);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,30);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,31);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,32);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,33);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,34);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,35);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,36);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,37);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,38);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,39);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}


void main_menu_background()
{
    gotoxy(2,6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,21);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,22);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,23);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,25);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,26);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,27);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,29);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,30);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,31);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,32);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,33);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,34);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,35);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,36);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,37);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,38);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,39);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

}


void menu_option(int x,int x1,int y,int y1)
{
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
}



void about()
{
    a_alpha(60,7);
    gotoxy(45,18);
    printf("This software is build in C language by Abhishek Verma");
    gotoxy(45,20);
    printf("Designed to managed hospital management record such as:");
    gotoxy(45,22);
    printf("Adding the records");
    gotoxy(45,24);
    printf("Displaying the records");
    gotoxy(45,26);
    printf("Searching the records");
    gotoxy(45,28);
    printf("Editing the records");
}



void setcolor(int ForgC)
{


    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
    wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut,wColor);
    }
}




 /*

        --------------------------------
         Color Code Of Background Color
        --------------------------------
            Black 			-- 	0
            Navy Blue  		-- 	28
            Green 			--	34
            Teal			--	49
            Maroon			--	68
            Purple			--	82
            Olive			--	100
            Silver, Grey	--	117
            Dark Grey		--	128
            Blue			--	147
            Light Green		--	162
            Cyan			--	180
            Red				--	197
            Magenta			--	210
            Yellow			--	225
            White			--	252

*/
