/*
 * ParserGenerator.h
 *
 *  Created on: Mar 1, 2018
 *      Author: szym
 */

#pragma once

#include <random>
#include "Operation.h"

namespace median_online
{

class ParserGenerator
{
    public:
        ParserGenerator(int argc, char **argv);
        virtual ~ParserGenerator();
        Operation getNextOperation();

    protected:
        std::mt19937 _twister;
        std::uniform_int_distribution<> _distribution;
};

} /* namespace median_online */

