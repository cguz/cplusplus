#include <iostream>
#include <thread>

void sum(int &x, int &y){

    while(true){

        printf("La suma es %d \n", (x+y));
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}

/*
* Program that sum two values with a thread passing the values by reference
* */
int main(){
    
    int x = 10;
    int y = 2;

    printf("The value of x is %d and y is %d\n", x, y);

    // create the thread with the function sum passing two parameters by reference
    std::thread threadSum(sum, std::ref(x), std::ref(y));

    // sleep for 5 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    // change the value of y
    y = 4;

    printf("The value of y change to %d\n", y);

    // call the join of the thread
    threadSum.join();

    // sleep for 5 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    return 0;

}