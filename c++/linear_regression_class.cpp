template <typename X, typename Z>

class Linear_Regression{
    private:
    X b_0;
    X b_1;

    public:
    void fit(std::vector<std::vector<Z>> dataset){
        estimate_coef(dataset[0], dataset[1], b_1, b_0);
    }
    Z predict(const Z & test_data){
        return b_0 + (b_1 * test_data);
    }
};