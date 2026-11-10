#include "BackwardPass.hpp"

std::vector<Vec4> backwardPass(const Mat4& A, const Vec4& B, const Mat4& Q, double R, const Mat4& Qf, int N, double dt){

    const Mat4 At=transpose(A);
    std::vector<Vec4>K(N+1);
    Mat4 P=Qf;
    for(int k=N;k>=0;--k){
        Vec4 Kk=multiply(P,B);
        for (int i=0;i<4;++i) Kk[i]/=R;

        K[k]=Kk;
    }
} 