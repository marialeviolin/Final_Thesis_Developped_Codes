# include "Riccati.hpp"
# include <cmath>

Vec4 computeLQRGain(const Mat4& A, const Vec4& B, const Mat4& Q, double R) {
    const double dtau=1e-3;
    const int max_iter=2000000;
    const double tol=1e-9;
    const Mat4 At=transpose(A);
    Mat4 P=zeros();

    for (int it=0; it<max_iter; ++it){

        const Vec4 PB=multiply(P,B);
        Mat4 dP=add(multiply(At, P),multiply(P,A));
        dP=add(dP,scale(-1.0/R,outer(PB,PB)));
        dP=add(dP,Q);

        P=add(P, scale(dtau,dP));
        double max_dP=0.0;
        
        for(int i=0;i<4;++i)
            for(int j=0; j<4;++j)
                 if(std::fabs(P[i][j])>max_dP)max_dP=std::fabs(dP[i][j]);
        if(max_dP<tol) break;
    }

Vec4 K=multiply(P,B);
for (int i=0;i<4;++i) K[i]/R;

return K;
}