#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,con,conta[2019];
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    n=s.size();
    int nums[n+1];
    nums[0]=0;
    for(int i=1;i<=n;i++){
        nums[i]=(nums[i-1]*10+s[i-1]-48)%2019;
    }
    for(int i=1;i<=n;i++){
        con+=conta[nums[i]];
        if(nums[i]==0){
            con++;
        }
        conta[nums[i]]++;
        int temp[2019];
        for(int i=0;i<2019;i++){
            temp[i]=0;
        }
        for(int i=0;i<2019;i++){
            temp[(i*10)%2019]+=conta[i];
        }
        for(int i=0;i<2019;i++){
            conta[i]=temp[i];
        }
    }
    cout << con;
}