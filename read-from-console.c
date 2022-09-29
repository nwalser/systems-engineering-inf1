#define _XOPEN_SOURCE 700
#include <assert.h>
#include <stdlib.h>
#include <pthread.h>

enum CONSTANTS {
    NUM_THREADS = 1000000,
    NUM_ITERS = 1000000
};

int global = 0;
int fail = 0;
pthread_mutex_t main_thread_mutex = PTHREAD_MUTEX_INITIALIZER;

void* main_thread(void *arg) {
    int i;
    for (i = 0; i < NUM_ITERS; ++i) {
        if (!fail)
            pthread_mutex_lock(&main_thread_mutex);
        global++;
        if (!fail)
            pthread_mutex_unlock(&main_thread_mutex);
    }
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t threads[NUM_THREADS];
    int i;
    fail = argc > 1;
    for (i = 0; i < NUM_THREADS; ++i)
        pthread_create(&threads[i], NULL, main_thread, NULL);
    for (i = 0; i < NUM_THREADS; ++i)
        pthread_join(threads[i], NULL);
    assert(global == NUM_THREADS * NUM_ITERS);
    return EXIT_SUCCESS;
}