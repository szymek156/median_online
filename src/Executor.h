/*
 * Executor.h
 *
 *  Created on: Feb 27, 2018
 *      Author: szym
 */

#pragma once

#include <iostream>
#include "Parser.h"

namespace median_online
{

// Policy based design, if you want to easily mix parsers (stdin, sockets, DBs)
// with median algos without all that class hierarchy, interfaces, factories BS.
template <class ParserType, class MedianType>
class Executor
{
    public:
        Executor(int argc, char **argv): mParser(ParserType(argc, argv))
        {}

        virtual ~Executor()
        {}

        void execute()
        {
            auto operation = mParser.getNextOperation();

            while (operation.first != Parser::OperationType::Quit)
            {
                std::cout << __FUNCTION__ << " Got operation " << static_cast<int>(operation.first)
                          << " with value " << operation.second << '\n';

                switch (operation.first)
                {
                    case Parser::OperationType::Add:
                        break;
                    case Parser::OperationType::Median:
                        break;
                    default:
                        std::cerr << __FUNCTION__ << " Unknown operation " << static_cast<int>(operation.first) << '\n';
                        break;

                }
                operation = mParser.getNextOperation();
            }
        }

    protected:
        ParserType mParser;
};

} /* namespace median_online */

