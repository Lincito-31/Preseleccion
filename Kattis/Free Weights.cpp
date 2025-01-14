#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int f[n],s[n];
    for(int i=0;i<n;i++){
        scanf("%d",&f[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        int last=-1;
        bool xd=true;
        for(auto u:f){
            if(u<=mid){
                continue;
            }
            if(last==-1){
                last=u;
            }else{
                if(last==u){
                    last=-1;
                }else{
                    xd=false;
                    break;
                }
            }
        }
        if(last!=-1){
            xd=false;
        }
        if(xd){
            last=-1;
            for(auto u:s){
                if(u<=mid){
                    continue;
                }
                if(last==-1){
                    last=u;
                }else{
                    if(last==u){
                        last=-1;
                    }else{
                        xd=false;
                        break;
                    }
                }
            }
            if(last!=-1){
                xd=false;
            }
        }
        if(xd){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%d",l);
}