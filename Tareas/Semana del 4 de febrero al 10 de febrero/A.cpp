#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int arr[2*n];
        for(int i=0;i<2*n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+2*n);
        printf("%d\n",arr[n]-arr[n-1]);
    }
}