#pragma once
#include <p6/p6.h>
#include <iostream>
#include <optional>
#include <vector>

struct CellIndex {
    int x;
    int y;
};

class Board {
private:
    size_t                                _size;
    std::vector<char>                     _board;
    std::vector<std::optional<CellIndex>> cross_to_draw;
    std::vector<std::optional<CellIndex>> nought_to_draw;

public:
    //void draw_board(int size, p6::Context& ctx);
    Board(size_t size, std::vector<char> board = std::vector<char>(10, ' '))
        : _size(size), _board(board)
    {
    }
    int               get_size() { return _size; }
    std::vector<char> get_board() { return _board; }
    void              add_cross(std::optional<CellIndex> cross)
    {
        cross_to_draw.push_back(cross);
    }
    void add_nought(std::optional<CellIndex> nought)
    {
        nought_to_draw.push_back(nought);
    }
    void print_board()
    {
        for (const auto& x : _board) {
            std::cout << x << ",";
        }
        std::cout << std::endl;
    }
    void draw_board(int size, p6::Context& ctx);
};

float     cell_radius(int board_size);
glm::vec2 cell_bottom_left_corner(CellIndex index, int board_size);
void      draw_cell(CellIndex index, int board_size, p6::Context& ctx);
glm::vec2 cell_center(CellIndex index, int board_size);
void      draw_nought(CellIndex index, int board_size, p6::Context& ctx);
void      draw_cross(CellIndex index, int board_size, p6::Context& ctx);