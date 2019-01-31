/*
	Kamran Khadivi-Dimbali
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int pageSize;
int memSize;
int typeOfPage;
int frameNum;
int *frames;
int pages[100];

int isInArray(int num, int array[], int size){
    int index = 0;

    for(index = 0; index < size; index++){
    	if(array[index] == num)
    		return index;
    }

    return -1;
}


int fifo(int prefs[], int arraySize){
    int replace = 0, numberOfPageFaults = 0;
    int i = 0;
    
    do{
    	frames[i] = -1;
    	i++;
    }while(i < frameNum);
    
    for (i = 0; i < arraySize; i++){
        if (isInArray(prefs[i], frames, frameNum) < 0){
            frames[replace % frameNum] = prefs[i];
            replace++;
            numberOfPageFaults++;
        }
    }
    return numberOfPageFaults;
}

int lru(int prefs[], int arraySize){
    int numberOfPageFaults = 0, index, i = 0, j, innerIndex = 0, referece, t;
    
    do{
    	frames[i] = -1;
    	i++;
    }while(i < 3);

    
    int *b;
    b = (int *)malloc(frameNum * sizeof(int));
    
    int *c2;
    c2 = (int *)malloc(frameNum * sizeof(int));
    
    frames[innerIndex] = prefs[innerIndex];
    
    numberOfPageFaults++;
    innerIndex++;
    
    for (i = 1; i< arraySize; i++){
        index = 0;
        
        if (isInArray(prefs[i], frames, frameNum) < 0){
            index = frameNum;
            numberOfPageFaults++;
            
            if (innerIndex < frameNum){
                frames[innerIndex] = prefs[i];
                innerIndex++;
            }
            else{
                for (referece = 0; referece < frameNum; referece++){
                    c2[referece] = 0;
                    for (j = i - 1; j < pageSize; j--){
                        if (frames[referece] != prefs[j])
                            c2[referece]++;
                        else
                            break;
                    }
                }
                
                for (referece = 0; referece < frameNum; referece++)
                    b[referece] = c2[referece];
                for (referece = 0; referece < frameNum; referece++){
                    for (j = referece; j < frameNum; j++){
                        if (b[referece]<b[j]){
                            t = b[referece];
                            b[referece] = b[j];
                            b[j] = t;
                        }
                    }
                }
                
                for (referece = 0; referece < frameNum; referece++){
                    if (c2[referece] == b[0])
                        frames[referece] = prefs[i];
                }
            }
        }
    }
    return numberOfPageFaults;
}

int main(int argc, char *argv[]){
    if (argc < 5){
        printf("\nIncorrect number of arguements\n");
        return 1;
    }

    pageSize = pow(2, atoi(argv[1]));
    memSize = pow(2,atoi(argv[2]));
    if (strcmp(argv[3], "FIFO") == 0){
        typeOfPage = 0;
    }
    else{
        typeOfPage = 1;
    }
    frameNum = atoi(argv[4]);
    
    frames = (int *)malloc(frameNum * sizeof(int));
    
    int count = 0, number;
    char addrs[100];
    
    printf("\nAlgorithm: %s\nFrames: %d\n", argv[3], frameNum);
    
    while (fgets(addrs, sizeof(addrs), stdin)){
        addrs[strlen(addrs) - 1] = '\0';
        
        if (strcmp(addrs, "") == 0)
            break;
        
        number = (int)strtol(addrs, NULL, 0) / pageSize;

        pages[count] = number;
        count++;
    }
    
    if (typeOfPage == 0){
        printf("Number of faults: %d\n\n", fifo(pages, count));
    }
    
    else if (typeOfPage == 1){
        printf("Number of faults: %d\n\n", lru(pages, count));
    }
    
    return 0;
}