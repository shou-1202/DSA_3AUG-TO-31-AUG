class Solution {
public:
    int countDigitOne(int n) {
        if(n==0)return 0;
        if(n<=9)return 1;

        int count = 0;
        for(long long factor = 1; factor<=n; factor*=10){
            long long higher = n/(factor*10);
            long long current = (n/factor)%10;
            long long lower = n%factor;

            if(current == 0){
                count += higher*factor;
            }
            else if(current == 1){
                count += higher*factor+1+lower;
            }
            else{
                count += (higher+1)*factor;
            }

        }
        return count;
    }
};