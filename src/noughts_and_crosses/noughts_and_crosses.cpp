#include "./noughts_and_crosses.hpp"
#include <p6/p6.h>

void draw_board()
{

}

void play_noughts_and_crosses()
{
    auto ctx   = p6::Context{{800, 800, "Noughts and Crosses"}};
    ctx.update = [&](){
        ctx.background({1.f, 1.f, 1.f});
        ctx.circle(p6::Center{ctx.mouse()}, // Draw a circle centered on the mouse cursor
                   p6::Radius{0.3f}); 
    };
    ctx.start();

}