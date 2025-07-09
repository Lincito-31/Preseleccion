#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int nums[7],a,b,c;
bool xd;
int main(){
    for(int i=0;i<7;i++){
        cin >> nums[i];
    }
    sort(nums,nums+7);
    a=nums[0];
    b=nums[1];
    for(int i=2;i<7;i++){
        if(xd){
            c=nums[i];
            break;
        }else{
            if(nums[i]!=a+b){
                c=nums[i];
                break;
            }else{
                xd=true;
            }
        }
    }
    cout << a << ' ' << b << ' ' << c;
}