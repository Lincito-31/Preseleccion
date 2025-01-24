#include <bits/stdc++.h>
using namespace std;
int n,ans;
vector<int> res;

int main(){
    scanf("%d",&n);
    vector<int> nums(n);
    res.push_back(0);
    for(int i=1;i<n;i++){
        int l=0,r=i;
        while(l<r){
            int mid=(l+r)/2;
            printf("? 2 %d %d\n",i,res[mid]);
            fflush(stdout);
            scanf("%d",&ans);
            if(ans==1){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        r++;
        vector<int> temp(i+1);
        for(int j=0;j<l;j++){
            temp[j]=res[j];
        }
        temp[l]=i;
        for(int j=l+1;j<i+1;j++){
            temp[j]=res[j-1];
        }
        res=temp;
    }
    vector<int> fina(n);
    for(int i=0;i<n;i++){
        fina[res[i]]=i;
    }
    printf("!");
    for(int i=0;i<n;i++){
        printf(" %d",fina[i]);
    }
}