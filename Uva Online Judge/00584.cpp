#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(getline(cin,s),s!="Game Over"){
        int canti[20],sum,con,canttt;
        sum=con=canttt=0;
        memset(canti,0,sizeof canti);
        for(int i=0;i<s.size();i+=2){
            if(s[i]>='0' && s[i]<='9'){
                if(canttt==0){
                    con++;
                }
                canttt++;
                if(canttt==2){
                    canttt=0;
                }
                canti[i/2]=s[i]-48;
            }else if(s[i]=='/'){
                canttt=0;
                canti[i/2]=10-canti[i/2-1];
            }else{
                con++;
                canti[i/2]=10;
            }
            if(con<=10){
                //cout << sum << ' ';
                sum+=canti[i/2];
            }
        }
        canttt=con=0;
        for(int i=0;i<s.size() && con<10;i+=2){
            if(s[i]=='X'){
                con++;
                sum+=canti[i/2+1]+canti[i/2+2];
            }else if(s[i]=='/'){
                con++;
                canttt=0;
                sum+=canti[i/2+1];
            }else{
                canttt++;
                if(canttt==2){
                    canttt=0;
                    con++;
                }
            }
        }
        cout << sum << '\n';
    }
}