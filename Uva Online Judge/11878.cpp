#include <bits/stdc++.h>
using namespace std;
int con,a,b,c,i;
bool mas;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(getline(cin,s)){
        if(s.back()=='?'){
            continue;
        }
        a=b=c=mas=i=0;
        for(;s[i]!='+' && s[i]!='-';i++){
            a*=10;
            a+=s[i]-48;
        }
        if(s[i]=='+'){
            mas=true;
        }
        i++;
        for(;s[i]!='=';i++){
            b*=10;
            b+=s[i]-48;
        }
        i++;
        for(;i<s.size();i++){
            c*=10;
            c+=s[i]-48;
        }
        if(mas){
            if(a+b==c){
                con++;
            }
        }else{
            if(a-b==c){
                con++;
            }
        }
    }
    cout << con << '\n';
}