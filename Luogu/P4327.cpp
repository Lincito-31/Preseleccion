#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FIN "\n"
#define REP(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) x.begin(),x.end()
#define LSOne(x) (x)&-(x)
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<long long> vll;
string st;
int main()
{
    FASTIO;
    cin >> st;
    int tam=st.size()*4+1;
    vector<vector<char>> mat(5,vector<char>(tam,' '));
    int i=2;
    int con=0;
    while(i<tam){
        mat[2][i]=st[con];
        con++;
        if(con%3==0){
            mat[0][i]=mat[1][i-1]=mat[1][i+1]=mat[2][i-2]=mat[2][i+2]=mat[3][i-1]=mat[3][i+1]=mat[4][i]='*';
        }else{
            if(mat[2][i-2]=='*'){
                mat[0][i]=mat[1][i-1]=mat[1][i+1]=mat[2][i+2]=mat[3][i-1]=mat[3][i+1]=mat[4][i]='#';
            }else{
                mat[0][i]=mat[1][i-1]=mat[1][i+1]=mat[2][i-2]=mat[2][i+2]=mat[3][i-1]=mat[3][i+1]=mat[4][i]='#';
            }
        }
        i+=4;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<tam;j++){
            if(mat[i][j]==' '){
                cout << '.';
            }else{
                cout << mat[i][j];
            }
        }
        cout << "\n";
    }
}
