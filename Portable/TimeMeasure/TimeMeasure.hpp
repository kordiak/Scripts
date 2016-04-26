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


template<typename errorT,typename TimeT=std::chrono::milliseconds>
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
    

    float errorLengthTrans;
    float errorAngleTrans;

    errorT error;

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

    void UpdateError(errorT errorcurrent)
    {
        error+=errorcurrent;
    }


    float AverageTime(int lvl)
    {
        return times[lvl]/static_cast<float>(counts[lvl]);
    }

    errorT Error(int lvl=0)
    {
        return error/static_cast<float>(counts[lvl]);
    }
    void Reset()
    {
        error=errorT();

        int size=times.size();

        times.clear();
        counts.clear();

        InitLevels(size);


    }
    
    
};

#endif /* TimeMeasure_hpp */
