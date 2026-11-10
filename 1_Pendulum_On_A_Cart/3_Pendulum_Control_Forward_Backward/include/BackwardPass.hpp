# pragma once
#include <vector>
#include "Matrix.hpp"

std::vector<Vec4> backwardPass (const Mat4& A, const Vec4& B, const Mat4& Q, double R, const Mat4& Qf, int N, double dt);