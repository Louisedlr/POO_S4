#pragma once
#include <p6/p6.h>
#include <optional>

struct CellIndex {
    int x;
    int y;
};

float                    cell_radius(int board_size);
void                     draw_board(int size, p6::Context& ctx);
void                     draw_cell(CellIndex index, int board_size, p6::Context& ctx);
std::optional<CellIndex> cell_hovered_by(glm::vec2 position, int board_size);

void play_noughts_and_crosses();
