#include <iostream>
#include <thread>
#include <mutex>
#include <list>

std::list<int> my_list;
std::mutex m;

void add_to_list(int const & x) {

    // garantie to access mutually exclusive
    m.lock();
    my_list.push_front(x);
    m.unlock(); // it is important to unlock
}

void size() {
    m.lock();
    int size = my_list.size();
    m.unlock();
    std::cout << "size of the list is: " << size << std::endl;
}

int main(){
    
    std::thread thread_1(add_to_list, 4);
    std::thread thread_2(add_to_list, 11);

    thread_1.join();
    thread_2.join();

}