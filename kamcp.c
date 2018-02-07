//Project 2

#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE *file1, *file2;
  char fileName[100], ch;

  printf("Enter the filename to open for reading \n");
  scanf("%s", fileName);

  file1 = fopen(fileName, "r");
  if(file1 == NULL){
	printf("%s is empty dawg\n", fileName);
	exit(0);
  }

  printf("Enter the filename you want to copy to\n");
  scanf("%s", fileName);
  
  file2 = fopen(fileName, "w");
  
  ch = fgetc(file1);
  while( ch != EOF){
	fputc(ch, file2);
	ch = fgetc(file1);
  } 


  fclose(file1);
  fclose(file2);
  return 0;



}
