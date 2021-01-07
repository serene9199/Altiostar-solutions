#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    int i,l,count=0,max=0;
char lines[5000], s[5000];
FILE *fp=fopen("sample.txt", "r");

if(fp == NULL){
    printf("File Opening Error!!");

}
//Reads each word and stores it into 'lines'.
    while(fscanf(fp, "%[a-zA-z0-9]%*[^a-zA-z0-9]", lines)!=EOF)
    {
    count=strlen(lines); //length of each word

//if the length of the current word is greater tha max, max is assigned the value of count and that word is copied to 's'
   if(count > max)
   {
    max = count; 
    strcpy(s,"");
    strcpy(s,lines);
   }
    }

 printf("\nThe longest word in the given text file is: %s\n", s);
 printf("Its length is: %d\n",max);

//closing the file
fclose(fp);
}