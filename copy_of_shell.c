#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#define MAX 100000
int main()
{
    char input[MAX];
    //char* p="/bin/";
    char* argv[MAX];
    char* tok;
    int i=0;
while(1){
    printf(">>>>");
int i=0;
if(fgets(input,MAX,stdin)==0)
{
    break;
}
if(strcmp(input,"exit")==0)
{   
    break;
} 
size_t x=strlen(input);
if(input[x-1]=='\n')
 {
    input[x-1]='\0';
 }  

tok=strtok(input," ");

while(tok!=NULL)
{
    argv[i]=tok;
    tok=strtok(NULL," ");
    i++;
}
argv[i]=NULL;//without this it was giving seg faultS
//strcpy(argv,c);



pid_t child=fork();

if (child==0)
 {
    execvp(argv[0],argv);
 }
else
 {
    wait(NULL);
 }

}
return 0;

}