/*
	Kamran Khadivi-Dimbali
*/

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>


#define THREADS 4
#define buffer 65536

int asciiChars[128];
char buffer[buffer];
pthread_mutex_t lock;

//Thread data
typedef struct{
    int partitionBound;
    int threadNumber;
    int maxLength;
} threadData;

//function to count the ascii characthers
void *threadCount(void *tData) {
    int i, threadPosition;
    //char currentChar;

    threadData *data = (threadData*) tData;
    threadPosition = data->threadNumber * data->partitionBound;
    
    //find and store ascii chars
  for(i = 0; threadPosition + i < data->maxLength && i < data->partitionBound; i++) {
        pthread_mutex_lock(&lock);
        asciiChars[buffer[threadPosition + i]]++;
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
} 

int main(int argc, char* argv[]){
    
    pthread_t threadIds[THREADS];
    threadData tData[THREADS];
    
    int i, j, //loops
    sourceFile, partitions, charTotal, threadmax;
    
    sourceFile = open(argv[1], O_RDONLY);  //open file
    
    //error opening file
    if (sourceFile < 0){
        fprintf(stderr, "Error opening file!\n");
        return -1;
    } 
    
    sourceFile = read(sourceFile, buffer, buffer); 
    partitions = (double) sourceFile / (double) THREADS;

    if(pthread_mutex_init(&lock, NULL) != 0){
        printf("\n mutex init failed\n");
        return 1;
    }
    
    //create threads
    for(i = 0; i < THREADS; i++) {
        tData[i].threadNumber = i;
        tData[i].partitionBound = partitions;
        tData[i].maxLength = sourceFile;
        //Passes data through 
    	threadmax = pthread_create(&threadIds[i],NULL,&threadCount,&tData[i]);
		
		//error check
    	if(threadmax != 0)
     	       printf("Error creating thread! %i\n", i);
   		} 
    
    i = 0;
    do{
        pthread_join(threadIds[i], NULL);
        i++;
    } while (i < THREADS);
    
    //print results
    for(i = 0; i < 128; i++) {
        
        printf("%i occurrences of ", asciiChars[i]);
        
        if(i < 33 || i == 127){
            printf("%#0x\n", i);
        } 
        else{
            printf("%c\n", i);
        }
    } 
    close(sourceFile);
    
    return 0;
} 