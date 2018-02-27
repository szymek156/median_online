/*
 * Parser.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: szym
 */

#include <stdexcept>
#include <iostream>
#include "Parser.h"

namespace median_online
{

Parser::Parser(int argc, char **argv) : mArgsCounter(argc), mCurrentToken(1), mArgs(argv)
{
}

Parser::~Parser()
{
}


Parser::Operation Parser::getNextOperation()
{
    Operation operation = Operation(OperationType::Quit, -1);

    if (mCurrentToken >= mArgsCounter)
    {
        return operation;
    }

    // String overhead is negligible, don't cry
    std::string token = mArgs[mCurrentToken];

    if (isMedian(token))
    {
        operation.first = OperationType::Median;
    }
    else if (isQuit(token))
    {
        operation.first = OperationType::Quit;
    }
    else
    {
        try
        {
            int value = stoi(token);
            operation.first = OperationType::Add;
            operation.second = value;
        }
        catch (const std::logic_error &ex)
        {
            std::cerr << __FUNCTION__ << " Unable to parse " << mCurrentToken << " argument '"
                      << token << "'" << ", reason " << ex.what() << '\n';
        }
    }

    mCurrentToken++;

    return operation;
}


bool Parser::isMedian(const std::string &token)
{
    const std::string MEDIAN = "m";
    return  token.compare(MEDIAN) == 0;
}

bool Parser::isQuit(const std::string &token)
{
    const std::string QUIT = "q";
    return  token.compare(QUIT) == 0;
}

} /* namespace median_online */
