#include <iostream>
#include "../commons/rand.hpp"

int get_int_from_user()
{
    // TODO ;) Use std::cin to get an int, and then return it
    int user_number;
    while (std::cout << "Enter a number : " && !(std::cin >> user_number)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input; please re-enter.\n"
                  << std::endl;
    }
    return user_number;
}

void play_guess_the_number()
{
    int  random_number = rand<int>(0, 100);
    bool finished      = false;
    int  user_number;
    while (!finished) {
        user_number = get_int_from_user();
        if (user_number == random_number) {
            std::cout << "Congrats, you won ! " << std::endl;
            finished = true;
        }
        else if (user_number < random_number) {
            std::cout << "Greater " << std::endl;
        }
        else {
            std::cout << "Smaller" << std::endl;
        }
    }
}
