#pragma once
#include <utility>


namespace median_online
{
    enum class OperationType
    {
        Add,
        Median,
        Quit
    };

    using Operation = std::pair<OperationType, int>;
}
