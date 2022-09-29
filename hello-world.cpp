#include <iostream>
#include <thread>

void thread_function()
{
    while(true){
        int i = 1000;
        i = i*10;
    }
}

const int threads = 20000;

int main()
{
    std::thread myThreads[threads];

    for(int i = 0; i< threads; i++){
        myThreads[i] = std::thread(&thread_function);
    }

    std::cout << "main thread\n";

    while(true){

    }
    return 0;
}