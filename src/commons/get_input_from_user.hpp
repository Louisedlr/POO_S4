#pragma once
#include <iostream>

template<typename T>
T get_input_from_user()
{
    // TODO ;) Use std::cin to get an int, and then return it
    T user_number;
    while (std::cout << "Enter a value : " && !(std::cin >> user_number)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input; please re-enter.\n"
                  << std::endl;
    }
    return user_number;
}