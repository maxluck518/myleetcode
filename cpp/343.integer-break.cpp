class Solution {
public:
    int integerBreak(int n) {
        int *a = new int[n+1];
        a[0] = 0;
        a[1] = 1;
        a[2] = 1;
        a[3] = 2;
        if(n < 4) return a[n];
        for(int i = 3;i<n+1;i++){
            int tmp = 0x80000000;
            for(int k = 0;k<i;k++){
                tmp = max(tmp,k*a[i-k]);
            }
            a[i] = max(tmp,i);
        }
        return a[n];
    }
};
