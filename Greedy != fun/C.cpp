#include <bits/stdc++.h>
using namespace std;
int d,s,mini,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> d >> s;
    pair<int,int> day[d];
    for(int i=0;i<d;i++){
        cin >> day[i].first >> day[i].second;
        mini+=day[i].first;
        maxi+=day[i].second;
    }
    if(s<mini || s>maxi){
        cout << "NO";
    }else{
        cout << "YES\n";
        for(int i=0;i<d;i++){
            if(mini+day[i].second-day[i].first<s){
                mini+=day[i].second-day[i].first;
                cout << day[i].second << ' ';
            }else{
                cout << s-mini+day[i].first << ' ';
                mini=s;
            }
        }
    }
}