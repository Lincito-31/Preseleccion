#include "dna.h"
#include <bits/stdc++.h>
using namespace std;
string x,y;
int n;
vector<vector<int>> psum;
void init(string a,string b){
	x=a;y=b;
	n=a.size(); 
	psum.assign(10,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		psum[6][i]=psum[6][i-1]+(a[i-1]=='A');
		psum[7][i]=psum[7][i-1]+(a[i-1]=='T');
		psum[8][i]=psum[8][i-1]+(b[i-1]=='A');
		psum[9][i]=psum[9][i-1]+(b[i-1]=='T');
		psum[4][i]=psum[4][i-1],psum[5][i]=psum[5][i-1],psum[0][i]=psum[0][i-1],psum[1][i]=psum[1][i-1],psum[2][i]=psum[2][i-1],psum[3][i]=psum[3][i-1];
		if(a[i-1]=='A'){
			if(b[i-1]=='T')psum[1][i]++;
			if(b[i-1]=='C')psum[4][i]++;
		}else if(a[i-1]=='T'){
			if(b[i-1]=='A')psum[0][i]++;
			if(b[i-1]=='C')psum[2][i]++;
		}else{
			if(b[i-1]=='A')psum[5][i]++;
			if(b[i-1]=='T')psum[3][i]++;
		}
	}
}
int get_distance(int x, int y){
	if((psum[6][y+1]-psum[6][x]==psum[8][y+1]-psum[8][x]) && (psum[7][y+1]-psum[7][x]==psum[9][y+1]-psum[9][x])){
        int AC=psum[4][y+1]-psum[4][x],CA=psum[5][y+1]-psum[5][x],AT=psum[1][y+1]-psum[1][x],TA=psum[0][y+1]-psum[0][x],TC=psum[2][y+1]-psum[2][x],CT=psum[3][y+1]-psum[3][x];
		int con1=min(AC,CA),con2=min(AT,TA),con3=min(TC,CT);
		return con1+con2+con3+((AC+CA+TA+AT+CT+TC-2*con1-2*con2-2*con3)/3)*2;;
    }else{
        return -1;
    }
}
