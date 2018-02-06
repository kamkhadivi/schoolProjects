#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MYNAME "Kamran Khadivi"

int main(){
	
	char hello[50];
	snprintf(hello, 50, "Hello 415, I am %s!\n", MYNAME);	
	write(1,hello,strlen(hello));
	
	return 0;
}
