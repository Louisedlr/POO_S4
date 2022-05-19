#pragma once
#include <p6/p6.h>
#include <optional>
#include "Board.hpp"

struct CellIndex {
    int x;
    int y;
};

float                    cell_radius(int board_size);
void                     draw_board(int size, p6::Context& ctx);
void                     draw_cell(CellIndex index, int board_size, p6::Context& ctx);
std::optional<CellIndex> cell_hovered_by(glm::vec2 position, int board_size);
glm::vec2                cell_bottom_left_corner(CellIndex index, int board_size);
glm::vec2                cell_center(CellIndex index, int board_size);

void draw_nought(CellIndex index, int board_size, p6::Context& ctx);
void draw_cross(CellIndex index, int board_size, p6::Context& ctx);

void play_noughts_and_crosses();
