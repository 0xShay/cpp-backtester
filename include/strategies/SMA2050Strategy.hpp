#pragma once

#include "Strategy.hpp"

class SMA2050Strategy : Strategy {
public:
    // given the data, and some index i that we're at, do we want to trigger a buy?
    [[nodiscard]] bool buy(const std::vector<Bar>& data, int i) const override;

    // given the data, and some index i that we're at, do we want to trigger a sell?
    [[nodiscard]] bool sell(const std::vector<Bar>& data, int i) const override;
};