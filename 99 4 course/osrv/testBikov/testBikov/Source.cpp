#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include "rdtsc.h"
#include <time.h>

#define N 100000

double t = 0;

void* semaphore_test_proc(void* arg) {
    sem_t* sem = (sem_t*)arg;
    for (int i = 0; i < N; i++) {
        sem_wait(sem);
        t += 0.001;
        sem_post(sem);
    }
}

void* mutex_test_proc(void* arg) {
    pthread_mutex_t* mutex = (pthread_mutex_t*)arg;
    for (int i = 0; i < N; i++) {
        pthread_mutex_lock(mutex);
        t += 0.001;
        pthread_mutex_unlock(mutex);
    }
}

void test_semaphores(int nThreads) {
    sem_t sem;
    pthread_t* threads = new pthread_t[nThreads];

    sem_init(&sem, 0, 0);
    for (int i = 0; i < nThreads; i++) {
        pthread_create(&threads[i], NULL, semaphore_test_proc, &sem);
    }

    clock_t start = clock();
    sem_post(&sem);
    for (int i = 0; i < nThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    clock_t end = clock();

    printf("Semaphore, %d thread(s):\t\t%f us/N\n", nThreads, (double)(end - start) / CLOCKS_PER_SEC * 1000000 / N);
    sem_destroy(&sem);
    delete[] threads;
}

void test_mutexes(int nThreads) {
    pthread_mutex_t mutex;
    pthread_t* threads = new pthread_t[nThreads];

    pthread_mutex_init(&mutex, 0);
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < nThreads; i++) {
        pthread_create(&threads[i], NULL, mutex_test_proc, &mutex);
    }

    clock_t start = clock();
    pthread_mutex_unlock(&mutex);
    for (int i = 0; i < nThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    clock_t end = clock();

    printf("Mutex, %d thread(s):\t\t%f us/N\n", nThreads, (double)(end - start) / CLOCKS_PER_SEC * 1000000 / N);
    pthread_mutex_destroy(&mutex);
    delete[] threads;
}

int main() {
    printf("\nBody: %d iterations of 't += 0.001'\n\n", N);

    test_semaphores(1);
    test_semaphores(2);
    test_semaphores(3);

    test_mutexes(1);
    test_mutexes(2);
    test_mutexes(3);
}
