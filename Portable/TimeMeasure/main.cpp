
#include <thread>
#include "TimeMeasure.hpp"
#include <iostream>


int prin(int a)
{
    std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000));
    return 0;
}

int main()
{
    
    
    int time=TimeMeasure<>::execution(prin,100,20);
    
    std::cout << time;
    
    int a;
    std::cin >> a;
    
return 0;
}
