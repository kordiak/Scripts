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

#include <vector>


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
    
private:
    
    std::vector<float>times;
    std::vector<int> counts;
    
    float errorT;
    float errorR;
    
    void setFloatErrorFlag(int val)
    {
        if(std::numeric_limits<float>::max()<val)
            errorFloat=true;
    }
    bool errorFloat;

public:
    void InitLevels(int lvlMax)
    {
        times.resize(lvlMax);
        counts.resize(lvlMax);
    }

    void Update(float value,int level=0)
    {
        times[level]+=value;
        counts[level]+=1;
    }
    void UpdateError(float T,float R)
    {
        int value=static_cast<int>(T) + static_cast<int>(errorT) +1;
        setFloatErrorFlag(value);
        
        value=static_cast<int>(R) + static_cast<int>(errorR) +1;
        setFloatErrorFlag(value);
        
        errorT+=T;
        errorR+=R;
    }
    float AverageTime(int lvl)
    {
        return times[lvl]/static_cast<float>(counts[lvl]);
    }
    float ErrorT()
    {
        return errorT/counts[0];
    }
    float ErrorR()
    {
        return errorR()/counts[0];
    }
    
    
    
    
};

#endif /* TimeMeasure_hpp */
