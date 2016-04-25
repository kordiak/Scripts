//
//  TimeMeasure.cpp
//  Hello
//
//  Created by Szymon Kordiaczyński on 21.04.2016.
//
//

#include "TimeMeasure.hpp"
#include <limits>
/*
template <typename TimeT>
void TimeMeasure<TimeT>::Update(float value,int level)
{
    times[level]+=value;
    counts[level]+=1;
}

template <typename TimeT>
void TimeMeasure<TimeT>::InitLevels(int lvlMax)
{
    times.resize(lvlMax);
    counts.resize(lvlMax);
}

template <typename TimeT>
void TimeMeasure<TimeT>::UpdateError(float T, float R)
{
    int value=static_cast<int>(T) + static_cast<int>(errorT) +1;
    setFloatErrorFlag(value);
    
    value=static_cast<int>(R) + static_cast<int>(errorR) +1;
    setFloatErrorFlag(value);
    
    errorT+=T;
    errorR+=R;
}

template <typename TimeT>
void TimeMeasure<TimeT>::setFloatErrorFlag(int val)
{
    if(std::numeric_limits<float>::max()<val)
        errorFloat=true;
}

template <typename TimeT>
float TimeMeasure<TimeT>::AverageTime(int lvl)
{
    return times[lvl]/static_cast<float>(counts[lvl]);
}

template <typename TimeT>
float TimeMeasure<TimeT>::ErrorT()
{
    return errorT/counts[0];
}
template <typename TimeT>
float TimeMeasure<TimeT>::ErrorR()
{
    return errorR()/counts[0];
}
 */
