/*
 * ParserGenerator.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: szym
 */



#include "ParserGenerator.h"

namespace median_online
{

ParserGenerator::ParserGenerator(int argc, char **argv)
{
    std::random_device rd;
    _twister = std::mt19937(rd());

    _distribution = std::uniform_int_distribution<>(-1000*1000*1000, 1000 *1000 *1000);
}

ParserGenerator::~ParserGenerator()
{
    // TODO Auto-generated destructor stub
}


Operation ParserGenerator::getNextOperation()
{
    static bool goMedian = true;

    Operation operation = Operation(OperationType::Quit, -1);

    if (goMedian)
    {
        operation = Operation(OperationType::Median, -1);
    }
    else
    {
        operation = Operation(OperationType::Add , _distribution(_twister));
    }

    goMedian = not goMedian;

    return operation;
}

} /* namespace median_online */
