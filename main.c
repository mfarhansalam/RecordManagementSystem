#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int ,int );
void menu();
void add();
void view();
void search();


void deleterec();
struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
    char cgpa[20];
};
int main()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               STUDENT RECORD              =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
    menu();
    
    
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
   printf("\n\t\t\                       MAIN MENU                  ");
    gotoxy(10,5);
   printf("\n\t\t\t           ENTER THE NUMBER TO PERFORM TASK                 \n\n");
   
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Delete.");
    gotoxy(10,11);
    printf("5 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;
        
    
    case 4:
        deleterec();
        break;

    case 5:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("data.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y' || another == 'Y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("Enter Name : ");

        gets(std.name);
        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter Matric No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter CGPA : ");
		gets(std.cgpa);
        gotoxy(10,11);
        printf("Enter Course : ");
		gets(std.course);
        gotoxy(10,12);
        printf("Enter Branch : ");
        gets(std.branch);

        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,15);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);

        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,6);
    printf("S.No   Name of Student       Mobile No   MatricNo    CGPA      Course   ");
    gotoxy(10,7);
    printf("---------------------------------------------------------------------------------");
    fp = fopen("data.txt","a+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=9;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-22s%-12s%-12d%-12s%-12s% \n",i,std.name,std.mobile,std.rollno,std.cgpa,std.course,std.branch);
        i++;
        j++;
    }
  
    fclose(fp);
    gotoxy(10,j+4);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("data.txt","a+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0){
            gotoxy(10,8);
            printf("Name : %s",std.name);
            gotoxy(10,9);
            printf("Mobile Number : %s",std.mobile);
            gotoxy(10,10);
            printf("CGPA : %d",std.cgpa);
            gotoxy(10,11);
            printf("Matric No : %d",std.rollno);
            gotoxy(10,12);
            printf("Course : %s",std.course);
            gotoxy(10,13);
            printf("Branch : %s",std.branch);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}

void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("data.txt","a+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("data.txt");
    rename("temp.txt","data.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


