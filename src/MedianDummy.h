/*
 * MedianDummy.h
 *
 *  Created on: Feb 28, 2018
 *      Author: szym
 */

#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

namespace median_online
{

template <typename Type>
class MedianDummy
{
    public:
        MedianDummy(){}
        virtual ~MedianDummy(){}

        void add(Type number)
        {
            auto place = std::find_if(_numbers.begin(), _numbers.end(),
                                        [number](Type other)
                                        {
                                            return other > number;
                                        });

            _numbers.insert(place, number);

//            for (auto &el : _numbers)
//            {
//                std::cout << el << " ";
//            }
//            std::cout << "\n size " << _numbers.size() << '\n';
        }

        float getMedian()
        {
            if (_numbers.empty())
            {
                return 0.0f;
            }

            int middle = _numbers.size() / 2;

            float median = 0.0f;

            if (_numbers.size() % 2 == 0)
            {
                median = (_numbers[middle-1] + _numbers[middle]) / 2.0f;
            }
            else
            {
                median = _numbers[middle];
            }

            return median;
        }

    protected:
        std::vector<Type> _numbers;
};

} /* namespace median_online */

