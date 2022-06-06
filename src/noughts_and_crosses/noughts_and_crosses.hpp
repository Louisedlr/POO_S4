#pragma once
#include <p6/p6.h>
#include <optional>
#include "Board.hpp"

std::optional<CellIndex> cell_hovered_by(const glm::vec2 position, const int board_size);

void play_noughts_and_crosses();
bool play_can_play(Board board, const int count, const std::optional<CellIndex> object_to_draw);