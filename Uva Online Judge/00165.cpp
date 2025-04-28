#include  <bits/stdc++.h>
using  namespace  std;
int  n,k,maxi=0,now=1;
string  NINJA[9][9];
vector<pair<int,int>>  posi;
vector<int>  conjunto;
vector<int>  respuesta;
bool  xd=false;
/*void  calc(){
        posi[0]={1,0};
        for(int  kk=0;kk<20;kk++){
                for(int  i=0;i<k;i++){
                        for(int  j=100;j>=0;j--){
                                if(posi[j].first==1){
                                        if(posi[j].second<n){
                                                if(j+conjunto[i]>100){
                                                        continue;
                                                }
                                                if(posi[j+conjunto[i]].first==0){
                                                        posi[j+conjunto[i]]=posi[j];
                                                        posi[j+conjunto[i]].second++;
                                                }else  if(posi[j+conjunto[i]].second>posi[j].second+1){
                                                        posi[j+conjunto[i]].second=posi[j].second+1;
                                                }
                                        }
                                }
                        }
                }
        }
        while(posi[now].first==1){
                now++;
        }
}
void  solve(int  pos,int  num){
        if(pos==k){
                now=1;
                posi.assign(101,{0,0});
                calc();
                if(maxi<now-1){
                        maxi=now-1;
                        respuesta=conjunto;
                }
                return;
        }
        if(num>35){
                return;
        }
        conjunto[pos]=num;
        solve(pos+1,num+1);
        conjunto[pos]=0;
        solve(pos,num+1);
}*/
int  main(){
        /*for(n=2;n<9;n++){
                for(k=1;k<9;k++){
                        if(n+k<=9){
                                maxi=0;
                                conjunto.assign(k,0);
                                conjunto[0]=1;
                                solve(1,2);
                                printf("NINJA[%d][%d]=\"",n,k);
                                for(int  i=0;i<k;i++){
                                        printf("%d  ",respuesta[i]);
                                }
                                printf(->  %d\\";",maxi);
                        }
                }
        }*/
        NINJA[1][1]="  1 ->  1";
        NINJA[1][2]="  1  2 ->  2";
        NINJA[1][3]="  1  2  3 ->  3";
        NINJA[1][4]="  1  2  3  4 ->  4";
        NINJA[1][5]="  1  2  3  4  5 ->  5";
        NINJA[1][6]="  1  2  3  4  5  6 ->  6";
        NINJA[1][7]="  1  2  3  4  5  6  7 ->  7";
        NINJA[1][8]="  1  2  3  4  5  6  7  8 ->  8";
        NINJA[2][1]="  1 ->  2";
        NINJA[2][2]="  1  2 ->  4";
        NINJA[2][3]="  1  3  4 ->  8";
        NINJA[2][4]="  1  3  5  6 -> 12";
        NINJA[2][5]="  1  3  5  7  8 -> 16";
        NINJA[2][6]="  1  2  5  8  9 10 -> 20";
        NINJA[2][7]="  1  2  5  8 11 12 13 -> 26";
        NINJA[3][1]="  1 ->  3";
        NINJA[3][2]="  1  3 ->  7";
        NINJA[3][3]="  1  4  5 -> 15";
        NINJA[3][4]="  1  4  7  8 -> 24";
        NINJA[3][5]="  1  4  6 14 15 -> 36";
        NINJA[3][6]="  1  3  7  9 19 24 -> 52";
        NINJA[4][1]="  1 ->  4";
        NINJA[4][2]="  1  3 -> 10";
        NINJA[4][3]="  1  5  8 -> 26";
        NINJA[4][4]="  1  3 11 18 -> 44";
        NINJA[4][5]="  1  3 11 15 32 -> 70";
        NINJA[5][1]="  1 ->  5";
        NINJA[5][2]="  1  4 -> 14";
        NINJA[5][3]="  1  6  7 -> 35";
        NINJA[5][4]="  1  4 12 21 -> 71";
        NINJA[6][1]="  1 ->  6";
        NINJA[6][2]="  1  4 -> 18";
        NINJA[6][3]="  1  7 12 -> 52";
        NINJA[7][1]="  1 ->  7";
        NINJA[7][2]="  1  5 -> 23";
        NINJA[8][1]="  1 ->  8";
        while(true){
            cin  >>  n  >>  k;
            if(n==0  &&  k==0){
                break;
            }
            cout  <<  NINJA[n][k] << "\n";
        }
}