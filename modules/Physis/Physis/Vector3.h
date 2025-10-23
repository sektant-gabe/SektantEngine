#pragma once
#include <ostream>

namespace SKT {

class Vector3
{
public:
    // Vector Data
    union {
        double data[3]{};

        struct
        {
            double x, y, z;
        };
    };

    Vector3();

    Vector3(double x, double y, double z);
    explicit Vector3(const double data[3]);

    // Vector / Vector Assignments
    Vector3 &operator+=(const Vector3 &rhs);
    Vector3 &operator-=(const Vector3 &rhs);
    Vector3 &operator*=(const Vector3 &rhs);
    Vector3 &operator/=(const Vector3 &rhs);

    // Vector / Scalar Assignments
    Vector3 &operator+=(double scalar);
    Vector3 &operator-=(double scalar);
    Vector3 &operator*=(double scalar);
    Vector3 &operator/=(double scalar);

    // Special Object Creators
    static const Vector3 xAxis();
    static const Vector3 yAxis();
    static const Vector3 zAxis();
};

// Vector / Vector Elementwise Operations
Vector3 operator-(const Vector3 &rhs);
Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator*(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator/(const Vector3 &lhs, const Vector3 &rhs);

// Vector / Scalar Operations
Vector3 operator+(const Vector3 &lhs, double scalar);
Vector3 operator-(const Vector3 &lhs, double scalar);
Vector3 operator*(const Vector3 &lhs, double scalar);
Vector3 operator/(const Vector3 &lhs, double scalar);
Vector3 operator+(double scalar, const Vector3 &rhs);
Vector3 operator-(double scalar, const Vector3 &rhs);
Vector3 operator*(double scalar, const Vector3 &rhs);
Vector3 operator/(double scalar, const Vector3 &rhs);

// Vector Operations
double  norm(const Vector3 &rhs);
void    normlize(Vector3 &rhs);
Vector3 unit(const Vector3 &rhs);
Vector3 cross(const Vector3 &lhs, const Vector3 &rhs);
double  dot(const Vector3 &lhs, const Vector3 &rhs);

// Stream Functions
std::ostream &operator<<(std::ostream &output, const Vector3 &obj);

}// namespace SKT
