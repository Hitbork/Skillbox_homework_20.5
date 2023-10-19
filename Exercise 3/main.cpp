#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Greetings
    std::cout << "Let's go fishing!\n\n\n" << std::endl;

    // Creating vars
    int amountOfFishes = 0;
    std::string fishCatching, currentFish;

    // Requesting data
    std::cout << "Insert which fish you want to catch:\n";
    std::cin >> fishCatching;
    std::cout << std::endl;

    // Creating the flow to read
    std::ifstream river("C:\\TXT\\Skillbox\\Module 20\\3_river.txt");

    // Check if file couldn't be opened
    if (!river.is_open()) {
        std::cout << "Error! File river.txt could be opened! Try again!\n";
        return 1;
    }

    // Creating the flow to write into
    std::ofstream basket("C:\\TXT\\Skillbox\\Module 20\\3_basket.txt", std::ios::app);

    // Check if file couldn't be opened
    if (!basket.is_open()) {
        std::cout << "Error! File bascket.txt could be opened! Try again!\n";
        return 1;
    }

    // Cycle until river would be ended
    while (!river.eof()) {
        river >> currentFish;
        if (currentFish == fishCatching) {
            // Writing fish into the list of basket
            basket << fishCatching << "\n";

            // Adding 1 more to the fish counter
            amountOfFishes++;
        }
    }

    // Closing files
    river.close();
    basket.close();

    // Output
    std::cout << "You caught " << amountOfFishes << " " << fishCatching << "!\n";

    return 0;
}
