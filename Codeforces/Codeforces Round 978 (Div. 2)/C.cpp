#include <bits/stdc++.h>
using namespace std;
int t,n;
int mat[2][100001];
char cade[100000];
vector<vector<int>> dp;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        dp.assign(n+1,vector<int>(3,0));
        scanf("%s",cade);
        mat[0][0]=mat[1][0]=0;
        for(int i=1;i<=n;i++){
            mat[0][i]=(cade[i-1]=='A'?1:-1);
        }
        scanf("%s",cade);
        for(int i=1;i<=n;i++){
            mat[1][i]=(cade[i-1]=='A'?1:-1);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                if(j==0){
                    //{i-3,i-3}
                    if(i>2){
                        int op1=dp[i-3][0];
                        if((mat[0][i]+mat[0][i-1]+mat[0][i-2])>0){
                            op1++;
                        }
                        if((mat[1][i]+mat[1][i-1]+mat[1][i-2])>0){
                            op1++;
                        }
                        dp[i][j]=max(dp[i][j],op1);
                    }
                    //{i-2,i-4}
                    if(i>3){
                        int op2=dp[i-2][2];
                        if((mat[0][i]+mat[0][i-1]+mat[1][i])>0){
                            op2++;
                        }
                        if((mat[1][i-1]+mat[1][i-2]+mat[1][i-3])>0){
                            op2++;
                        }
                        dp[i][j]=max(dp[i][j],op2);
                    }
                    //{i-1,i-2}
                    if(i>1){
                        int op3=dp[i-1][1];
                        if((mat[0][i]+mat[1][i]+mat[1][i-1])>0){
                            op3++;
                        }
                        dp[i][j]=max(dp[i][j],op3);
                    }
                    //{}
                    if(i>2){
                        int op4=dp[i-3][0];
                        if((mat[0][i]+mat[0][i-1]+mat[1][i])>0){
                            op4++;
                        }
                        if((mat[0][i-2]+mat[1][i-1]+mat[1][i-2])>0){
                            op4++;
                        }
                        dp[i][j]=max(dp[i][j],op4);
                    }
                }else if(j==1){
                    //{i-2,i-1}
                    if(i>1){
                        int op1=dp[i-2][0];
                        if((mat[0][i]+mat[1][i-1]+mat[0][i-1])>0){
                            op1++;
                        }
                        dp[i][j]=max(dp[i][j],op1);
                    }
                    //{i-3,i-4}
                    if(i>3){
                        int op2=dp[i-3][1];
                        if((mat[0][i]+mat[0][i-1]+mat[0][i-2])>0){
                            op2++;
                        }
                        if((mat[1][i-3]+mat[1][i-1]+mat[1][i-2])>0){
                            op2++;
                        }
                        dp[i][j]=max(dp[i][j],op2);
                    }
                }else if(j==2){
                    //{i-3,i-5}
                    if(i>4){
                        int op1=dp[i-3][2];
                        if((mat[0][i]+mat[0][i-1]+mat[0][i-2])>0){
                            op1++;
                        }
                        if((mat[1][i-2]+mat[1][i-3]+mat[1][i-4])>0){
                            op1++;
                        }
                        dp[i][j]=max(dp[i][j],op1);
                    }
                    //
                    if(i>3){
                        int op2=dp[i-4][0];
                        if((mat[0][i]+mat[0][i-1]+mat[0][i-2])>0){
                            op2++;
                        }
                        if((mat[0][i-3]+mat[1][i-3]+mat[1][i-2])>0){
                            op2++;
                        }
                        dp[i][j]=max(dp[i][j],op2);
                    }
                }
            }
        }
        printf("%d\n",dp[n][0]);
    }
}