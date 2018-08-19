/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
bool cmp(const Point &a,const Point &b){
    if(a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}
int gcd(int a,int b){
    if(a < b){
        int tmp = a;
        a = b;
        b = a;
    }
    if(b == 0) return a;
    else return gcd(b,a%b);
}
pair<int,int> get_slope(int a,int b){
    if(a < 0){
        a = -a;
        b = -b;
    }
    if(a == 0) return make_pair(0x7fffffff,0x7fffffff);
    else {
        int tmp = gcd(a,b);
        return make_pair(a/tmp,b/tmp);
    }
}
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        int res = 0;
        for(int i = 0;i<n;i++){
            int same_point = 1;
            map<pair<int,int>,int> line;
            line.insert(make_pair(make_pair(0,0),0));
            line.insert(make_pair(make_pair(0x7fffffff,0x7fffffff),0));
            for(int k = i+1;k<n;k++){
                int a = points[i].x - points[k].x;
                int b = points[i].y - points[k].y;
                pair<int,int> tmp = make_pair(a,b);
                if(a == 0 && b == 0){
                    same_point ++;
                    continue;
                }
                else if(a == 0){
                    a = 0x7fffffff;
                    b = 0x7fffffff;
                }
                else if(b == 0){
                    a = 0;
                    b = 0;
                }
                else{
                    tmp = get_slope(a,b);
                }

                auto it = line.find(tmp);
                if(it == line.end()){
                    line.insert(make_pair(tmp,1));
                }
                else{
                    it -> second ++;
                    res = max(res,it->second);
                }
            }
            for(auto it = line.begin();it != line.end();it++){
                res = max(res,it->second+same_point);
            }
        }

        return res;
    }
};
