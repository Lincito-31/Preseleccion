#include "carpet.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int max_line(int N, int M, std::vector<int> X, std::vector<int> Y)
{
    vector<pair<int,int>> nue;
    /*nue.push_back({X[0],Y[0]});
    for(int i=1;i<N-2;i++){
        if(((X[i-1]!=X[i])&&(Y[i-1]==Y[i]))&&((X[i+1]==X[i])&&(Y[i+1]!=Y[i]))){
            nue.push_back({X[i],Y[i]});
        }else if(((Y[i-1]!=Y[i])&&(X[i-1]==X[i]))&&((Y[i+1]==Y[i])&&(X[i+1]!=X[i]))){
            nue.push_back({X[i],Y[i]});
        }
    }
    //nue.push_back({X[N-2],Y[N-2]});
    for(int i=0;i<nue.size();i+=2){
        if(nue[i].second%2==1){
            return nue[i].first;
        }
        if((nue[i+1].first-nue[i].first)%2==1){
            return nue[i+1].first-1;
        }
    }
    return nue.back().first;*/
    int izx=1e9,dex=0,aby=1e9,ary=0;
    int midx=-1,midy=-1;
    vector<pair<int,int>> puntos(6);
    for(int i=0;i<N;i++){
        izx=min(izx,X[i]);
        dex=max(dex,X[i]);
        aby=min(aby,Y[i]);
        ary=max(ary,Y[i]);
    }
    for(int i=0;i<N;i++){
        if(!(X[i]==izx || X[i]==dex)){
            midx=X[i];
        }
        if(!(Y[i]==aby || Y[i]==ary)){
            midy=Y[i];
        }
    }
    if(midy==-1 || midx==-1){
        if((ary-aby)%2==0){
            if((dex-izx)%2==0){
                return dex;
            }else{
                return dex-1;
            }
        }else{
            return izx;
        }
    }else{
        if(X[0]==izx && X[5]==izx && Y[0]<Y[5]){
            reverse(ALL(X));
            reverse(ALL(Y));
            for(int i=0;i<N;i++){
                nue.push_back({X[i],Y[i]});
            }
        }else{
            int ini;
            for(int i=0;i<N-1;i++){
                if(X[i]==izx && X[i+1]==izx && Y[i]>Y[i+1]){
                    reverse(ALL(X));
                    reverse(ALL(Y));
                }
            }
            for(int i=0;i<N-1;i++){
                if(X[i]==izx && X[i+1]==izx){
                    ini=i+1;
                }
            }
            for(int i=ini;i<N;i++){
                nue.push_back({X[i],Y[i]});
            }
            for(int i=0;i<ini;i++){
                nue.push_back({X[i],Y[i]});
            }
        }
        if((nue[0].second-nue[5].second)%2==1){
            return nue[0].first;
        }
        if(nue[0].second==midy){
            //caso 3
            if((nue[1].first-nue[0].first)%2==1){
                return nue[1].first-1;
            }else{
                if((nue[3].second-nue[5].second)%2==1){
                    return nue[1].first;
                }else{
                    if((nue[3].first-nue[2].first)%2==1){
                        return nue[3].first-1;
                    }else{
                        return nue[3].first;
                    }
                }
            }
        }else if(nue[1].first==midx){
            //caso 4
            if((nue[1].first-nue[0].first)%2==1){
                return nue[1].first-1;
            }else{
                if((nue[3].second-nue[5].second)%2==1){
                    return nue[1].first;
                }else{
                    if((nue[3].first-nue[2].first)%2==1){
                        return nue[3].first-1;
                    }else{
                        return nue[3].first;
                    }
                }
            }
        }else if(nue[2].second==midy){
            //caso 1
            if((nue[3].first-nue[0].first)%2==1){
                return nue[3].first-1;
            }else{
                if((nue[1].second-nue[3].second)%2==1){
                    return nue[3].first;
                }else{
                    if((nue[1].first-nue[3].first)%2==1){
                        return nue[1].first-1;
                    }else{
                        return nue[1].first;
                    }
                }
            }
        }else{
            //caso 2
            if((nue[3].first-nue[0].first)%2==1){
                return nue[3].first-1;
            }else{
                if((nue[1].second-nue[3].second)%2==1){
                    return nue[3].first;
                }else{
                    if((nue[1].first-nue[3].first)%2==1){
                        return nue[1].first-1;
                    }else{
                        return nue[1].first;
                    }
                }
            }
        }
    }
}
