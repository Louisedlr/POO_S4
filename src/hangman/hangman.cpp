#include "hangman.hpp"
#include <array>
#include <iostream>
#include <string>
#include "../commons/get_input_from_user.hpp"
#include "../commons/rand.hpp"

const std::string pick_a_random_word()
{
    const std::array<std::string, 5> words        = {"bonjour", "courgette", "biscuit", "plante", "cactus"};
    int                              random_index = rand<int>(0, words.size() - 1);
    std::cout << words[random_index] << std::endl;
    return words[random_index];
}

void play_hangman()
{
    int               player_life = 8;
    std::string       user_input;
    bool              is_winning  = false;
    const std::string random_word = pick_a_random_word();
    bool              is_in_word  = false;
    while (player_life > 0 && !is_winning) {
        std::cout << "You have " << player_life << " lives." << std::endl;
        for (auto it = random_word.begin(); it != random_word.end(); ++it) {
            std::cout << "_";
        }
        std::cout << std::endl;
        user_input = get_input_from_user<std::string>();
        player_life--;
    }
}