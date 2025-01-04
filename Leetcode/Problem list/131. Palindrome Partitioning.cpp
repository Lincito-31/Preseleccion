#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string S;
    int N;
    vector<vector<string>> res;
    vector<string> temp;
    void sol(int position, string now){
        if(position==N){
            string rev=now;
            reverse(rev.begin(),rev.end());
            if(rev==now){
                temp.push_back(now);
                res.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        //option 1:push now to temp;
        string rev=now;
        reverse(rev.begin(),rev.end());
        if(rev==now){
            temp.push_back(now);
            string nue="";
            nue.push_back(S[position]);
            sol(position+1,nue);
            temp.pop_back();
        }
        //option 2:unite with the next one;
        now.push_back(S[position]);
        sol(position+1,now);
    }
    vector<vector<string>> partition(string s) {
        S=s;
        N=s.size();
        string nue="";
        nue.push_back(s[0]);
        sol(1,nue);
        return res;
    }
};