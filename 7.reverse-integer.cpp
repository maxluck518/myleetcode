class Solution {
public:
    int reverse(int x) {
        const uint32_t max = 0x7fffffff;
        const uint32_t min = 0x80000000;
        if(x == min)
            return 0;
        int y = abs(x);
        int ret = 0;
        while(y != 0){
            if(ret > max/10)
                return 0;
            ret = ret * 10 + y%10;
            y = y/10;
        }
        return x>0?ret:-ret;
    }
};
