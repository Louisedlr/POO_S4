#include "./noughts_and_crosses.hpp"
#include <p6/p6.h>
#include <iostream>
#include <optional>

float cell_radius(int board_size)
{
    return 1.f / static_cast<float>(board_size);
}

void draw_cell(CellIndex index, int board_size, p6::Context& ctx)
{
    ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{static_cast<float>(index.x), static_cast<float>(index.y)},
                                            glm::vec2{0.f}, glm::vec2{static_cast<float>(board_size)},
                                            glm::vec2{-1.f}, glm::vec2{1.f})},
               p6::Radius{1.f / static_cast<float>(board_size)});
}

void draw_board(int size, p6::Context& ctx)
{
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y) {
            draw_cell({x, y}, size, ctx);
        }
    }
}

std::optional<CellIndex> cell_hovered_by(glm::vec2 position, int board_size)
{
    const auto pos   = p6::map(position,
                             glm::vec2{-1.f}, glm::vec2{1.f},
                             glm::vec2{0.f}, glm::vec2{static_cast<float>(board_size)});
    const auto index = CellIndex{
        static_cast<int>(std::floor(pos.x)),
        static_cast<int>(std::floor(pos.y))};
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
    auto                 ctx        = p6::Context{{800, 800, "Noughts and Crosses"}};
    ctx.update                      = [&]() {
        ctx.background({171 / 255.f, 212 / 255.f, 235 / 255.f});
        ctx.stroke_weight = 0.01f;
        ctx.stroke        = {1.f, 1.f, 1.f, 1.f};
        ctx.fill          = {0.f, 0.f, 0.f, 0.f};
        draw_board(board_size, ctx);
        const auto hovered_cell = cell_hovered_by(ctx.mouse(), board_size);
        if (hovered_cell.has_value()) {
            ctx.fill = {74 / 255.f, 137 / 255.f, 255 / 255.f, 1.f};
            draw_cell(*hovered_cell, board_size, ctx);
        }
    };
    ctx.start();
}