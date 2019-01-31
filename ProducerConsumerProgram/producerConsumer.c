/*
	Kamran Khadivi-Dimbali
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<math.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>


#define SLOTS 16

int consumerItems;
int producerItems;
pthread_mutex_t lock;
int count = 0;
int buffer[SLOTS];
sem_t full; //Must stop when buffer is full
sem_t empty; //Must stop when buffer is empty


struct producerThread{
    int pid;
    int sizeProduce;
};

void *consumer(void *consume){
    int numconsumer = *(int *) consume;
    int item;
    int i = 0;
    
    while(i < numconsumer){
        
        sem_wait(&full);
        pthread_mutex_lock(&lock);
        
        if(count > 0){ //ready to read
            count--;
            
            item = buffer[count];
            
            printf("Item %-2i consumed from slot %i\n", item, count);
            
            buffer[count] = 0;
        }else{
            exit(1);
        } 
        pthread_mutex_unlock(&lock);
        sem_post(&empty);
        i++;
    } 
    
    pthread_exit(0);
} 

void *producer(void *produce){
    struct producerThread* pdata = (struct producerThread*) produce;
    int i = 0;
    int item;
    
    while(i < pdata->sizeProduce){
        item = pdata->pid * pdata->sizeProduce + i;
        
        sem_wait(&empty);
        pthread_mutex_lock(&lock);
        
        if(count < SLOTS){ //ready to write
            buffer[count] = item;
            
            printf("Item %-2i produced to slot %i\n", item, count);
            
            count++;
        }else{
            exit(1);
        } 
        
        pthread_mutex_unlock(&lock);
        sem_post(&full);
        i++;
    } 
    
    pthread_exit(0);
} 

int main(int argc, const char * argv[]){
    int i;
    int numProducers, numConsumers, numItems;
    pthread_t *producerrs;
    pthread_t *consumerrs;
    
    //sempaphore
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, SLOTS);
    
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\nError initializing mutex\n");
        return 1;
    } 
    
    //Number of consumers, producers, items 
    //by binary log
    numConsumers = pow(2, atoi(argv[2]));
    numProducers = pow(2, atoi(argv[1]));
    numItems = pow(2, atoi(argv[3]));
    
    producerItems = numItems / numProducers;
    consumerItems = numItems / numConsumers;
    
    //Print
    printf("Producers: %i\n", numProducers);
    printf("Consumers: %i\n", numConsumers);
    printf("Items produced: %i\n\n", numItems);
    printf("Items for each producer: %i\n", producerItems);
    printf("Items for each consumer: %i\n\n", consumerItems);
    
    //memory allocations
    producerrs = (pthread_t *)malloc(numProducers * sizeof(pthread_t));
    consumerrs = (pthread_t *)malloc(numConsumers * sizeof(pthread_t));
    
    struct producerThread pData[numProducers];
    
    //Producer Threads
    for(i = 0; i < numProducers; i++){
        pData[i].pid = i;
        pData[i].sizeProduce = producerItems;
        
        if(pthread_create(&producerrs[i], NULL, producer, &pData[i]) != 0){
            printf("\nError creating producerr threads\n");
            return 1;
        } 
    } 
    
    //Consumer Threads
    for(i = 0; i < numConsumers; i++){
        if(pthread_create(&consumerrs[i], NULL, consumer, &consumerItems) != 0){
            printf("\nError creating consumerr threads\n");
            return 1;
        } 
    } 
    
   	//Join Threads
    for(i = 0; i < numProducers; i++){
        pthread_join(producerrs[i], NULL);
    } 
    
    for( i=0; i < numConsumers; i++){
        pthread_join(consumerrs[i], NULL);
    } 
    
    //Free allocated memory
    free(producerrs);
    free(consumerrs);
    pthread_mutex_destroy(&lock);
    sem_destroy(&full);
    sem_destroy(&empty);
    
    return 0;
}