#include "Render/WriteTGA.h"
#include "SKT/Window.h"

namespace SKT {


void WriteTGA()
{
    TGAImage framebuffer(SKT::WINDOW_WIDTH, SKT::WINDOW_HEIGHT, TGAImage::RGB);
    framebuffer.set(ax, ay, white);
    framebuffer.set(bx, by, white);
    framebuffer.set(cx, cy, white);

    framebuffer.write_tga_file("framebuffer.tga");
};


};// namespace SKT
