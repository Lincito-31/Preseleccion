#include <bits/stdc++.h>
using namespace std;
int n,k,a,b,con=0,maxi=1;
int main(){
    scanf("%d%d",&n,&k);
    vector<pair<int,int>> movie(n);
    vector<int> per(k,0);
    for(int i=0;i<n;i++){
        scanf("%d%d",&movie[i].second,&movie[i].first);
    }
    sort(movie.begin(),movie.end());
    for(int i=0;i<n;i++){
        /*int l=0,r=maxi-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(per[mid]<=movie[i].second){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        if(l==0 && per[l]>movie[i].second){
            if(maxi<k){
                per[maxi]=movie[i].first;
                con++;
                maxi++;
            }
        }else{
            per[l]=movie[i].first;
            con++;
        }*/
    }
    printf("%d",con);
}