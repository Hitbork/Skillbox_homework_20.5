#include <iostream>
#include <fstream>
#include <ctime>

int banknotes[6] = {0, 0, 0, 0, 0, 0};
int values[6] = {100, 200, 500, 1000, 2000, 5000};

void writingTheBanknoteIntoCounter(int &value) {
    switch (value) {
        case 100:
            banknotes[0] += 1;
            break;
        case 200:
            banknotes[1] += 1;
            break;
        case 500:
            banknotes[2] += 1;
            break;
        case 1000:
            banknotes[3] += 1;
            break;
        case 2000:
            banknotes[4] += 1;
            break;
        case 5000:
            banknotes[5] += 1;
            break;
        default:
            std::cout << "Numbers isn't correctly determined";
            break;
    }
}

void outputTheFillingOfATM() {
    std::cout << "Filling status of ATM:\n" <<
                "   100 - " << banknotes[0] << std::endl <<
                "   200 - " << banknotes[1] << std::endl <<
                "   500 - " << banknotes[2] << std::endl <<
                "   1000 - " << banknotes[3] << std::endl <<
                "   2000 - " << banknotes[4] << std::endl <<
                "   5000 - " << banknotes[5] << std::endl;

    std::cout << "\n\n";
}

void checkingTheATM() {
    // Filling the gaps
    for (int i = 0; i < 6; i++) {
        banknotes[i] = 0;
    }

    // Creating the flow to read
    std::ifstream flow("C:\\TXT\\Skillbox\\Module 20\\4.bin", std::ios::binary);

    // Checking if file isn't existing or empty
    if (!flow.is_open() || (flow.peek() == EOF)) {
        std::cout << " !!! ATM is empty !!!\n";
        flow.close();
        return;
    }

    // Reading the file and counting banknotes
    int value;

    while (!flow.eof()) {
        flow.read((char*)&value, sizeof(int));

        writingTheBanknoteIntoCounter(value);
    }

    flow.close();

    // Outputting info about filling of ATM
    outputTheFillingOfATM();
}

void writingBanknotesIntoFile() {
    // Creating the flow input to
    std::fstream flow;

    flow.open("C:\\TXT\\Skillbox\\Module 20\\4.bin", std::ios::in | std::ios:: out | std::ios::binary | std::ios::trunc);

    if (!flow.is_open()) {
        std::cout << "Error! File hasn't opened!";
        return;
    }

    // Clearing the past numbers
    flow.clear();

    // Filling with banknotes
    int currentIndex = 0;

    for (int counter : banknotes) {
        for (int i = 0; i < counter; i++) {
            flow.write((char*)&values[currentIndex], sizeof(int));
        }

        currentIndex++;
    }

    flow.close();
}

bool can_value_be_withdraw(int value) {
    // Creating var to count banknotes to withdraw
    int banknotesToWithdraw[6] = {0, 0, 0, 0, 0, 0};

    // If value doesn't end on two zeros it can't be withdrawal
    if (value % 100 != 0) {
        std::cout << "Value can't be withdrawn!\n Value must be multiple of 100!\n\n";
        return false;
    }

    // Counting how much banknotes each banknote need to be withdrawn
    int currentIndexValue = 5;

    while (currentIndexValue >= 0) {
        banknotesToWithdraw[currentIndexValue] = value / values[currentIndexValue];
        value -= values[currentIndexValue] * banknotesToWithdraw[currentIndexValue];
        currentIndexValue--;
    }

    // Checking if there are enough banknotes in ATM to withdraw the value
    for (int i = 0; i < 6; i++) {
        if (banknotes[i] < banknotesToWithdraw[i]) {
            std::cout << "Value can't be withdrawn!\n There's not enough banknotes of " << values[i] << " to withdraw!\n\n";
            return false;
        }
    }

    // Subtracting banknotes
    for (int i = 0; i < 6; i++) {
        banknotes[i] -= banknotesToWithdraw[i];
    }

    writingBanknotesIntoFile();

    return true;
}

void fillingTheATM() {
    // Making random work
    std::srand(std::time(nullptr));

    // Creating vars
    int counterOfBanknotes = 0, indexOfNewValue;

    // Counting the banknotes
    for (int i = 0; i < 6; i++) {
        counterOfBanknotes += banknotes[i];
    }

    // Filling the array with missing banknotes
    for (int i = 0; i < 1000 - counterOfBanknotes; i++) {
        indexOfNewValue = rand() % 6;

        banknotes[indexOfNewValue] += 1;
    }

    // Writing banknotes into file
    writingBanknotesIntoFile();
}




int main() {
    // Greetings
    std::cout << "\tATM at work\n\n\n";

    // Creating var
    char temp;


    while (true) {
        // Checking the ATM first
        checkingTheATM();

        // Check for an action
        std::cout << "Insert:" << std::endl <<
                        " '-' for cash withdrawal" << std::endl <<
                        " '+' for filling ATM with money (for collectors)" << std::endl <<
                        " '0' for exiting the program\n";
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
            if (can_value_be_withdraw(valueToWithdraw)) {
                std::cout << "Value has been withdrawn!\n\n";
            }
        }
        // Check if filling ATM with money
        else if (temp == '+') {
            fillingTheATM();
        }
        // Check if exiting the program
        else if (temp == '0') {
            std::cout << "Exiting the program...\n";
            break;
        }
        // Check for the wrong input
        else {
            std::cout << "Wrong input!\n Try insert new symbol properly!";
        }

        std::cout << "\n\n";
    }

    return 0;
}
