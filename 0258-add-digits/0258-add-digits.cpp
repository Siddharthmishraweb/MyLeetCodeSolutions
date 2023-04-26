class Solution {
public:
    int addDigits(int num) {
        int n = num;
        int sum = 0;
        while(n != 0 ){
            int k = n % 10;
            
            n = n / 10;
            sum += k;
            cout<<k<<", sum"<<sum<<endl;
        }
        if(sum < 10)
            return sum;
        else
            return addDigits(sum);

         return 12;
    }
};