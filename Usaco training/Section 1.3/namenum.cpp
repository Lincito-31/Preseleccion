/*
ID: simplem2
TASK: namenum
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int n;
bool xd,lol;
string st[5000],x;
string name;
unordered_map<char, string>mapa={
    {'2', "ABC"}, {'3', "DEF"}, {'4', "GHI"},
    {'5', "JKL"}, {'6', "MNO"}, {'7', "PRS"},
    {'8', "TUV"}, {'9', "WXY"}
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    name="dict.txt";
    ifstream in1(name);
    name="namenum.in";
    ifstream in2(name);
    ofstream fout("namenum.out");
    while(in1 >> st[n++]);
    in2 >> x;
    for(int i=0;i<n;i++){
        if(st[i].size()==x.size()){
            xd=true;
            for(int j=0;j<x.size();j++){
                if(!(mapa[x[j]][0]==st[i][j] || mapa[x[j]][1]==st[i][j] || mapa[x[j]][2]==st[i][j])){
                    xd=false;
                    break;
                }
            }
            if(xd){
                lol=true;
                fout << st[i] << '\n';
            }
        }
    }
    if(!lol){
        fout << "NONE\n";
    }
}
