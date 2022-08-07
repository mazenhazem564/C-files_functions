#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MaxSize 100

void simplefilewrite()
{
    FILE* fp; //pointer points in your drive (insiide your harddisk)
    fp=fopen("test.txt","w+");//fopen:  take the name of the desired file you want to open
                              //w+: to write in the file and read from it
    if (fp==NULL)
        printf("NO FILE exists");
    fprintf(fp,"Mazen Hazem\n");
    fputs("Fathallah ahmed\n",fp);//fputs: f=file,put=put in this file,s= a string

    fputs("is coding here\n",fp);

    //fp=fopen("test.txt","r"); //to read from a file
    fclose(fp);//to close the file and don't still have pointer opened in memory
}
void simplefileread()
{
    FILE* fp;
    char buffer[MaxSize];

    fp = fopen("test.txt","r"); //w+ = read and write , w=write only , r=read only
    /*fscanf(fp,"%s",buffer);//this line means you will read from file fp a string and you will put it in a string array called buffer */


    fgets(buffer,MaxSize,fp);//this line means you will read all the strings with the spaces from the file unlike (fscanf: don't read the spaces) with the MaxSize of array buffer and you will put it in a string array called buffer
    printf("%s\n",buffer);//print on the console screen


    //do the same previous lines to read the next line this is an unprofessional solution [proffesional solution: make a for loop]
    fgets(buffer,MaxSize,fp);
    printf("%s\n",buffer);
}

void readarray()
{
    FILE* fp;
    char c;
    fp = fopen("test.txt","r");
    while(1){
        c =fgetc(fp); //get 1 character each loop from file fp
        if(c==EOF)
            break;
        printf("%c",c);
    }
    fclose(fp);
}

void readwritefromuser()
{
FILE* newfile;
char ch;
newfile=fopen("user.docx","w");
printf("N.B. IF YOU FINISHED ENTERING DATA PRESS: CTRL Z. to save\n");
printf("_________________________________________________________\n\n");
printf("Enter data to file: \n");
while((ch=getchar())!=EOF) //as you read characters from file and put it in c execute the loop
    {
        putc(ch,newfile);
    }
fclose(newfile);



newfile=fopen("user.docx","r");
while((ch=getc(newfile))!=EOF)
    {
        printf("%c",ch);
    }
fclose(newfile);

}


struct emp
{
   char name[10];
   int age;
};

void readwritefromuserstruct()
{
FILE* newfile;
struct emp e;
char ch;
newfile=fopen("test.txt","a");//a: means append
printf("N.B. IF YOU FINISHED ENTERING DATA PRESS: CTRL Z. to save\n");
printf("_________________________________________________________\n\n");
printf("Enter data to file: \n");
scanf("%s %d",e.name,&e.age);
fprintf(newfile,"%s %d",e.name,e.age);//you may use putc instead of fprintf

}

void main()
{
    //simplefilewrite();
    //simplefileread();
    //readarray();
    //readwritefromuser();
    readwritefromuserstruct();
    return 0;
}
