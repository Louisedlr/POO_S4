#include "./noughts_and_crosses.hpp"
#include <p6/p6.h>
#include <iostream>
#include <optional>

std::optional<CellIndex> cell_hovered_by(glm::vec2 position, int board_size)
{
    const auto pos   = p6::map(position,
                             glm::vec2{-1.f}, glm::vec2{1.f},
                             glm::vec2{0.f}, glm::vec2{float(board_size)});
    const auto index = CellIndex{
        int(std::floor(pos.x)),
        int(std::floor(pos.y))};
    if (index.x >= 0 && index.x < board_size &&
        index.y >= 0 && index.y < board_size) {
        return std::make_optional(index);
    }
    else {
        return std::nullopt;
    }
}

void play_noughts_and_crosses()
{
    static constexpr int board_size = 3;
    Board                board(board_size);
    board.print_board();
    auto ctx    = p6::Context{{800, 800, "Noughts and Crosses"}};
    bool player = true;

    ctx.mouse_pressed = [&](p6::MouseButton event) {
        ctx.circle(p6::Center{event.position},
                   p6::Radius{0.2f});
    };
    ctx.update = [&]() {
        ctx.background({171 / 255.f, 212 / 255.f, 235 / 255.f});
        ctx.stroke_weight = 0.01f;
        ctx.stroke        = {1.f, 1.f, 1.f, 1.f};
        ctx.fill          = {0.f, 0.f, 0.f, 0.f};
        board.draw_board(board_size, ctx);
        const auto hovered_cell = cell_hovered_by(ctx.mouse(), board_size);
        if (hovered_cell.has_value() & player) {
            ctx.fill = {74 / 255.f, 137 / 255.f, 255 / 255.f, 1.f};
            // draw_cell(*hovered_cell, board_size, ctx);
            draw_nought(*hovered_cell, board_size, ctx);
        }
        if (hovered_cell.has_value() & !player) {
            ctx.fill = {74 / 255.f, 137 / 255.f, 255 / 255.f, 1.f};
            draw_cross(*hovered_cell, board_size, ctx);
        }

        ctx.mouse_pressed = [&](p6::MouseButton event) {
            const auto object_to_draw = cell_hovered_by(event.position, board_size);
            if (player) {
                board.add_nought(object_to_draw);
                player = !player;
            }
            else {
                board.add_cross(object_to_draw);
                player = !player;
            }
        };
    };

    ctx.start();
}