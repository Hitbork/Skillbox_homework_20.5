#include <iostream>
#include <fstream>
#include <string>

bool is_date_right(std::string &date) {
    int dateNumbers[3];

    for (int i = 0; i < 2; i++) {
        dateNumbers[i] = std::stoi(date.substr(0, date.find('.')));
        date.erase(0, date.find('.') + 1);
    }

    dateNumbers[2] = std::stoi(date);
/*

    bool isLeapYear = std::stoi(date.substr(date.rfind('.'), 4)) % 4 == 0;
*/
    // Check if month is validating
    if (dateNumbers[1] <= 12) {
        // Check if month is odd number
        if ((dateNumbers[1] % 2 == 1 && dateNumbers[1] <= 7)
            || (dateNumbers[1] % 2 == 0 && dateNumbers[1] >= 8)) {
            return dateNumbers[0] <= 31;
        } else {
            // Check if month isn't February
            if (dateNumbers[1] != 2) {
                return dateNumbers[0] <= 30;
            } else {
                // Check if year is leap
                if (dateNumbers[2] % 4 == 0) {
                    return dateNumbers[0] <= 29;
                } else {
                    return dateNumbers[0] <= 28;
                }
            }
        }
    }

}

int main() {
    // Greetings
    std::cout << "Inputting new info into payment statement\n\n\n";

    // Creating vars
    std::string name, secondName, date;
    int value;

    while (true) {
        // Requesting string to input
        std::cout << "Insert new string to input in the statement:\n";
        std::cin >> name >> secondName >> date >> value;
        std::cout << std::endl;

        // Opening the file
        std::ofstream file("C:\\TXT\\Skillbox\\Module 20\\1.txt", std::ios::app);

        // Check if file could be opened
        if (!file.is_open()) {
            std::cout << "Error! File can't be opened!";
            return 1;
        } else {
            if (!is_date_right(date)) {
                std::cout << "Date isn't validated. Try again.\n";
                return 1;
            } else {
                file << name << " " << secondName << " " << date << " " << value << "\n";
            }
        }

        std::cout << "String added successfully!\n\n";
        file.close();
    }
}
