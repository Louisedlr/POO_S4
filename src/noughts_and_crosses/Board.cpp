#include "Board.hpp"

void draw_cell(CellIndex index, const int board_size, p6::Context& ctx)
{
    ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{float(index.x), float(index.y)},
                                            glm::vec2{0.f}, glm::vec2{float(board_size)},
                                            glm::vec2{-1.f}, glm::vec2{1.f})},
               p6::Radius{1.f / float(board_size)});
}

float cell_radius(const int board_size)
{
    return 1.f / static_cast<float>(board_size);
}

glm::vec2 cell_bottom_left_corner(const CellIndex index, const int board_size)
{
    const auto idx = glm::vec2{static_cast<float>(index.x),
                               static_cast<float>(index.y)};
    return p6::map(idx,
                   glm::vec2{0.f}, glm::vec2{static_cast<float>(board_size)},
                   glm::vec2{-1.f}, glm::vec2{1.f});
}

glm::vec2 cell_center(const CellIndex index, const int board_size)
{
    return cell_bottom_left_corner(index, board_size) + cell_radius(board_size);
}

void draw_nought(const CellIndex index, const int board_size, p6::Context& ctx)
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

void draw_cross(const CellIndex index, const int board_size, p6::Context& ctx)
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

void Board::draw_board(const int size, p6::Context& ctx)
{
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y) {
            draw_cell({x, y}, size, ctx);
        }
    }
    for (auto x : _cross_to_draw) {
        draw_cross(x.value(), size, ctx);
    }
    for (auto x : _nought_to_draw) {
        draw_nought(x.value(), size, ctx);
    }
}