#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,p,con;
int main(){
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if((sum%(j-i+1))==0){
                for(int k=i;k<=j;k++){
                    if(nums[k]==(sum/(j-i+1))){
                        con++;
                        break;
                    }
                }
            }
        }
    }
    cout << con;
}