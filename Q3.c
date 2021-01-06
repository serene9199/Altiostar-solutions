#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    int i,l,count=0,k=0,max=0,index=0,j;
char lines[5000], s[5000];
FILE *fp=fopen("sample.txt", "r");

if(fp == NULL){
    printf("File Opening Error!!");

}
//Reads and copies the whole string in the sample.txt file to 'lines'.
    fscanf(fp, "%[^\n]", lines);

//closing the file
fclose(fp);

l=strlen(lines); //length of the text copied

 index=0;
 //Finding the length of the longest word and starting index
 for( i = 0 ; i< l ; i++)
 {
/*Here, hyphenated words are considered as separate words (Eg:multi-vendor considered as 2 separate words)
We can count it as a single word if we eliminate " lines[i] != '-' " from the given condition*/ 
     
  if(lines[i] != ' '&&lines[i] != ','&&lines[i] != '.'&&lines[i] != '-'&&lines[i] != '('&&lines[i] != ')')
  {
   count++;
  }
  else
  {
/*if the length of the current word is greater tha max, max is assigned the value of count 
    and the starting index of that word is set as (i-max)*/
   if(count > max)
   {
    max = count; 
    index = i-max;
   }
   count = 0;
  }
 }
 /* Checking if last word is longest */
 if(count>max)
 {
  max = count;
  index = l-max;
 }
 /* Using the length and index to copy the longest word */
 j=0;
 for(i=index;i< index+max;i++)
 {
  s[j] = lines[i];
  j++;
 }
 /* Inserting NULL character to terminate string */
 s[j] = '\0';
 printf("\nThe longest word in the given text file is: %s\n", s);
 printf("Its length is: %d\n",max);
}
