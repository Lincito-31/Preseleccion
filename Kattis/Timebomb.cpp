#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef long double ld;
int fin;
string mat[5];
string numero[10]=
{   "***\n* *\n* *\n* *\n***\n",
    "  *\n  *\n  *\n  *\n  *\n",
    "***\n  *\n***\n*  \n***\n",
    "***\n  *\n***\n  *\n***\n",
    "* *\n* *\n***\n  *\n  *\n",
    "***\n*  \n***\n  *\n***\n",
    "***\n*  \n***\n* *\n***\n",
    "***\n  *\n  *\n  *\n  *\n",
    "***\n* *\n***\n* *\n***\n",
    "***\n* *\n***\n  *\n***\n"
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<5;i++){
        getline(cin,mat[i]);
    }
    for(int i=0;i<mat[0].size()-2;i+=4){
        fin*=10;
        string temp="";
        for(int j=0;j<5;j++){
            for(int k=0;k<3;k++){
                temp.push_back(mat[j][i+k]);
            }
            temp.push_back('\n');
        }
        for(int j=0;j<10;j++){
            if(temp==numero[j]){
                fin+=j;
                break;
            }
        }
    }
    //cout << fin;
    if(fin%6!=0){
        cout << "BOOM!!";
    }else{
        cout << "BEER!!";
    }
}