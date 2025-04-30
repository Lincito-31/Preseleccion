#include <bits/stdc++.h>
using namespace std;
int t,pointer,a[100];
string s;
char hexa[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    cin.ignore();
    for(int i=1;i<=t;i++){
        cout << "Case " << i << ": ";
        memset(a,0,sizeof a);
        pointer=0;
        getline(cin,s);
        for(int j=0;j<s.size();j++){
            if(s[j]=='>'){
                pointer++;
                pointer%=100;
            }else if(s[j]=='<'){
                pointer--;
                pointer+=100;
                pointer%=100;
            }else if(s[j]=='+'){
                a[pointer]++;
                a[pointer]%=256;
            }else if(s[j]=='-'){
                a[pointer]--;
                a[pointer]+=256;
                a[pointer]%=256;
            }
        }
        for(int j=0;j<99;j++){
            cout << hexa[a[j]/16] << hexa[a[j]%16] << ' ';
        }
        cout << hexa[a[99]/16] << hexa[a[99]%16];
        cout << '\n';
    }
}