class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int len = flowerbed.size();
        if(len == 1)
            cnt = flowerbed[0]? 0:1;
        // else if(len == 2)
            // cnt = flowerbed[0] + flowerbed[1] == 0? 1:0;
        else{
            if(flowerbed[0] + flowerbed[1] == 0){
                flowerbed[0] = 1;
                cnt++;
            }
            flowerbed.push_back(0);
            for(int i = 1;i<len;i++){
                if(flowerbed[i-1] +flowerbed[i] +flowerbed[i+1] == 0){
                    cnt ++;
                    flowerbed[i]= 1;
                }
            }
        }
        return cnt>=n? true:false;
    }
};

