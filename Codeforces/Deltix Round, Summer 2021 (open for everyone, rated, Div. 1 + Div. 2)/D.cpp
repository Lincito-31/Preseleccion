#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,b,c,d,e,f,n,k;
int num1[32],num2[32],num3[32],numer1,numer2,numer3;
bool xd1,xd2,xd3;
int andop(int x,int y){
    int temp;
    cout << "and " << x << ' ' << y << '\n';
    cout.flush();
    cin >> temp;
    return temp;
}
int orop(int x,int y){
    int temp;
    cout << "or " << x << ' ' << y << '\n';
    cout.flush();
    cin >> temp;
    return temp;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    a=andop(1,2);
    b=orop(1,2);
    c=andop(1,3);
    d=orop(1,3);
    e=andop(2,3);
    f=orop(2,3);
    for(int i=0;i<32;i++){
        num1[i]=num2[i]=num3[i]=-1;
    }
    for(int i=0;i<32;i++){
        if(a&(1<<i)){
            num1[i]=num2[i]=1;
        }else if(!(b&(1<<i))){
            num1[i]=num2[i]=0;
        }
        if(c&(1<<i)){
            num1[i]=num3[i]=1;
        }else if(!(d&(1<<i))){
            num1[i]=num3[i]=0;
        }
        if(e&(1<<i)){
            num3[i]=num2[i]=1;
        }else if(!(f&(1<<i))){
            num3[i]=num2[i]=0;
        }
        if(a&(1<<i)){
            num1[i]=num2[i]=1;
        }else if(!(b&(1<<i))){
            num1[i]=num2[i]=0;
        }else{
            if(num1[i]!=-1){
                num2[i]=1-num1[i];
            }else if(num2[i]!=-1){
                num1[i]=1-num2[i];
            }
        }
        if(c&(1<<i)){
            num1[i]=num3[i]=1;
        }else if(!(d&(1<<i))){
            num1[i]=num3[i]=0;
        }else{
            if(num1[i]!=-1){
                num3[i]=1-num1[i];
            }else if(num3[i]!=-1){
                num1[i]=1-num3[i];
            }
        }
        if(e&(1<<i)){
            num3[i]=num2[i]=1;
        }else if(!(f&(1<<i))){
            num3[i]=num2[i]=0;
        }else{
            if(num3[i]!=-1){
                num2[i]=1-num3[i];
            }else if(num2[i]!=-1){
                num3[i]=1-num2[i];
            }
        }
        if(a&(1<<i)){
            num1[i]=num2[i]=1;
        }else if(!(b&(1<<i))){
            num1[i]=num2[i]=0;
        }else{
            if(num1[i]!=-1){
                num2[i]=1-num1[i];
            }else if(num2[i]!=-1){
                num1[i]=1-num2[i];
            }
        }
        if(c&(1<<i)){
            num1[i]=num3[i]=1;
        }else if(!(d&(1<<i))){
            num1[i]=num3[i]=0;
        }else{
            if(num1[i]!=-1){
                num3[i]=1-num1[i];
            }else if(num3[i]!=-1){
                num1[i]=1-num3[i];
            }
        }
        if(e&(1<<i)){
            num3[i]=num2[i]=1;
        }else if(!(f&(1<<i))){
            num3[i]=num2[i]=0;
        }else{
            if(num3[i]!=-1){
                num2[i]=1-num3[i];
            }else if(num2[i]!=-1){
                num3[i]=1-num2[i];
            }
        }
        if(a&(1<<i)){
            num1[i]=num2[i]=1;
        }else if(!(b&(1<<i))){
            num1[i]=num2[i]=0;
        }else{
            if(num1[i]!=-1){
                num2[i]=1-num1[i];
            }else if(num2[i]!=-1){
                num1[i]=1-num2[i];
            }
        }
        if(c&(1<<i)){
            num1[i]=num3[i]=1;
        }else if(!(d&(1<<i))){
            num1[i]=num3[i]=0;
        }else{
            if(num1[i]!=-1){
                num3[i]=1-num1[i];
            }else if(num3[i]!=-1){
                num1[i]=1-num3[i];
            }
        }
        if(e&(1<<i)){
            num3[i]=num2[i]=1;
        }else if(!(f&(1<<i))){
            num3[i]=num2[i]=0;
        }else{
            if(num3[i]!=-1){
                num2[i]=1-num3[i];
            }else if(num2[i]!=-1){
                num3[i]=1-num2[i];
            }
        }
        if(a&(1<<i)){
            num1[i]=num2[i]=1;
        }else if(!(b&(1<<i))){
            num1[i]=num2[i]=0;
        }else{
            if(num1[i]!=-1){
                num2[i]=1-num1[i];
            }else if(num2[i]!=-1){
                num1[i]=1-num2[i];
            }
        }
        if(c&(1<<i)){
            num1[i]=num3[i]=1;
        }else if(!(d&(1<<i))){
            num1[i]=num3[i]=0;
        }else{
            if(num1[i]!=-1){
                num3[i]=1-num1[i];
            }else if(num3[i]!=-1){
                num1[i]=1-num3[i];
            }
        }
        if(e&(1<<i)){
            num3[i]=num2[i]=1;
        }else if(!(f&(1<<i))){
            num3[i]=num2[i]=0;
        }else{
            if(num3[i]!=-1){
                num2[i]=1-num3[i];
            }else if(num2[i]!=-1){
                num3[i]=1-num2[i];
            }
        }
        if(a&(1<<i)){
            num1[i]=num2[i]=1;
        }else if(!(b&(1<<i))){
            num1[i]=num2[i]=0;
        }else{
            if(num1[i]!=-1){
                num2[i]=1-num1[i];
            }else if(num2[i]!=-1){
                num1[i]=1-num2[i];
            }
        }
        if(c&(1<<i)){
            num1[i]=num3[i]=1;
        }else if(!(d&(1<<i))){
            num1[i]=num3[i]=0;
        }else{
            if(num1[i]!=-1){
                num3[i]=1-num1[i];
            }else if(num3[i]!=-1){
                num1[i]=1-num3[i];
            }
        }
        if(e&(1<<i)){
            num3[i]=num2[i]=1;
        }else if(!(f&(1<<i))){
            num3[i]=num2[i]=0;
        }else{
            if(num3[i]!=-1){
                num2[i]=1-num3[i];
            }else if(num2[i]!=-1){
                num3[i]=1-num2[i];
            }
        }
        if(a&(1<<i)){
            num1[i]=num2[i]=1;
        }else if(!(b&(1<<i))){
            num1[i]=num2[i]=0;
        }else{
            if(num1[i]!=-1){
                num2[i]=1-num1[i];
            }else if(num2[i]!=-1){
                num1[i]=1-num2[i];
            }
        }
        if(c&(1<<i)){
            num1[i]=num3[i]=1;
        }else if(!(d&(1<<i))){
            num1[i]=num3[i]=0;
        }else{
            if(num1[i]!=-1){
                num3[i]=1-num1[i];
            }else if(num3[i]!=-1){
                num1[i]=1-num3[i];
            }
        }
        if(e&(1<<i)){
            num3[i]=num2[i]=1;
        }else if(!(f&(1<<i))){
            num3[i]=num2[i]=0;
        }else{
            if(num3[i]!=-1){
                num2[i]=1-num3[i];
            }else if(num2[i]!=-1){
                num3[i]=1-num2[i];
            }
        }
        numer1+=num1[i]<<i;
        numer2+=num2[i]<<i;
        numer3+=num3[i]<<i;
    }
    vector<int> conj(n);
    conj[0]=numer1;
    conj[1]=numer2;
    conj[2]=numer3;
    for(int i=3;i<n;i++){
        int temp=0;
        a=andop(1,i+1);
        b=orop(1,i+1);
        for(int j=0;j<32;j++){
            if(a&(1<<j)){
                temp+=1<<j;
            }else if(b&(1<<j)){
                temp+=(1-num1[j])<<j;
            }
        }
        conj[i]=temp;
    }
    sort(ALL(conj));
    cout << "finish " << conj[k-1] << '\n';
    cout.flush();
}