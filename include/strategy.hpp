#pragma once
#include <vector>

#include "bar.hpp"

class Strategy {
public:
    virtual ~Strategy() = default;

    // given the data, and some index i that we're at, do we want to trigger a buy?
    [[nodiscard]] virtual bool buy(const std::vector<Bar>& data, int i) const = 0;

    // given the data, and some index i that we're at, do we want to trigger a sell?
    [[nodiscard]] virtual bool sell(const std::vector<Bar>& data, int i) const = 0;
};
