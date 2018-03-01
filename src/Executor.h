/*
 * Executor.h
 *
 *  Created on: Feb 27, 2018
 *      Author: szym
 */

#pragma once

#include <iostream>
#include <cassert>
#include "Parser.h"
#include "Operation.h"


#include "MedianDummy.h"
#include "MedianPrioQueue.h"

namespace median_online
{

// Policy based design, if you want to easily mix parsers (stdin, sockets, DBs)
// with median algos without all that class hierarchy, interfaces, factories BS.
template <class ParserType, class MedianType>
class Executor
{
    public:
        Executor(int argc, char **argv): _parser(ParserType(argc, argv))
        {}

        virtual ~Executor()
        {}

        void execute()
        {
            auto operation = _parser.getNextOperation();

            while (operation.first != OperationType::Quit)
            {
//                std::cout << __FUNCTION__ << " Got operation " << static_cast<int>(operation.first)
//                          << " with value " << operation.second << '\n';

                switch (operation.first)
                {
                    case OperationType::Add:
                        std::cout << "Adding " << operation.second << '\n';

                        _median1.add(operation.second);
                        _median2.add(operation.second);
                        break;

                    case OperationType::Median:

                        std::cout << "current median " << _median1.getMedian() << ", " <<  _median2.getMedian() << '\n';

                        assert(_median1.getMedian() == _median2.getMedian());
                        break;

                    default:
                        std::cerr << __FUNCTION__ << " Unknown operation " << static_cast<int>(operation.first) << '\n';
                        break;

                }
                operation = _parser.getNextOperation();
            }
        }

    protected:
        ParserType _parser;
//        MedianType _median;
        MedianDummy<int> _median1;
        MedianPrioQueue<int> _median2;
};

} /* namespace median_online */

