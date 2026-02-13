#include <iostream>
#include <string>
#include "stock.h"
using namespace std;

    stock::stock(){
        NAME = "NO_NAME";
        total_amount = shares = average_price = 0.0;
        show_position();
    }
    stock::stock(string name, int amount, double price, double dividend){
        NAME = name;
        shares = amount;
        average_price = price;
        total_amount = shares * average_price;
        this->dividend = dividend;
        show_position();
    }
    // stock::stock(stock* stock_ptr){
    //     NAME = stock_ptr->get_name();
    //     shares = stock_ptr->get_shares();
    //     average_price = stock_ptr->get_average_price();
    //     total_amount = stock_ptr->get_shares() * get_average_price();
    //     dividend = stock_ptr->get_dividend();
    // }
    stock::~stock(){}
    void stock::buy(int amount, double price){
        double temp_average = get_average_price();
        shares += amount;
        total_amount += amount * price;
        average_price = evaluate_average(get_shares());
        cout << "|BUY ORDER|" << endl;
        cout << "Stock Name : " << get_name() << endl;
        cout << "Bought Stocks : " << amount << " shares"
        << " at : " << price << "$" << endl;
        cout << "Average Difference : "
        << -1 * (temp_average - get_average_price()) << "$" << endl;
        cout << "Amount Spent : " << amount * price << "$" << endl;
        show_position();
    }
    void stock::buy_multiple_times(int amount, double price, int times){
        double* changed_average = new double[times];

        for(int i = 0 ; i < times; i++){
            cout << "Times : " << i+1 << " of " << times << endl;
            buy(amount, price);
            changed_average[i] = get_average_price();
        }
        for(int i = 0; i < times-1; i++)
            cout << "Changed Average : " << changed_average[i] << "$" << endl;
        cout << "Changed Average : " << changed_average[times-1] << "$" << endl;
        delete []changed_average;
    }
    void stock::sell(int amount, double price){
        shares -= amount;
        total_amount -= amount * price;
        cout << "|SELL ORDER|" << endl;
        cout << "Stock Name : " << get_name() << endl;
        cout << "Sold Stocks : " << amount << " shares";
        cout << " at : " << price << "$" << endl;
        cout << "Amount sold : " << amount * price << "$" << endl;
        show_position();
    }
    void stock::sell_multiple_times(int amount, double price, int times){
        for(int i = 0 ; i < times; i++){
            cout << "Times : " << i+1 << " of " << times << endl;
            sell(amount, price);
        }
    }
    void stock::set_name(string name){NAME = name;}
    void stock::set_dividend(double dividend){this->dividend = dividend;
    }
    void stock::show_position(){
        cout << "--------------------------------------------" << endl;
        cout << "|SHOWING POSITION|" << endl;
        cout << "Stock Name : " << get_name() << endl;
        cout << "Shares : " << get_shares() << " shares";
        cout << " at: " << get_average_price() << "$" << endl;
        cout << "Dividend per stock : " << get_dividend() << "$" << endl;
        show_dividend();
        cout << "Total Amount : " << get_total_amount() << "$" << endl;
        cout << "--------------------------------------------" << endl;
    }
    void stock::show_dividend(){
        cout << "Dividend : " << get_shares() * get_dividend() << "$" << endl;
    }
    void stock::show_estimated_price(double percentage){
        cout << "Estimated price : " << average_price * (1 + percentage * 0.01) 
        << "$" << endl;
    }
    void stock::show_estimated_gain(double percentage){
        cout << "Estimated gain : " << shares * (average_price * 
        (1 + percentage * 0.01)) - (shares * average_price) << "$" << endl;
    }
    void stock::show_target_average_while_adding(double buy_amount, double target_average_price, double current_price){
        if (current_price >= get_average_price() && target_average_price <= get_average_price())
            return;
        if (current_price == target_average_price){
            cout << "you can add shares : " << int(buy_amount / current_price);
            cout << " at price of : " << current_price << "$" << endl;
            return;
        }

        long original_shares = get_shares();
        double temp_shares = 0;
        long minimum_buyable_shares = buy_amount / current_price;
        double temp_average_price = 0;
        double added_total_amount = get_total_amount() + minimum_buyable_shares * current_price;
        double temp_i = 0;

        for (double i = 0; temp_average_price < target_average_price || i <= current_price; i += 0.1){
            temp_shares = (double)buy_amount / i;
            temp_average_price = added_total_amount / ((int)temp_shares + original_shares);
            temp_i = i;

            if (temp_shares <= minimum_buyable_shares)
                break;
        }
        cout << "Target average price : " << target_average_price << "$" << endl;
        cout << "Average after added more shares : " << original_shares + temp_shares
        << " at average of " << temp_average_price << "$" << endl;
        cout << "You can buy " << temp_shares << " more shares at " << temp_i << " $ by spending "
        << temp_shares * temp_i << "$" << endl;
    }
    // void stock::snowball_effect(int amount, double price, int months){
    //     stock temp_stock = this;
    //     double* dividend_record = new double[months];
    //     double total_dividend = 0.0;
    //     double cash = 0.0;
    //     int stock_by_dividend = 0;

    //     for(int i = 0; i < months; i++){
    //         stock_by_dividend = 0.0;
    //         cash += temp_stock.get_shares() * temp_stock.get_dividend();

    //         if(cash >= price){
    //             stock_by_dividend = cash / price;
    //             cash -= stock_by_dividend * price;
    //             temp_stock.buy(stock_by_dividend, price);
    //         }
    //         total_dividend += temp_stock.get_shares() * temp_stock.get_dividend();
    //         temp_stock.show_dividend();
    //         dividend_record[i] = temp_stock.get_shares() * temp_stock.get_dividend();
    //         cout << "Total Dividend : " << total_dividend << "$" << endl;
    //         cout << "Cash : " << cash << "$" << endl;
    //         temp_stock.buy(amount, price);
    //     }
    //     for(int i = 0; i < months-1; i++)
    //         cout <<"Dividend times : " << i+1 << ", Dividend : "
    //         << dividend_record[i] << "$, " << endl;
    //     cout << "Dividend times : "<< months << ", Dividend : "<< dividend_record[months-1] << "$";
    //     cout << endl;
    //     delete []dividend_record;
    // }
    void stock::snowball_effect(int amount, double price, int months){
        double* dividend_record = new double[months];
        double total_dividend = 0.0;
        double cash = 0.0;
        int stock_by_dividend = 0;

        for(int i = 0; i < months; i++){
            stock_by_dividend = 0.0;
            cash += get_shares() * get_dividend();
            cout << "Cash : " << cash << "$" << endl;

            if(cash >= price){
                stock_by_dividend = cash / price;
                cash -= stock_by_dividend * price;
                buy(stock_by_dividend, price);
            }
            total_dividend += get_shares() * get_dividend();
            show_dividend();
            dividend_record[i] = get_shares() * get_dividend();
            cout << "Total Dividend : " << total_dividend << "$" << endl;
            cout << "Cash : " << cash << "$" << endl;
            buy(amount, price);
        }
        for(int i = 0; i < months-1; i++)
            cout <<"Dividend times : " << i+1 << ", Dividend : "
            << dividend_record[i] << "$, " << endl;
        cout << "Dividend times : "<< months << ", Dividend : "
        << dividend_record[months-1] << "$" << endl;
        cout << "--------------------------------------------" << endl;
        delete []dividend_record;
    }
    void stock::cost_averaging(double target_price, double current_price){
        if (target_price <= current_price) // if current price is higher then target price, 
            return;                        //it is impossible to lower the average.
        int temp_shares = get_shares();
        double temp_average = get_average_price();
        double temp_total = get_total_amount();
        unsigned int i = 0;
        bool is_under_average = false;

        while(!is_under_average){
            temp_shares += 1;
            temp_total += current_price;
            temp_average = temp_total / double(temp_shares);
            i++;
            
            if (temp_average <= target_price)
                is_under_average = true;
        }
        cout << "You need to buy : " << i << " shares." << endl;
        cout << "Average : " << temp_average << "," << endl;
        cout << "Amount : $" << temp_shares * current_price << endl;
    }
    string stock::get_name(){return NAME;}
    int stock::get_shares(){return shares;}
    double stock::get_dividend(){return dividend;}
    double stock::get_average_price(){return average_price;}
    double stock::get_total_amount(){return total_amount;}
    double stock::evaluate_average(int amount){
        return get_total_amount() / amount;
    }