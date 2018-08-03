class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string > ret;
        string str;
        if(n == 0)
            return ret;
        pushParenthesis(ret,str,n,0);
        return ret;
    }
    void pushParenthesis(vector<string> &ret,string str,int n,int m) {
        if(m == 0 && n == 0){
            ret.push_back(str);
            return ;
        }
        if(m>0) pushParenthesis(ret,str+")",n,m-1);
        if(n>0) pushParenthesis(ret,str+"(",n-1,m+1);
    }
};
