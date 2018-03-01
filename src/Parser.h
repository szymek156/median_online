/*
 * Parser.h
 *
 *  Created on: Feb 27, 2018
 *      Author: szym
 */

#pragma once

#include <string>
#include "Operation.h"

namespace median_online
{

class Parser
{
    public:
        Parser(int argc, char **argv);
        virtual ~Parser();

        Operation getNextOperation();

    protected:
        int _argsCounter;
        int _currentToken;
        char **_args;

        bool isMedian(const std::string &token);
        bool isQuit(const std::string &token);
};

} /* namespace median_online */

