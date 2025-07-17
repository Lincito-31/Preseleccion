#include <bits/stdc++.h>
using namespace std;
int n,q,nums[100000],a,b;
int main(){
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    fin >> n >> q;
    for(int i=0;i<n;i++){
        fin >> nums[i];
    }
    sort(nums,nums+n);
    while(q--){
        fin >> a >> b;
        fout << upper_bound(nums,nums+n,b)-upper_bound(nums,nums+n,a-1) << '\n';
    }
}