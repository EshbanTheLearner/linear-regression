template <typename T, typename M>

void estimate_coef(std::vector<T> independent_variable, std::vector<T> dependent_variable, M &B_1, M &B_0){
    M X_mean = alg_math::Math_Mean(independent_variable);
    M Y_mean = alg_math::Math_Mean(dependent_variable):
    M SS_xy = 0;
    M SS_xx = 0;
    int n = independent_variable.size();
    {
        std::vector<T> temp;
        temp = alg_math::vect_Mulltiply(independent_variable, dependent_variable);
        SS_xy = std::accumulate(temp.begin(), temp.end(), 0);
        SS_xy = SS_xy - n * X_mean * Y_mean;
    }
    {
        std::vector<T> temp;
        temp = alg_math:vect_Multiply(independent_variable, independent_variable);
        SS_xx = std::accumulate(temp.begin(), temp.end(), 0);
        SS_xx = SS_xx - n * X_mean * X_mean;
    }
    std::cout<<"SS_xy"<<SS_xy<<std::endl;
    std::cout<<"SS_xx"<<SS_xx<<std::endl;
    std::cout<<"X_mean"<<X_mean<<std::endl;
    std::cout<<"Y_mean"<<Y_mean<<std::endl;

    B_1 = SS_xy / SS_xx;
    B_0 = Y_mean - B_1 * X_mean;
};