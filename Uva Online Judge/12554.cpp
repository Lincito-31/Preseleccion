#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,j;
string song[]={"Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you"},names[100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> names[i];
    }
    if(n>16){
        for(int i=0;i<n;i++){
            cout << names[i] << ": " << song[j++] << '\n';
            if(j==16){
                j=0;
            }
        }
        for(int i=0;j<16;i++){
            cout << names[i] << ": " << song[j++] << '\n';
        }
    }else{
        for(int i=0;i<16;i++){
            cout << names[j++] << ": " << song[i] << '\n';
            if(j==n){
                j=0;
            }
        }
    }
}