#include "./noughts_and_crosses.hpp"
#include <p6/p6.h>
#include <iostream>

struct CellIndex
{
    float x;
    float y;
};

void draw_board(int size, p6::Context& ctx)
{
    for (int x = 0; x < size; ++x) {
            for (int y = 0; y < size; ++y) {
                ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{static_cast<float>(x), static_cast<float>(y)},
                                                        glm::vec2{0.f}, glm::vec2{static_cast<float>(size)},
                                                        glm::vec2{-1.f}, glm::vec2{1.f})},
                        p6::Radius{1.f / static_cast<float>(size)});
            }
        }
}

void play_noughts_and_crosses()
{
    auto ctx   = p6::Context{{800, 800, "Noughts and Crosses"}};
    ctx.update = [&]() {
        ctx.background({171/255.f, 212/255.f, 235/255.f});
        ctx.stroke_weight = 0.02f;
        ctx.stroke        = {1.f, 1.f, 1.f, 1.f};
        //171, 212, 235
        //ctx.fill          = {1.f, 1.f, 1.f, 0.f};
        draw_board(4, ctx);
    };
    ctx.start();

}