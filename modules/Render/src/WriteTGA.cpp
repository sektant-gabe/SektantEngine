#include "WriteTGA.h"

void WriteTGA()
{
    TGAImage framebuffer(width, height, TGAImage::RGB);
    framebuffer.set(ax, ay, white);
    framebuffer.set(bx, by, white);
    framebuffer.set(cx, cy, white);

    framebuffer.write_tga_file("framebuffer.tga");
};
