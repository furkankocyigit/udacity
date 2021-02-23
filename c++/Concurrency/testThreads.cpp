#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void threadFunction(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); //simulate work
    std::cout<<"Finished work 1 in thread"<<std::endl;

    // std::this_thread::sleep_for(std::chrono::milliseconds(100)); //simulate work
    // std::cout<<"Finished work 2 in thread"<<std::endl;
}

int main(){

    std::cout << "Hello concurrent world from main! Thread id = "<<std::this_thread::get_id()<<std::endl;

    unsigned int nCores = std::thread::hardware_concurrency();
    std::cout<<"this machine supports concurrency with "<<nCores<<" cores available" << std::endl;

    //create thread in main()
    std::thread t(threadFunction);

    //detach thread and continue with main
    t.detach();

    //wait for thread t to finish
    //t.join();
    
    //do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); //simulate work
    std::cout<<"Finished work 1 in main" <<std::endl;

    // std::this_thread::sleep_for(std::chrono::milliseconds(50)); //simulate work
    // std::cout<<"Finished work 2 in main" <<std::endl;

    
    





    return 0;
}