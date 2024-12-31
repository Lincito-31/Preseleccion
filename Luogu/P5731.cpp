#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n;
int main(){
    scanf("%d",&n);
    vector<vi> mat(n+2,vi(n+2,0));
    for(int i=0;i<n+2;i++){
        mat[i][0]=mat[0][i]=mat[n+1][i]=mat[i][n+1]=1;
    }
    int inix=1,iniy=1,dire=3;
    //0up,1down,2left,3right;
    for(int i=0;i<n*n;i++){
        mat[inix][iniy]=i+1;
        if(dire==3){
            if(mat[inix+1][iniy]==0){
                inix++;
            }else if(mat[inix][iniy+1]==0){
                iniy++;
                dire=1;
            }else{
                iniy--;
                dire=0;
            }
        }else if(dire==2){
            if(mat[inix-1][iniy]==0){
                inix--;
            }else if(mat[inix][iniy+1]==0){
                iniy++;
                dire=1;
            }else{
                iniy--;
                dire=0;
            }
        }else if(dire==0){
            if(mat[inix][iniy-1]==0){
                iniy--;
            }else if(mat[inix-1][iniy]==0){
                inix--;
                dire=2;
            }else{
                inix++;
                dire=3;
            }
        }else{
            if(mat[inix][iniy+1]==0){
                iniy++;
            }else if(mat[inix-1][iniy]==0){
                inix--;
                dire=2;
            }else{
                inix++;
                dire=3;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[j][i]<10){
                printf(" ");
            }
            printf(" %d",mat[j][i]);
        }
        printf("\n");
    }
}