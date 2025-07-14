#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,k,num[1000001],a,b;
int main(){
    cin >> n >> k;
    while(k--){
        cin >> a >> b;
        num[a-1]++;
        num[b]--;
    }
    for(int i=1;i<n;i++){
        num[i]+=num[i-1];
    }
    sort(num,num+n);
    cout << num[n/2];
}