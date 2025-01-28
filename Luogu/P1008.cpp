#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<bool> used(10);
    used[0]=true;
    for(int i=100;i<1000;i++){
        bool xd=true;
        for(int j=1;j<10;j++){
            used[j]=false;
        }
        int x=i;
        while(x>0){
            if(used[x%10]){
                xd=false;
                break;
            }
            used[x%10]=true;
            x/=10;
        }
        x=2*i;
        while(x>0){
            if(used[x%10]){
                xd=false;
                break;
            }
            used[x%10]=true;
            x/=10;
        }
        x=3*i;
        while(x>0){
            if(used[x%10]){
                xd=false;
                break;
            }
            used[x%10]=true;
            x/=10;
        }
        if(xd){
            printf("%d %d %d\n",i,2*i,3*i);
        }
    }
}