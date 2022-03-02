#include "menu.hpp"
#include <iostream>
#include <string>
#include "../guess_the_number/guess_the_number.hpp"
#include "../hangman/hangman.hpp"

void menu()
{
    char user_input;
    std::cout << "What do you want to do ? " << std::endl;
    std::cout << "1 : Play \" Guess the Number \" " << std::endl;
    std::cout << "2 : Play \" Hangman \" " << std::endl;
    std::cout << "other : Quit " << std::endl;
    std::cin >> user_input;
    check_user_input(user_input);
}

void check_user_input(char& user_input)
{
    if (user_input == '1') {
        play_guess_the_number();
    }
    else if (user_input == '2') {
        play_hangman();
    }
    else {
        return;
    }
}