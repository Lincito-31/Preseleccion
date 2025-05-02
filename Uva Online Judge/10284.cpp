#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int r,c,con;
string s;
vector<vector<char>> chess;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(getline(cin,s)){
        r=c=con=0;
        chess.assign(8,vector<char>(8,' '));
        for(int i=0;i<s.size();i++){
            if(s[i]>='1' && s[i]<='9'){
                c+=s[i]-48;
            }else if(s[i]=='/'){
                r++;
                c=0;
            }else{
                chess[r][c]=s[i];
                c++;
            }
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(chess[i][j]=='k' || chess[i][j]=='K'){
                    for(int k=i-1;k<=i+1;k++){
                        for(int l=j-1;l<=j+1;l++){
                            if(k>=0 && k<8 && l>=0 && l<8){
                                if(chess[k][l]==' '){
                                    chess[k][l]='x';
                                }
                            }
                        }
                    }
                }else if(chess[i][j]=='P'){
                    if(i-1>=0 && j-1>=0){
                        if(chess[i-1][j-1]==' '){
                            chess[i-1][j-1]='x';
                        }
                    }
                    if(i-1>=0 && j+1<8){
                        if(chess[i-1][j+1]==' '){
                            chess[i-1][j+1]='x';
                        }
                    }
                }else if(chess[i][j]=='p'){
                    if(i+1<8 && j-1>=0){
                        if(chess[i+1][j-1]==' '){
                            chess[i+1][j-1]='x';
                        }
                    }
                    if(i+1<8 && j+1<8){
                        if(chess[i+1][j+1]==' '){
                            chess[i+1][j+1]='x';
                        }
                    }
                }else if(chess[i][j]=='n' || chess[i][j]=='N'){
                    if(i-2>=0){
                        if(j-1>=0){
                            if(chess[i-2][j-1]==' '){
                                chess[i-2][j-1]='x';
                            }
                        }
                        if(j+1<8){
                            if(chess[i-2][j+1]==' '){
                                chess[i-2][j+1]='x';
                            }
                        }
                    }
                    if(i-1>=0){
                        if(j-2>=0){
                            if(chess[i-1][j-2]==' '){
                                chess[i-1][j-2]='x';
                            }
                        }
                        if(j+2<8){
                            if(chess[i-1][j+2]==' '){
                                chess[i-1][j+2]='x';
                            }
                        }
                    }
                    if(i+1<8){
                        if(j-2>=0){
                            if(chess[i+1][j-2]==' '){
                                chess[i+1][j-2]='x';
                            }
                        }
                        if(j+2<8){
                            if(chess[i+1][j+2]==' '){
                                chess[i+1][j+2]='x';
                            }
                        }
                    }
                    if(i+2<8){
                        if(j-1>=0){
                            if(chess[i+2][j-1]==' '){
                                chess[i+2][j-1]='x';
                            }
                        }
                        if(j+1<8){
                            if(chess[i+2][j+1]==' '){
                                chess[i+2][j+1]='x';
                            }
                        }
                    }
                }else if(chess[i][j]=='r' || chess[i][j]=='R'){
                    for(int k=i-1;k>=0;k--){
                        if(chess[k][j]==' ' || chess[k][j]=='x'){
                            chess[k][j]='x';
                        }else{
                            break;
                        }
                    }
                    for(int k=i+1;k<8;k++){
                        if(chess[k][j]==' ' || chess[k][j]=='x'){
                            chess[k][j]='x';
                        }else{
                            break;
                        }
                    }
                    for(int k=j-1;k>=0;k--){
                        if(chess[i][k]==' ' || chess[i][k]=='x'){
                            chess[i][k]='x';
                        }else{
                            break;
                        }
                    }
                    for(int k=j+1;k<8;k++){
                        if(chess[i][k]==' ' || chess[i][k]=='x'){
                            chess[i][k]='x';
                        }else{
                            break;
                        }
                    }
                }else if(chess[i][j]=='b' || chess[i][j]=='B'){
                    int k,l;
                    for(k=i-1,l=j-1;k>=0 && l>=0;k--,l--){
                        if(chess[k][l]==' ' || chess[k][l]=='x'){
                            chess[k][l]='x';
                        }else{
                            break;
                        }
                    }
                    for(k=i-1,l=j+1;k>=0 && l<8;k--,l++){
                        if(chess[k][l]==' ' || chess[k][l]=='x'){
                            chess[k][l]='x';
                        }else{
                            break;
                        }
                    }
                    for(k=i+1,l=j-1;k<8 && l>=0;k++,l--){
                        if(chess[k][l]==' ' || chess[k][l]=='x'){
                            chess[k][l]='x';
                        }else{
                            break;
                        }
                    }
                    for(k=i+1,l=j+1;k<8 && l<8;k++,l++){
                        if(chess[k][l]==' ' || chess[k][l]=='x'){
                            chess[k][l]='x';
                        }else{
                            break;
                        }
                    }
                }else if(chess[i][j]=='q' || chess[i][j]=='Q'){
                    for(int k=i-1;k>=0;k--){
                        if(chess[k][j]==' ' || chess[k][j]=='x'){
                            chess[k][j]='x';
                        }else{
                            break;
                        }
                    }
                    for(int k=i+1;k<8;k++){
                        if(chess[k][j]==' ' || chess[k][j]=='x'){
                            chess[k][j]='x';
                        }else{
                            break;
                        }
                    }
                    for(int k=j-1;k>=0;k--){
                        if(chess[i][k]==' ' || chess[i][k]=='x'){
                            chess[i][k]='x';
                        }else{
                            break;
                        }
                    }
                    for(int k=j+1;k<8;k++){
                        if(chess[i][k]==' ' || chess[i][k]=='x'){
                            chess[i][k]='x';
                        }else{
                            break;
                        }
                    }
                    int k,l;
                    for(k=i-1,l=j-1;k>=0 && l>=0;k--,l--){
                        if(chess[k][l]==' ' || chess[k][l]=='x'){
                            chess[k][l]='x';
                        }else{
                            break;
                        }
                    }
                    for(k=i-1,l=j+1;k>=0 && l<8;k--,l++){
                        if(chess[k][l]==' ' || chess[k][l]=='x'){
                            chess[k][l]='x';
                        }else{
                            break;
                        }
                    }
                    for(k=i+1,l=j-1;k<8 && l>=0;k++,l--){
                        if(chess[k][l]==' ' || chess[k][l]=='x'){
                            chess[k][l]='x';
                        }else{
                            break;
                        }
                    }
                    for(k=i+1,l=j+1;k<8 && l<8;k++,l++){
                        if(chess[k][l]==' ' || chess[k][l]=='x'){
                            chess[k][l]='x';
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(chess[i][j]==' '){
                    con++;
                }
            }
        }
        cout << con << '\n';
    }
}