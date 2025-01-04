#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int N,K;
    vector<vector<int>> res;
    vector<int> temp;
    void complete_search(int x,int y){
        if(y==K){
            res.push_back(temp);
            return;
        }
        for(int i=x+1;i<=N;i++){
            temp[y]=i;
            complete_search(i,y+1);
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        N=n;K=k;
        temp.resize(k);
        complete_search(0,0);
        return res;
    }
};