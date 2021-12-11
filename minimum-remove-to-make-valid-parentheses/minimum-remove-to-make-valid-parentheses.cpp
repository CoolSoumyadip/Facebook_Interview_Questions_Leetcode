class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        int n = s.size();
        unordered_set<int> set;
        
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == ')' || s[i] == '(') {
                if(s[i] == '(') {
                    stk.push(i);
                }
                else{
                    if(stk.empty()) {
                        set.insert(i);
                    }else {
                        if(s[stk.top()] == '(')
                            stk.pop();
                    }
                }
            }
        }
        
        while(!stk.empty()) {
            set.insert(stk.top());
            stk.pop();
        }
        
        string ans = "";
        
        for(int i = 0 ; i < n ; i++) {
            if(set.find(i) == set.end()) {
                ans += s[i];
            }
        }
        return ans;
    }
};