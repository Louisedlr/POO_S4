#pragma once
#include <p6/p6.h>
#include <iostream>
#include <vector>

class Board {
private:
    size_t            _size;
    std::vector<char> _board;

public:
    //void draw_board(int size, p6::Context& ctx);
    Board(size_t size, std::vector<char> board = std::vector<char>(10, ' '))
        : _size(size), _board(board)
    {
    }
    int               get_size() { return _size; }
    std::vector<char> get_board() { return _board; }
    void              print_board()
    {
        for (const auto& x : _board) {
            std::cout << x << ",";
        }
        std::cout << std::endl;
    }
};
