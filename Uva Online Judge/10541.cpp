#include <bits/stdc++.h>
using namespace std;
int t,n,k,a;
string combi[201][201];
string sumar(string x,string y){
    int tamx=x.size();
    int tamy=y.size();
    if(tamx>tamy){
        swap(x,y);
        swap(tamx,tamy);
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    string res="";
    bool sobra=false;
    for(int i=0;i<y.size();i++){
        if(i>=tamx){
            x.push_back('0');
            tamx++;
        }
        int aaa=x[i]-48+y[i]-48;
        if(sobra){
            aaa++;
            sobra=false;
        }
        if(aaa>9){
            sobra=true;
        }
        char bbb=(aaa%10+48);
        res.push_back(bbb);
    }
    if(sobra){
        res.push_back('1');
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    for(int i=0;i<201;i++){
        combi[i][0]="1";
        for(int j=1;j<=i;j++){
            combi[i][j]="";
            if(i-j<j){
                combi[i][j]=combi[i][i-j];
                continue;
            }
            combi[i][j]=sumar(combi[i-1][j],combi[i-1][j-1]);
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int blank=n;
        for(int i=0;i<k;i++){
            cin >> a;
            blank-=a;
        }
        blank-=k-1;
        if(blank<0){
            cout << "0\n";
        }else{
            //formar el numero blank con k+1 numeros
            string res=combi[blank+k][min(blank,k)];
            cout << res << endl;
        }
    }
}