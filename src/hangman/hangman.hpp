#pragma once
#include <string>

const std::string pick_a_random_word();
bool              is_user_input_is_in_word(char user_input, std::string word, std::string& display_word, unsigned int& letters_found);
void              display_end_game(int& player_life);
void              play_hangman();
