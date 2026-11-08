#pragma once
# include <array>

using Vec4 = std::array<double, 4>;
using Mat4 = std::array<std::array<double, 4>, 4>;

Mat4 zeros();
Mat4 identity();
Mat4 transpose(const Mat4& a);
Mat4 multiply(const Mat4& a, const Mat4& b);
Vec4 multiply(const Mat4& a, const Vec4& v);
Mat4 outer(const Vec4& u, const Vec4& v);
Mat4 add(const Mat4& a, const Mat4& b);
Mat4 scale(double k, const Mat4& a);