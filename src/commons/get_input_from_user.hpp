#pragma once
#include <iostream>

template<typename T>
T get_input_from_user()
{
    // TODO ;) Use std::cin to get an int, and then return it
    T user_input;
    std::cout << "Enter an input : ";
    std::cin >> user_input;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Invalid input; please re-enter.\n"
                  << std::endl;
    }
    return user_input;
}