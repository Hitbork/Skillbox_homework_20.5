#include <iostream>
#include <fstream>
#include <ctime>

bool can_value_be_withdraw(int &value) {
    // If value doesn't end on two zeros it can't be withdrawal
    if (value % 100 != 0) return false;

    return true;
}

void fillingTheATM() {
    // Making random work
    std::srand(std::time(nullptr));

    // Creating var
    int array[1000], temp;

    // Filling the array with banknotes
    for (int i = 0; i < 1000; i++) {
        temp = rand() % 5;

        switch (temp) {
            case 0:
                array[i] = 100;
                break;
            case 1:
                array[i] = 200;
                break;
            case 2:
                array[i] = 500;
                break;
            case 3:
                array[i] = 1000;
                break;
            case 4:
                array[i] = 2000;
                break;
            case 5:
                array[i] = 5000;
                break;
            default:
                std::cout << "Filler doesn't work correctly.\n";
                break;
        }

        // Creating the flow
        std::ofstream ATM("C:\\TXT\\Skilbox\\Module 20\\4.bin", std::ios::binary);

        // Checking if ATM couldn't be opened
        if (!ATM.is_open()) {
            std::cout << "ATM doesn't open prorpely!\n";
        }

        // Writing array into the file
        ATM.write((char*) array, sizeof(int) * 1000);

        // Closing the file
        ATM.close();
    }
}




int main() {
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
        fillingTheATM();
    }

    return 0;
}
