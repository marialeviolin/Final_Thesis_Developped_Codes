#pragma once
#include "Matrix.hpp"

Vec4 computeLQRGain(const Mat4& A, const Vec4& B, const Mat4& Q, double R);