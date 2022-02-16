#include <iostream>
#include "../commons/get_input_from_user.hpp"
#include "../commons/rand.hpp"

void play_guess_the_number()
{
    int  random_number = rand<int>(0, 100);
    bool finished      = false;
    int  user_number;
    while (!finished) {
        user_number = get_input_from_user<int>();
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
