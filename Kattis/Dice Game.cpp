#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,b,c,d,x,y,z,w,win;
vector<int> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> d >> x >> y >> z >> w;
    for(int i=x;i<=y;i++){
        for(int j=z;j<=w;j++){
            s.push_back(i+j);
        }
    }
    sort(ALL(s));
    for(int i=a;i<=b;i++){
        for(int j=c;j<=d;j++){
            win+=lower_bound(ALL(s),i+j)-s.begin();
            win-=s.size()-(upper_bound(ALL(s),i+j)-s.begin());
        }
    }
    if(win>0){
        cout << "Gunnar";
    }else if(win==0){
        cout << "Tie";
    }else{
        cout << "Emma";
    }
}