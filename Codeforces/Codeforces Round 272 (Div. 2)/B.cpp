#include <bits/stdc++.h>
using namespace std;
char a[10],b[10];
int fact[11];
int main(){
    fact[0]=1;
    for(int i=1;i<=10;i++){
        fact[i]=fact[i-1]*i;
    }
    scanf(" %s",a);
    scanf(" %s",b);
    string A(a),B(b);
    int num=0,num2=0,canti=0;
    for(int i=0;i<A.size();i++){
        if(A[i]=='+'){
            num++;
        }else{
            num--;
        }
        if(B[i]=='+'){
            num2++;
        }else if(B[i]=='-'){
            num2--;
        }else{
            canti++;
        }
    }
    num=abs(num-num2);
    int res=0;
    if(canti-num>=0 && (canti-num)%2==0){
        int necesito=num+(canti-num)/2;
        int posi=fact[canti]/(fact[necesito]*fact[canti-necesito]);
        int tot=1<<canti;
        double fina=(double)posi/(double)tot;
        printf("%.12lf",fina);
    }else{
        printf("0.000000000000");
    }
}