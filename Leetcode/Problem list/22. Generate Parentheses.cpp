#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> res;
    int N;
    string x="";
    void calc(int sum,int position){
        if(position==N){
            if(sum==0){
                res.push_back(x);
            }
            return;
        }
        if(sum<0){
            return;
        }
        x.push_back('(');
        calc(sum+1,position+1);
        x.pop_back();
        x.push_back(')');
        calc(sum-1,position+1);
        x.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        N=2*n;
        calc(0,0);
        return res;
    }
};