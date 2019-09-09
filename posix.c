#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
using namespace std;
#define MAX 200

 char** parsing(char buffer[], int i)
 {
    char **out=(char**)malloc(sizeof(char*)*200);
    char *mid;
int length = strlen(buffer);
    while(length > 0)
    {   
        if(buffer[length-1]== '\n' || buffer[length-1]== ' ')
            buffer[length - 1] ='\0';
        else
            break;
        length--;
    }
  mid=strtok(buffer," ");

  while(mid!=NULL)
   {
    out[i]=(char*)malloc(sizeof(char)*200);
    strcpy(out[i], mid);
    mid=strtok(NULL," ");
    i++;
   }
   out[i]==NULL;//without this seg fault
   return out;
 } 
    


int main()
{

    while(1)
    {
      char buffer[MAX];
      char **out;
      int i=0;
      fgets(buffer,MAX,stdin);
      out = parsing(buffer,i);

      if(!strcmp(out[0],"exit"))break;
      if(!strcmp(out[0],"cd"))
      {
          if(out[1]==NULL)chdir("/");
          else chdir(out[1]);
      }
      int child=fork();

      if (child == 0)
      {
         // cout<<out[0]<<strlen(out[0])<<endl;
          execvp(out[0],out);
          exit(-1);
      }
      else
      {
          wait(NULL);
      }

        
    }
    
    

    return 0;
}