#include<iostream>
#include <thread>

void test(){
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    printf("Hello from test \n");
}

void sum(int &x, int &y){

    while(true){

        printf("La suma es %d \n", (x+y));
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}

int main(){
    
    int x = 10;
    int y = 2;

    printf("The value of x is %d and y is %d\n", x, y);

    std::thread threadSum(sum, std::ref(x), std::ref(y));

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    y = 4;

    printf("The value of y change to %d\n", y);
    threadSum.join();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    return 0;

}