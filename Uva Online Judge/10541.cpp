#include <bits/stdc++.h>
using namespace std;
int t,n,k,a;
string suma(string x,string y,int pos,bool lleva){
    
}
string sumar(string x,string y){
    int tamx=x.size();
    int tamy=y.size();
    if(tamx>tamy){
        swap(x,y);
        swap(tamx,tamy);
    }
    reverse(x.begin(),x.end());
    for(int i=tamx;i<tamy;i++){
        x.push_back('0');
    }
    reverse(x.begin(),x.end());
    suma(x,y,tamy-1,false);
}
string combi(int x,int y){
    if(x==y || y==0){
        return "1";
    }
    return sumar(combi(x-1,y-1),combi(x-1,y));
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int blank=n;
        for(int i=0;i<k;i++){
            scanf("%d",&a);
            blank-=a;
        }
        blank-=k-1;
        if(blank<0){
            printf("0\n");
        }else{
            //formar el numero blank con k+1 numeros
            string res=combi(blank+k,min(blank,k));
        }
    }
}