#include "Matrix.hpp"

Mat4 zeros() {
    Mat4 r{};
    return r;
}

Mat4 identity(){
    Mat4 r=zeros();
    for (int i = 0; i < 4; ++i) {
        r[i][i] = 1.0;
    }
    return r;
}

Mat4 transpose(const Mat4& a) {
    Mat4 r=zeros();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            r[i][j] = a[j][i];
        }
    }
    return r;
} 

Mat4 multiply(const Mat4& a, const Mat4& b) {
    Mat4 r=zeros();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return r;
}

Vec4 multiply(const Mat4& a, const Vec4& v) {
    Vec4 r{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            r[i] += a[i][j] * v[j];
        }
    }
    return r;
}

Mat4 outer(const Vec4& u, const Vec4& v) {
    Mat4 r=zeros();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            r[i][j] = u[i] * v[j];
        }
    }
    return r;
}

Mat4 add(const Mat4& a, const Mat4& b) {
    Mat4 r=zeros();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
    return r;
}

Mat4 scale(double k, const Mat4& a) {
    Mat4 r=zeros();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            r[i][j] = k * a[i][j];
        }
    }
    return r;
}