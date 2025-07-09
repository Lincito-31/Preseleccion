#include <bits/stdc++.h>
using namespace std;
char ori[3][3];
int indivi,par;
bool board[3][3];
bool check(){
    if(board[0][0]&board[1][1]&board[2][2]){
        return true;
    }
    if(board[2][0]&board[1][1]&board[0][2]){
        return true;
    }
    for(int i=0;i<3;i++){
        if(board[i][0]&board[i][1]&board[i][2]){
            return true;
        }
        if(board[0][i]&board[1][i]&board[2][i]){
            return true;
        }
    }
    return false;
}
bool check2(){
    if(board[0][0]&board[1][1]&board[2][2] && !(ori[0][0]==ori[1][1] && ori[0][0]==ori[2][2])){
        return true;
    }
    if(board[2][0]&board[1][1]&board[0][2] && !(ori[2][0]==ori[1][1] && ori[2][0]==ori[0][2])){
        return true;
    }
    for(int i=0;i<3;i++){
        if(board[i][0]&board[i][1]&board[i][2] && !(ori[i][0]==ori[i][1] && ori[i][0]==ori[i][2])){
            return true;
        }
        if(board[0][i]&board[1][i]&board[2][i] && !(ori[0][i]==ori[1][i] && ori[0][i]==ori[2][i])){
            return true;
        }
    }
    return false;
}
int main(){
    ifstream in("tttt.in");
    ofstream out("tttt.out");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            in >> ori[i][j];
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                board[j][k]=(ori[j][k]-'A'==i);
            }
        }
        if(check()){
            indivi++;
        }
        for(int l=i+1;l<26;l++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    board[j][k]=(ori[j][k]-'A'==i || ori[j][k]-'A'==l);
                }
            }
            if(check2()){
                par++;
            }
        }
    }
    out << indivi << '\n' << par;
}