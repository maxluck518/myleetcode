class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() == 0) return {};
        dfs(s,"",0);
        return ans;
    }
    void dfs(string s,string str,int k){
        if(s.size()==0 && k==4 ) {
            return ans.push_back(str.substr(0,str.size()-1));
        }
        if(s.size()==0 || k==4 ) return;
        for(int i = 1;i<=min((int)s.size(),3);i++){
            int val = stoi(s.substr(0,i));
            if(val >=0 && val <=255){
                dfs(s.substr(i),str+s.substr(0,i)+'.',k+1);
            }
            if(s[0] =='0') break;
        }
    }
private:
    vector<string> ans;
};
