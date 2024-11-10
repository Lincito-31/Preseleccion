#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
string x;
int main(){
    scanf("%d",&t);
    while(t--){
        cin >> x;
        if(x.size()==5){
            printf("3");
        }else{
            int can=0;
            if(x[0]=='o'){
                can++;
            }
            if(x[1]=='n'){
                can++;
            }
            if(x[2]=='e'){
                can++;
            }
            if(can>=2){
                printf("1");
            }else{
                printf("2");
            }
        }
        printf("\n");
    }
}