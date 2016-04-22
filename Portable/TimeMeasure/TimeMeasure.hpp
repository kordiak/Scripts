//
//  TimeMeasure.hpp
//  Hello
//
//  Created by Szymon Kordiaczyński on 21.04.2016.
//
//

#ifndef TimeMeasure_hpp
#define TimeMeasure_hpp

#include <stdio.h>
#include <chrono>



template<typename TimeT=std::chrono::milliseconds>
struct TimeMeasure
{
    template<typename F,typename ...Args>
    static typename TimeT::rep execution(F&& func,int times, Args&&... args)
    {
        auto start=std::chrono::steady_clock::now();
        for(int i=0;i<times;++i)
        std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
        
        auto duration=std::chrono::duration_cast<TimeT>(std::chrono::steady_clock::now()-start);
        return duration.count();
        
    }
    
};

#endif /* TimeMeasure_hpp */
