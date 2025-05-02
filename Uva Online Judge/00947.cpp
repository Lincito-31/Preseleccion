#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,a,b,x,cantidigi,temp,now=0,canti,tot;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        tot=0;
        vector<int> con(10,0),pos(5);
        now=0;
        cin >> x >> a >> b;
        temp=x;
        while(temp>0){
            con[temp%10]++;
            pos[now++]=temp%10;
            temp/=10;
        }
        cantidigi=log10(x)+1;
        int fijo=pow(10,cantidigi);
        for(int i=(fijo-1)/9;i<fijo;i++){
            xd=true;
            canti=0;
            now=0;
            vector<int> nue(10,0);
            int iguales=0;
            temp=i;
            while(temp>0){
                nue[temp%10]++;
                if(temp%10==0){
                    xd=false;
                    break;
                }
                if(temp%10==pos[now++]){
                    canti++;
                }
                temp/=10;
            }
            for(int i=0;i<10;i++){
                iguales+=min(nue[i],con[i]);
            }
            if(!xd || canti!=a){
                continue;
            }else{
                iguales-=a;
                if(iguales==b){
                    tot++;
                }
            }
        }
        cout << tot << '\n';
    }
}