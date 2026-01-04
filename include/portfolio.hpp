#pragma once

// Portfolio to track cash and positions
class Portfolio {
private:
    double cash;
    int shares;

public:
    explicit Portfolio(double initial_cash);

    // Buy shares at given price. Returns true if successful.
    bool buy(double price, int quantity);

    // Sell shares at given price. Returns true if successful.
    bool sell(double price, int quantity);

    // Calculate total portfolio value (cash + shares * current_price)
    [[nodiscard]] double getTotalValue(double current_price) const;

    [[nodiscard]] int getShares() const;
    [[nodiscard]] double getCash() const;
};
