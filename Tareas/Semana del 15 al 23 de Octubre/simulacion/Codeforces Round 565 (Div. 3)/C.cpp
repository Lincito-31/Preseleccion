#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n,a;
int main(){
    scanf("%d",&n);
    vi nums(n);
    vector<vi> pos(43);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        pos[nums[i]].push_back(i);
    }
    int po1=0,po2=0,po3=0,po4=0,po5=0,po6=0;
    while(po1<pos[4].size()){
        int now=pos[4][po1];
        //8
        while(po2<pos[8].size()){
            if(pos[8][po2]<now){
                po2++;
            }else{
                break;
            }
        }
        if(po2==pos[8].size()){
            break;
        }
        now=pos[8][po2];
        //15
        while(po3<pos[15].size()){
            if(pos[15][po3]<now){
                po3++;
            }else{
                break;
            }
        }
        if(po3==pos[15].size()){
            break;
        }
        now=pos[15][po3];
        //16
        while(po4<pos[16].size()){
            if(pos[16][po4]<now){
                po4++;
            }else{
                break;
            }
        }
        if(po4==pos[16].size()){
            break;
        }
        now=pos[16][po4];
        //23
        while(po5<pos[23].size()){
            if(pos[23][po5]<now){
                po5++;
            }else{
                break;
            }
        }
        if(po5==pos[23].size()){
            break;
        }
        now=pos[23][po5];
        // 42
        while(po6<pos[42].size()){
            if(pos[42][po6]<now){
                po6++;
            }else{
                break;
            }
        }
        if(po6==pos[42].size()){
            break;
        }
        now=pos[42][po6];
        pos[4][po1]=-1;
        pos[8][po2]=-1;
        pos[15][po3]=-1;
        pos[16][po4]=-1;
        pos[23][po5]=-1;
        pos[42][po6]=-1;
        po1++;
    }
    int con=0;
    for(int i=0;i<pos[4].size();i++){
        if(pos[4][i]!=-1){
            con++;
        }
    }
    for(int i=0;i<pos[8].size();i++){
        if(pos[8][i]!=-1){
            con++;
        }
    }
    for(int i=0;i<pos[15].size();i++){
        if(pos[15][i]!=-1){
            con++;
        }
    }
    for(int i=0;i<pos[16].size();i++){
        if(pos[16][i]!=-1){
            con++;
        }
    }
    for(int i=0;i<pos[23].size();i++){
        if(pos[23][i]!=-1){
            con++;
        }
    }
    for(int i=0;i<pos[42].size();i++){
        if(pos[42][i]!=-1){
            con++;
        }
    }
    printf("%d",con);
}