#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int last;
double per,loan,car,m,n;
pair<int,double> mon[101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> m >> per >> loan >> n &&(m>=0)){
        car=loan+per;
        per=loan/(double)m;
        last=0;
        for(int i=0;i<n;i++){
            cin >> mon[i].first >> mon[i].second;
        }
        car*=1-mon[0].second;
        if(loan<car){
            cout << "0 months\n";
            continue;
        }
        for(int i=1;i<=m;i++){
            if(last+1<n){
                if(mon[last+1].first<=i){
                    last++;
                }
            }
            car*=1-mon[last].second;
            loan-=per;
            if(loan<car){
                if(i==1){
                    cout << i << " month\n";
                }else{
                    cout << i << " months\n";
                }
                break;
            }
        }
    }
}