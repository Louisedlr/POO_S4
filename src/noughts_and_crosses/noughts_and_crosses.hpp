#pragma once
#include <p6/p6.h>
#include <optional>
#include "Board.hpp"

std::optional<CellIndex> cell_hovered_by(glm::vec2 position, int board_size);

void play_noughts_and_crosses();
bool play_can_play(Board board, int count, std::optional<CellIndex> object_to_draw);
bool cross_win(Board board, std::optional<CellIndex> object_to_draw);
