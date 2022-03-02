#include "menu.hpp"
#include <iostream>
#include <string>
#include "../guess_the_number/guess_the_number.hpp"
#include "../hangman/hangman.hpp"

void menu()
{
    bool quit = false;
    while (!quit) {
        char user_input;
        std::cout << "What do you want to do ? " << std::endl;
        std::cout << "1 : Play \" Guess the Number \" " << std::endl;
        std::cout << "2 : Play \" Hangman \" " << std::endl;
        std::cout << "q : Quit " << std::endl;
        std::cin >> user_input;
        check_user_input(user_input, quit);
    }
    return;
}

void check_user_input(char& user_input, bool quit)
{
    switch (user_input) {
    case '1':
        play_guess_the_number();
        break;
    case '2':
        play_hangman();
        break;
    case 'q':
        quit = true;
        break;
    default:
        std::cout << "Sorry I don't know that command!\n";
        break;
    }
}