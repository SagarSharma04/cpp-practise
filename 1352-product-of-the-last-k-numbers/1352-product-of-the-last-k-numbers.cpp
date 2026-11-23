class ProductOfNumbers {
public:
    vector<int>arr;
    ProductOfNumbers() {
        vector<int>arr{};
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int n = arr.size();
        int x = 1;
        while(k--){
            x *= arr[n-1];
            n--;
        }
        return x;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */