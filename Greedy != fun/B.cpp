#include <bits/stdc++.h>
using namespace std;
string st;
int maxi=-1,k,a,rep[26],sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st >> k;
    for(int i=0;i<26;i++){
        cin >> rep[i];
        maxi=max(maxi,rep[i]);
    }
    for(int i=0;i<st.size();i++){
        sum+=(i+1)*rep[st[i]-'a'];
    }
    for(int i=st.size();i<st.size()+k;i++){
        sum+=(i+1)*maxi;
    }
    cout << sum;
}