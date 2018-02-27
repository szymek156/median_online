/*
 * Parser.h
 *
 *  Created on: Feb 27, 2018
 *      Author: szym
 */

#pragma once

#include <utility>
#include <string>

namespace median_online
{

class Parser
{
    public:
        Parser(int argc, char **argv);
        virtual ~Parser();

        enum class OperationType
        {
            Add,
            Median,
            Quit
        };

        using Operation = std::pair<OperationType, int>;

        Operation getNextOperation();

    protected:
        int mArgsCounter;
        int mCurrentToken;
        char **mArgs;

        bool isMedian(const std::string &token);
        bool isQuit(const std::string &token);
};

} /* namespace median_online */

