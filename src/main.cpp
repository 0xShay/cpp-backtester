#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "../include/strategies/sma2050strategy.hpp"
#include "../include/portfolio.hpp"

class Backtester {
private:
    std::vector<Bar> data;
    Portfolio portfolio;

public:
    explicit Backtester(const double initial_cash) : portfolio(initial_cash) {};

    bool loadData(const std::string& filename) {
        std::ifstream input_file(filename);

        if (!input_file.is_open()) {
            throw std::runtime_error("Could not open \"" + filename + "\"");
        }

        std::vector<Bar> bars;
        std::string line;
        // read header line
        std::getline(input_file, line);

        while (std::getline(input_file, line)) {
            std::stringstream ss(line);
            Bar bar;
            std::string temp;

            std::getline(ss, temp, ','); // ticker
            std::getline(ss, temp, ','); // per

            std::getline(ss, bar.date, ',');

            std::getline(ss, temp, ','); // time

            std::getline(ss, temp, ',');
            bar.open = std::stoi(temp);

            std::getline(ss, temp, ',');
            bar.high = std::stoi(temp);

            std::getline(ss, temp, ',');
            bar.low = std::stoi(temp);

            std::getline(ss, temp, ',');
            bar.close = std::stoi(temp);

            std::getline(ss, temp, ',');
            bar.volume = std::stoi(temp);

            bars.push_back(bar);
        }

        input_file.close();

        data = bars;
        return true;
    }

    void run() {
        for (int i = 0; i < data.size(); i++) {
            auto strategy = SMA2050Strategy();

            std::printf("%s | volume: %ld | PF shares: %d | PF cash: $%f | PF value: $%f\n",
                data[i].date.c_str(),
                data[i].volume,
                portfolio.getShares(),
                portfolio.getCash(),
                portfolio.getTotalValue((data[i].close)));

            if (strategy.buy(data, i)) {
                portfolio.buy(data[i+1].open, 1);
            }

            if (strategy.sell(data, i)) {
                portfolio.sell(data[i+1].open, 1);
            }
        }

        std::printf("\noverall return: %f\n", (portfolio.getTotalValue(data[data.size()-1].close) / 10000));
        std::printf("share value change: %f\n", (data[data.size()-1].close / data[0].open));
    }
};

int main() {
    Backtester bt(10000.0);

    if (bt.loadData("testaapl.txt")) {
        bt.run();
    }

    return 0;
}
