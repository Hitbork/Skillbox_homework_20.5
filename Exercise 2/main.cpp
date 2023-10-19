#include <iostream>
#include <fstream>
#include <ctime>

int main() {
    // Correcting random numbers
    std::srand(std::time(nullptr));

    // Greetings
    std::cout << "Drawing a picture\n\n\n";

    // Creating vars
    int x, y;

    // Requesting length and width
    std::cout << "Insert length and width of generating picture:\n";
    std::cin >> x >> y;
    std::cout << std::endl;

    // Creating the flow
    std::ofstream picture("C:\\TXT\\Skillbox\\Module 20\\2.txt");

    // Check if file could be opened
    if (!picture.is_open()) {
        std::cout << "Error! Couldn't open the file!\n";
        return 1;
    } else {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                picture << rand() % 2;
            }

            picture << std::endl;
        }
    }

    picture.close();

    // Output
    std::cout << "Picture created successfully!\n";
    return 0;
}
