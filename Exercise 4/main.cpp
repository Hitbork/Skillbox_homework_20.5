#include <iostream>
#include <fstream>
#include <ctime>

bool can_value_be_withdraw(int &value) {
    // If value doesn't end on two zeros it can't be withdrawal
    if (value % 100 != 0) return false;


}


int main() {
    // Making random work
    std::srand(std::time(nullptr));

    // Greetings
    std::cout << "\tATM at work\n\n\n";

    // Creating var
    char temp;

    // Check for an action
    std::cout << "Insert:" << std::endl <<
                    " '-' for cash withdrawal" << std::endl <<
                    " '+' for filling ATM with money (for collectors)\n" << std::endl;
    std::cin >> temp;
    std::cout << "\n\n";

    // Check if withdrawing cash
    if (temp == '-') {
        // Creating var for requested value
        int valueToWithdraw;

        // Requesting value to withdraw
        std::cout << "Insert value to withdraw:\n";
        std::cin >> valueToWithdraw;
        std::cout << std::endl;

        // Checking if we can withdraw money

    }
    // Check if filling ATM with money
    else {

    }

    return 0;
}
