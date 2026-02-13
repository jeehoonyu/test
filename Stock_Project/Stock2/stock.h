#ifndef STOCK_H
#define STOCK_H
#include <string>
using namespace std;
class stock{
private:
    string NAME;
    int shares;
    double average_price;
    double total_amount;
    double dividend;
public:
    stock();
    stock(string name, int amount, double price, double dividend);
    // stock(stock* stock_ptr);
    ~stock();
    void buy(int amount, double price);
    void buy_multiple_times(int amount, double price, int times);
    void sell(int amount, double price);
    void sell_multiple_times(int amount, double price, int times);
    void set_name(string name);
    void set_dividend(double dividend);
    void show_position();
    void show_dividend();
    void show_estimated_price(double percentage);
    void show_estimated_gain(double percentage);
    void show_target_average_while_adding(double buy_amount, double target_average_price, double current_price);
    void snowball_effect(int amount, double price, int months);
    void cost_averaging(double target_price, double current_price);
    string get_name();
    int get_shares();
    double get_dividend();
    double get_average_price();
    double get_total_amount();
    double evaluate_average(int amount);
};
#endif
