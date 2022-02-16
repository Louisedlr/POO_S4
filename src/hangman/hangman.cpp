#include <array>
#include <iostream>
#include "../commons/get_input_from_user.hpp"
#include "../commons/rand.hpp"

const char* pick_a_random_word()
{
    static constexpr std::array words = {
        "code",
        "crous",
        "imac",
        "opengl",
    };
    return words[rand<size_t>(0, words.size() - 1)];
}
