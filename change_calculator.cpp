// Program:			Money Counting Calculator
// Author:			Ilya Babenko - w1793796
// Date:			01/31/2023 - Spring 2023 - T/Th @ 1pm
// Description:		Calculate the minimum dollar bills and coins required
//					to make a given amount.

#include<iostream>
#include<iomanip>

void input_data(double &change_amount);
void perform_calculations(double change_amount, int &amount_of_quarters, int &amount_of_dimes, int &amount_of_nickels, int &amount_of_pennies);
void output_results(double change_amount, int amount_of_quarters, int amount_of_dimes, int amount_of_nickels, int amount_of_pennies );



int main(){
    int amount_of_quarters, amount_of_dimes, amount_of_nickels, amount_of_pennies;
    double change_amount;
    input_data(change_amount);
    perform_calculations(change_amount, amount_of_quarters, amount_of_dimes, amount_of_nickels, amount_of_pennies);
    output_results(change_amount, amount_of_quarters, amount_of_dimes, amount_of_nickels, amount_of_pennies);
    return 0;
}

//
// An input module that recieves the total amount user has.
//

void input_data(double &change_amount){
    std::cout << "Enter amount (e.g., 2.38): ";
    std::cin >> change_amount;
};

//
// A processing module that computes the minimum amount of dollar bills and coins required to make the given total.
//

void perform_calculations(double change_amount, int &amount_of_quarters, int &amount_of_dimes, int &amount_of_nickels, int &amount_of_pennies){
    int total = change_amount * 100 + 0.5;
    int rq, rd, rn, rp; // <--- remainders 213.00
    rq = total % 25;
    amount_of_quarters = (total - rq) / 25;
    rd = rq % 10;
    amount_of_dimes = (rq - rd) / 10;
    rn = rd % 5;
    amount_of_nickels = (rd - rn) / 5;
    rp = rn % 1;
    amount_of_pennies = (rn - rp) / 1;
};

//
// An output module that displays to the user the computed amount of dollar bills and coins required to make the given total.
//

void output_results(double change_amount, int amount_of_quarters, int amount_of_dimes, int amount_of_nickels, int amount_of_pennies ){
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "$" << change_amount << " can be created using" << std::endl;
    std::cout << "Number of quarters: " << amount_of_quarters << std::endl;
    std::cout << "Number of dimes   : "<< amount_of_dimes << std::endl;
    std::cout << "Number of nickels : " << amount_of_nickels << std::endl;
    std::cout << "Number of pennies : " << amount_of_pennies << std::endl;
};
