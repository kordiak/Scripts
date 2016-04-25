
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
    
    
    int time=TimeMeasure<>::execution(prin,10,20);
    
    
    TimeMeasure<> TM;
    
    
    TM.InitLevels(3);
    
    
    
    TM.Update(time/100.f,0);
    std::cout << TM.AverageTime(0);
    
    int a;
    std::cin >> a;
    
return 0;
}
