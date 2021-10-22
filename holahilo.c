#include <bits/pthreadtypes.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 1000
int saldo;
pthread_mutex_t saldolock = PTHREAD_MUTEX_INITIALIZER;
void * suma100(void *arg){
    pthread_mutex_lock(&saldolock);
    //char *c = (char *)arg;
    //printf("hola desde un hilo %s \n",c);
    int lsaldo = saldo;
    lsaldo += 100;
    saldo = lsaldo; 
    pthread_mutex_unlock(&saldolock);
    pthread_exit(NULL);
}


int main(){
    pthread_t threads[NUM_THREADS];
    saldo =0;
    char *s = "soy un argumento";
    for(int i =0; i < NUM_THREADS;i++){
        pthread_create(&threads[i],NULL,suma100,NULL);
    }
    for(int i =0; i < NUM_THREADS;i++){
        pthread_join(threads[i],NULL);
    }
    printf("saldo final es %d\n",saldo);
    pthread_exit(NULL);
}
