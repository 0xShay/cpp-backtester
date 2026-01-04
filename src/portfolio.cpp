#include "../include/portfolio.hpp"

Portfolio::Portfolio(const double initial_cash) {
    cash = initial_cash;
    shares = 0;
}

bool Portfolio::buy(const double price, const int quantity) {
    if (cash > price * quantity) {
        cash -= price * quantity;
        shares += quantity;
        return true;
    }
    return false;
}

bool Portfolio::sell(const double price, const int quantity) {
    if (shares > quantity) {
        cash += price * quantity;
        shares -= quantity;
        return true;
    }
    return false;
}

double Portfolio::getTotalValue(const double current_price) const {
    return cash + (shares * current_price);
}

int Portfolio::getShares() const {
    return shares;
}

double Portfolio::getCash() const {
    return cash;
}
