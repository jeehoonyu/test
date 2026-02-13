#include <iostream>
#include <string>
#include "stock.h"
using namespace std;

int main(){
    cout.precision(4);
    cout.setf(ios::fixed, ios::floatfield);

    //NAME, SHARES, AVERAGE, DIVIDEND
    // stock SPCE("SPCE", 152, 150.2735, 0.0);
    // SPCE.cost_averaging(10, 6.1);
    // SPCE.buy_multiple_times(650, 2, 2);
    // SPCE.buy(1000, 6.1);
    // SPCE.buy(27, 1.8);
    // SPCE.buy(1725, 6.6);
    // SPCE.buy(425, 1.86);
    // SPCE.buy(840, 17.4);
    // SPCE.buy(2506, 3);

    // stock EPR("EPR", 0, 40.0, 0.275);
    // EPR.snowball_effect(40, 42, 7);
    // EPR.snowball_effect(15, 40, 3);
    // EPR.buy(187, 40);
    // EPR.snowball_effect(0, 42, 8);

    // stock O("O", 30, 55.0, 0.2555*0.85);
    // O.snowball_effect(30, 55.0, 6);
    // O.snowball_effect(10, 55, 3);
    // O.snowball_effect(0, 55, 4);
    // O.buy(136, 55.0);
    // O.snowball_effect(0, 55, 2);
    // O.snowball_effect(0, 55.0, 12);

    // stock MAIN("MAIN", 0, 39, 0.2350);
    // MAIN.snowball_effect(30, 39, 5);
    // MAIN.snowball_effect(10, 39, 3);
    // MAIN.buy(76,39);
    // MAIN.buy(76,39);

    stock RKLB("RKLB", 1650, 4.8600, 0.0);
    // RKLB.show_target_average_while_adding(17500, 10.0, 23.0);
    // RKLB.cost_averaging(4.2, 3.65);
    // RKLB.buy(750, 19);
    // RKLB.buy(949, 12);
    // RKLB.buy(1035, 11);
    // RKLB.buy(1138, 10);
    // RKLB.buy(1352, 5.8);
    // RKLB.buy(10, 4.7);
    // RKLB.show_estimated_gain(100);
    // RKLB.buy_multiple_times(285, 4.2, 5);

    // stock PL("PL", 100, 5.7530, 0.0);
    // PL.buy(400, 2);
    // PL.cost_averaging(2.5, 2);

    // stock CMRX("CMRX", 200, 2.8800, 0.0);
    // CMRX.buy(200, 1);
    // CMRX.cost_averaging(1.3, 1);

    // stock TEST("TEST", 100, 10.0, 0);
    // TEST.show_target_average_while_adding(1000, 15.0, 20.0);

    // stock TEST2("TEST2", 1, 10, 0);
    // TEST2.show_target_average_while_adding(20, 18, 20);
    return 0;
}