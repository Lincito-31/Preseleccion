#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    vector<int> cows(n+1),b(n+1),psum(n+1,0);
    vector<vector<int>> pair(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        scanf("%d",&cows[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        psum[i]=psum[i-1];
        if(b[i]==cows[i]){
            psum[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cows[i]==b[j]){
                pair[min(i,j)][max(i,j)]++;
            }
        }
    }
    vector<int> res(n+1);
    for(int i=1;i<=n;i++){
        int iz=i,de=i;
        int sum=0;
        while(iz>=1 && de<=n){
            sum+=pair[iz][de];
            int coincideiz=psum[iz-1];
            int coincidede=psum[n]-psum[de];
            res[sum+coincidede+coincideiz]++;
            //cout << iz << " " << de << " " << sum << " " << coincideiz << " " << coincidede << endl;
            iz--;
            de++;
        }
    }
    for(int i=1;i<n;i++){
        int iz=i,de=i+1;
        int sum=0;
        while(iz>=1 && de<=n){
            sum+=pair[iz][de];
            int coincideiz=psum[iz-1];
            int coincidede=psum[n]-psum[de];
            res[sum+coincidede+coincideiz]++;
            iz--;
            de++;
        }
    }
    for(int i=0;i<=n;i++){
        printf("%d\n",res[i]);
    }
}