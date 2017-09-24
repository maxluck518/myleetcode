class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray_set;
        int maxCode = 1;
        for(int i = 0;i<n;i++){
            maxCode = maxCode << 1;
        }

        for(int i = 0;i<maxCode;i++){
            int tmp1 = i;
            int tmp2 = i/2;
            int gray = tmp1 ^ tmp2;
            gray_set.push_back(gray);
        }
        return gray_set;
    }
};
