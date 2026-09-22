class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int d=n;
        while(n>0){
            int digit=n%10;
            n=n/10;
            sum=sum+digit;
            prod=prod*digit;
        }
        return d % (sum+prod) == 0;
    }
};
