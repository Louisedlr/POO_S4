#include "hangman.hpp"
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "../commons/get_input_from_user.hpp"
#include "../commons/rand.hpp"

const std::string pick_a_random_word()
{
    const std::array<std::string, 5> words        = {"bonjour", "courgette", "biscuit", "plante", "cactus"};
    int                              random_index = rand<int>(0, words.size() - 1);
    return words[random_index];
}

bool is_user_input_is_in_word(char user_input, std::string word, std::string& display_word, unsigned int& letters_found)
{
    bool is_in_word;
    for (unsigned int i = 0; i < word.size(); i++) {
        if (word[i] == user_input) {
            display_word[i] = user_input;
            letters_found++;
            is_in_word = true;
        }
    }
    if (is_in_word) {
        return true;
    }
    else {
        return false;
    }
}

void display_end_game(int& player_life)
{
    if (player_life == 0) {
        std::cout << "Too bad your lost :(" << std::endl;
    }
    else {
        std::cout << "Congrats, you won ! " << std::endl;
    }
}

void play_hangman()
{
    int               player_life = 8;
    char              user_input;
    unsigned int      letters_found = 0;
    const std::string random_word   = pick_a_random_word();
    std::string       display_word(random_word.size(), '_');
    while (letters_found < random_word.size() && player_life > 0) {
        std::cout << "You have " << player_life << " lives." << std::endl;
        std::cout << display_word;
        std::cout << std::endl;
        user_input = get_input_from_user<char>();
        if (!is_user_input_is_in_word(user_input, random_word, display_word, letters_found)) {
            player_life--;
        }
    }
    std::cout << "The word is : " << random_word << std::endl;

    display_end_game(player_life);
}