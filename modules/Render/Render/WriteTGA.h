#pragma once
#include "TGAImage.h"

namespace SKT {

constexpr TGAColor white{{255, 255, 255, 255}};// attention, BGRA order
constexpr TGAColor green{{0, 255, 0, 255}};
constexpr TGAColor red{{0, 0, 255, 255}};
constexpr TGAColor blue{{255, 128, 64, 255}};
constexpr TGAColor yellow{{0, 200, 255, 255}};

constexpr int ax = 7, ay = 3;
constexpr int bx = 12, by = 37;
constexpr int cx = 62, cy = 53;


void WriteTGA();
};// namespace SKT
