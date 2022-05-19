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
    ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{float(index.x), float(index.y)},
                                            glm::vec2{0.f}, glm::vec2{float(board_size)},
                                            glm::vec2{-1.f}, glm::vec2{1.f})},
               p6::Radius{1.f / float(board_size)});
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
glm::vec2 cell_bottom_left_corner(CellIndex index, int board_size)
{
    const auto idx = glm::vec2{static_cast<float>(index.x),
                               static_cast<float>(index.y)};
    return p6::map(idx,
                   glm::vec2{0.f}, glm::vec2{static_cast<float>(board_size)},
                   glm::vec2{-1.f}, glm::vec2{1.f});
}

glm::vec2 cell_center(CellIndex index, int board_size)
{
    return cell_bottom_left_corner(index, board_size) + cell_radius(board_size);
}

void draw_nought(CellIndex index, int board_size, p6::Context& ctx)
{
    ctx.stroke        = {74 / 255.f, 137 / 255.f, 255 / 255.f, 1.f};
    ctx.fill          = {74 / 255.f, 137 / 255.f, 255 / 255.f, 1.f};
    ctx.stroke_weight = 0.4f * cell_radius(board_size);
    ctx.circle(p6::Center{cell_center(index, board_size)},
               p6::Radius{0.9f * cell_radius(board_size)});
    ctx.stroke = {171 / 255.f, 212 / 255.f, 235 / 255.f};
    ctx.fill   = {171 / 255.f, 212 / 255.f, 235 / 255.f};
    ctx.circle(p6::Center{cell_center(index, board_size)},
               p6::Radius{0.6f * cell_radius(board_size)});
}

void draw_cross(CellIndex index, int board_size, p6::Context& ctx)
{
    ctx.stroke          = {74 / 255.f, 137 / 255.f, 255 / 255.f, 1.f};
    ctx.fill            = {74 / 255.f, 137 / 255.f, 255 / 255.f, 1.f};
    ctx.stroke_weight   = 0.4f * cell_radius(board_size);
    const auto center   = p6::Center{cell_center(index, board_size)};
    const auto radii    = p6::Radii{glm::vec2{1.f, 0.2f} * cell_radius(board_size)};
    const auto rotation = p6::Rotation{0.125_turn};
    ctx.rectangle(center, radii, rotation);
    ctx.rectangle(center, radii, -rotation);
}

void play_noughts_and_crosses()
{
    static constexpr int board_size = 3;
    Board                board(board_size);
    board.print_board();
    auto ctx = p6::Context{{800, 800, "Noughts and Crosses"}};

    ctx.mouse_pressed = [&](p6::MouseButton event) {
        ctx.circle(p6::Center{event.position},
                   p6::Radius{0.2f});
    };
    ctx.update = [&]() {
        ctx.background({171 / 255.f, 212 / 255.f, 235 / 255.f});
        ctx.stroke_weight = 0.01f;
        ctx.stroke        = {1.f, 1.f, 1.f, 1.f};
        ctx.fill          = {0.f, 0.f, 0.f, 0.f};
        draw_board(board_size, ctx);
        const auto hovered_cell = cell_hovered_by(ctx.mouse(), board_size);
        if (hovered_cell.has_value()) {
            ctx.fill = {74 / 255.f, 137 / 255.f, 255 / 255.f, 1.f};
            // draw_cell(*hovered_cell, board_size, ctx);
            draw_nought(*hovered_cell, board_size, ctx);
        }
    };

    ctx.start();
}