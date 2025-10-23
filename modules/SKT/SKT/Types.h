#pragma once

#include <string>


namespace SKT {

// Common types
using String  = std::string;
using Boolean = bool;
using Real    = float;
using Integer = int;
// using Integer2 = glm::i64vec2;
// using Integer3 = glm::i64vec3;
// using Integer4 = glm::i64vec4;
// using Vec2     = glm::vec2;
// using Vec3     = glm::vec3;
// using Vec4     = glm::vec4;
// using Mat3     = glm::mat3;
// using Mat4     = glm::mat4;

// Mouse
enum class Buttons { Left, Middle, Right };

// Keyboard
enum class Keys { Escape, A };

}// namespace SKT
