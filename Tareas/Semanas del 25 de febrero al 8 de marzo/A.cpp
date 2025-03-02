#include <bits/stdc++.h>
using namespace std;
int n,con=0;
char c;
vector<int> nums(300,0);
vector<int> temp(300);
void solve(int x){
    if(x==n){
        //process
        bool xd=false;
        int sum=0;
        for(int k=0;k<n;k++){
            sum+=temp[k];
            if(sum<0){
                break;
            }
        }
        if(sum==0){
            xd=true;
        }
        for(int i=0;i<n && !xd;i++){
            for(int j=i;j<n && !xd;j++){
                // de i a j
                temp[j]*=-1;
                int sum=0;
                for(int k=0;k<n;k++){
                    sum+=temp[k];
                    if(sum<0){
                        break;
                    }
                }
                if(sum==0){
                    xd=true;
                    for(;j>=i;j--){
                        temp[j]*=-1;
                    }
                }
            }
            for(int j=i;j<n && !xd;j++){
                temp[j]*=-1;
            }
        }
        if(xd){
            con++;
        }
        return;
    }
    if(nums[x]!=0){
        temp[x]=nums[x];
        solve(x+1);
        temp[x]=0;
        return;
    }
    temp[x]=1;
    solve(x+1);
    temp[x]=-1;
    solve(x+1);
    temp[x]=0;
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c;
        if(c=='('){
            nums[i]=1;
        }else if(c==')'){
            nums[i]=-1;
        }
    }
    solve(0);
    cout << con;
}