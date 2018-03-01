/*
 * MedianPrioQueue.h
 *
 *  Created on: Mar 1, 2018
 *      Author: szym
 */

#pragma once

#include <queue>
#include <vector>
#include <iostream>

namespace median_online
{

template <typename Type>
class MedianPrioQueue
{
    public:
        MedianPrioQueue() : _currentMedian(0), _balance(0){}
        virtual ~MedianPrioQueue() {}

        void add(Type number)
        {
            switch (_balance)
            {
                case 0:
                {
                    if (number < _currentMedian)
                    {
                        _smaller.push(number);
                        _currentMedian = _smaller.top();
                        _balance = -1;
                    }
                    else
                    {
                        _greater.push(number);
                        _currentMedian = _greater.top();
                        _balance = 1;
                    }
                    break;
                }

                case 1:
                {
                    if (number < _currentMedian)
                    {
                        _smaller.push(number);
                    }
                    else
                    {
                        _greater.push(number);
                        _smaller.push(_greater.top());
                        _greater.pop();
                    }

                    _balance = 0;

                    _currentMedian = (_greater.top() + _smaller.top()) / 2.0f;
                    break;
                }

                case -1:
                {
                    if (number >= _currentMedian)
                    {
                        _greater.push(number);
                    }
                    else
                    {
                        _smaller.push(number);
                        _greater.push(_smaller.top());
                        _smaller.pop();
                    }

                    _balance = 0;
                    _currentMedian = (_greater.top() + _smaller.top()) / 2.0f;

                    break;
                }
            }

//            auto greater = _greater;
//            while (not greater.empty())
//            {
//                std::cout << greater.top() << " ";
//                greater.pop();
//            }
//            std::cout << "\n size " << _greater.size() << '\n';
//
//            auto smaller = _smaller;
//
//            while (not smaller.empty())
//            {
//                std::cout << smaller.top() << " ";
//                smaller.pop();
//            }
//            std::cout << "\n size " << _smaller.size() << '\n';
        }

        float getMedian()
        {
            return _currentMedian;
        }

    protected:
        std::priority_queue<Type> _smaller;
        std::priority_queue<Type, std::vector<Type>, std::greater<Type> > _greater;

        float _currentMedian;
        int _balance;
};

} /* namespace median_online */

