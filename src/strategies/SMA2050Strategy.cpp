#include "strategies/SMA2050Strategy.hpp"

[[nodiscard]] double calculateSMA(const std::vector<Bar>& data, const size_t end_idx, const int period) {
    double total = 0;
    for (size_t i = end_idx - period; i < end_idx; i++) {
        total += (data[i].high + data[i].low + data[i].close) / 3;
    }
    return total / period;
}

[[nodiscard]] bool SMA2050Strategy::buy(const std::vector<Bar>& data, int i) const {
    const double sma20 = calculateSMA(data, i, 20);
    const double sma50 = calculateSMA(data, i, 50);

    return sma20 < sma50;
}

[[nodiscard]] bool SMA2050Strategy::sell(const std::vector<Bar>& data, int i) const {
    const double sma20 = calculateSMA(data, i, 20);
    const double sma50 = calculateSMA(data, i, 50);

    return sma20 > sma50;
}