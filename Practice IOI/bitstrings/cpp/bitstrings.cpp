#include "bitstrings.h"
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int count_duplicated(string S){
  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  ll constante=uniform_int_distribution<ll> (1,MOD-1)(rng);
  int N=S.size();
  vector<ll> prefhash(N),prefpower(N);
  prefhash[0]=S[0];
  prefpower[0]=1;
  for(int i=1;i<N;i++){
    prefhash[i]=prefhash[i-1]*constante+S[i];
    prefhash[i]%=MOD;
    prefpower[i]=prefpower[i-1]*constante;
    prefpower[i]%=MOD;
  }
  set<ll> contador;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j+=2){
      int mid=(i+j)/2;
      // checkear si del i al mid es igual de mid+1 al j;
      ll i_mid,mid_j;
      if(i==0){
        i_mid=prefhash[mid];
      }else{
        i_mid=prefhash[mid]-prefhash[i-1]*prefpower[mid-i+1];
        i_mid%=MOD;
        i_mid+=MOD;
        i_mid%=MOD;
      }
      mid_j=prefhash[j]-prefhash[mid]*prefpower[j-mid];
      mid_j%=MOD;
      mid_j+=MOD;
      mid_j%=MOD;
      if(i_mid==mid_j){
        contador.insert(i_mid);
      }
    }
  }
  return contador.size();
}
/*ll constante;
map<ll,ll> contador;
string res="";
bool xd=false;
string superes="";
vector<ll> prefhash(100),prefpower(100);
void solve_weak(int pos){
  if(xd){
    return;
  }
  if(pos==100){
    superes=res;
    xd=true;
    return;
  }
  res.push_back('0');
  if(pos==0){
    prefhash[pos]='0';
  }else{
    prefhash[pos]=prefhash[pos-1]*constante+'0';
    prefhash[pos]%=MOD;
    prefhash[pos]+=MOD;
    prefhash[pos]%=MOD;
  }
  for(int i=pos-1;i>=0;i-=2){
    int mid=(i+pos)/2;
    //check del i al mid y del mid+1 al pos;
    ll i_mid,mid_pos;
    if(i==0){
      i_mid=prefhash[mid];
    }else{
      i_mid=prefhash[mid]-prefhash[i-1]*prefpower[mid-i+1];
      i_mid%=MOD;
      i_mid+=MOD;
      i_mid%=MOD;
    }
    mid_pos=prefhash[pos]-prefhash[mid]*prefpower[pos-mid];
    mid_pos%=MOD;
    mid_pos+=MOD;
    mid_pos%=MOD;
    if(i_mid==mid_pos){
      contador[i_mid]++;
    }
  }
  if(contador.size()<=3){
    solve_weak(pos+1);
  }
  for(int i=pos-1;i>=0;i-=2){
    int mid=(i+pos)/2;
    //check del i al mid y del mid+1 al pos;
    ll i_mid,mid_pos;
    if(i==0){
      i_mid=prefhash[mid];
    }else{
      i_mid=prefhash[mid]-prefhash[i-1]*prefpower[mid-i+1];
      i_mid%=MOD;
      i_mid+=MOD;
      i_mid%=MOD;
    }
    mid_pos=prefhash[pos]-prefhash[mid]*prefpower[pos-mid];
    mid_pos%=MOD;
    mid_pos+=MOD;
    mid_pos%=MOD;
    if(i_mid==mid_pos){
      contador[i_mid]--;
      if(contador[i_mid]==0){
        contador.erase(i_mid);
      }
    }
  }
  res.pop_back();
  res.push_back('1');
  if(pos==0){
    prefhash[pos]='1';
  }else{
    prefhash[pos]=prefhash[pos-1]*constante+'1';
    prefhash[pos]%=MOD;
    prefhash[pos]+=MOD;
    prefhash[pos]%=MOD;
  }
  for(int i=pos-1;i>=0;i-=2){
    int mid=(i+pos)/2;
    //check del i al mid y del mid+1 al pos;
    ll i_mid,mid_pos;
    if(i==0){
      i_mid=prefhash[mid];
    }else{
      i_mid=prefhash[mid]-prefhash[i-1]*prefpower[mid-i+1];
      i_mid%=MOD;
      i_mid+=MOD;
      i_mid%=MOD;
    }
    mid_pos=prefhash[pos]-prefhash[mid]*prefpower[pos-mid];
    mid_pos%=MOD;
    mid_pos+=MOD;
    mid_pos%=MOD;
    if(i_mid==mid_pos){
      contador[i_mid]++;
    }
  }
  if(contador.size()<=3){
    solve_weak(pos+1); 
  }
  for(int i=pos-1;i>=0;i-=2){
    int mid=(i+pos)/2;
    //check del i al mid y del mid+1 al pos;
    ll i_mid,mid_pos;
    if(i==0){
      i_mid=prefhash[mid];
    }else{
      i_mid=prefhash[mid]-prefhash[i-1]*prefpower[mid-i+1];
      i_mid%=MOD;
      i_mid+=MOD;
      i_mid%=MOD;
    }
    mid_pos=prefhash[pos]-prefhash[mid]*prefpower[pos-mid];
    mid_pos%=MOD;
    mid_pos+=MOD;
    mid_pos%=MOD;
    if(i_mid==mid_pos){
      contador[i_mid]--;
      if(contador[i_mid]==0){
        contador.erase(i_mid);
      }
    }
  }
  res.pop_back();
}*/
string find_weakest(){
  /*mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  constante=uniform_int_distribution<ll> (1,MOD-1)(rng);
  prefpower[0]=1;
  for(int i=1;i<100;i++){
    prefpower[i]=prefpower[i-1]*constante;
    prefpower[i]%=MOD;
  }
  solve_weak(0);*/
  return "0001011000111001011000101110001100101100010111001011000111001011100010110001110010110001011100011001";
  //return superes;
}
//forma1:
// setear limites {(0,0)(10,1),(20,4),(30,9),(40,16),(50,25),(60,36),(70,49),(80,60),(90,70),(100,80)}
// forma2:
map<int,int> limites={
  {0,0},{10,1},{20,4},{30,4},{40,9},{50,9},{60,16},{70,25},{80,36},{90,49},{100,60}
};
// añadir el de menor cantidad si ninguno aumenta,
ll constante,conta0=0,conta1=0;
map<ll,ll> contador;
string res="";
bool xd=false;
string superes="";
vector<ll> prefhash(100),prefpower(100);
void solve_strong(int pos){
  if(pos==100){
    superes=res;
    return;
  }
  res.push_back('0');
  if(pos==0){
    prefhash[pos]='0';
  }else{
    prefhash[pos]=prefhash[pos-1]*constante+'0';
    prefhash[pos]%=MOD;
    prefhash[pos]+=MOD;
    prefhash[pos]%=MOD;
  }
  for(int i=pos-1;i>=0;i-=2){
    int mid=(i+pos)/2;
    //check del i al mid y del mid+1 al pos;
    ll i_mid,mid_pos;
    if(i==0){
      i_mid=prefhash[mid];
    }else{
      i_mid=prefhash[mid]-prefhash[i-1]*prefpower[mid-i+1];
      i_mid%=MOD;
      i_mid+=MOD;
      i_mid%=MOD;
    }
    mid_pos=prefhash[pos]-prefhash[mid]*prefpower[pos-mid];
    mid_pos%=MOD;
    mid_pos+=MOD;
    mid_pos%=MOD;
    if(i_mid==mid_pos){
      contador[i_mid]++;
    }
  }
  if(contador.size()>=(--limites.upper_bound(pos))->second){
    solve_strong(pos+1);
  }
  for(int i=pos-1;i>=0;i-=2){
    int mid=(i+pos)/2;
    //check del i al mid y del mid+1 al pos;
    ll i_mid,mid_pos;
    if(i==0){
      i_mid=prefhash[mid];
    }else{
      i_mid=prefhash[mid]-prefhash[i-1]*prefpower[mid-i+1];
      i_mid%=MOD;
      i_mid+=MOD;
      i_mid%=MOD;
    }
    mid_pos=prefhash[pos]-prefhash[mid]*prefpower[pos-mid];
    mid_pos%=MOD;
    mid_pos+=MOD;
    mid_pos%=MOD;
    if(i_mid==mid_pos){
      contador[i_mid]--;
      if(contador[i_mid]==0){
        contador.erase(i_mid);
      }
    }
  }
  res.pop_back();
  res.push_back('1');
  if(pos==0){
    prefhash[pos]='1';
  }else{
    prefhash[pos]=prefhash[pos-1]*constante+'1';
    prefhash[pos]%=MOD;
    prefhash[pos]+=MOD;
    prefhash[pos]%=MOD;
  }
  for(int i=pos-1;i>=0;i-=2){
    int mid=(i+pos)/2;
    //check del i al mid y del mid+1 al pos;
    ll i_mid,mid_pos;
    if(i==0){
      i_mid=prefhash[mid];
    }else{
      i_mid=prefhash[mid]-prefhash[i-1]*prefpower[mid-i+1];
      i_mid%=MOD;
      i_mid+=MOD;
      i_mid%=MOD;
    }
    mid_pos=prefhash[pos]-prefhash[mid]*prefpower[pos-mid];
    mid_pos%=MOD;
    mid_pos+=MOD;
    mid_pos%=MOD;
    if(i_mid==mid_pos){
      contador[i_mid]++;
    }
  }
  if(contador.size()>=(--limites.upper_bound(pos))->second){
    solve_strong(pos+1);
  }
  for(int i=pos-1;i>=0;i-=2){
    int mid=(i+pos)/2;
    //check del i al mid y del mid+1 al pos;
    ll i_mid,mid_pos;
    if(i==0){
      i_mid=prefhash[mid];
    }else{
      i_mid=prefhash[mid]-prefhash[i-1]*prefpower[mid-i+1];
      i_mid%=MOD;
      i_mid+=MOD;
      i_mid%=MOD;
    }
    mid_pos=prefhash[pos]-prefhash[mid]*prefpower[pos-mid];
    mid_pos%=MOD;
    mid_pos+=MOD;
    mid_pos%=MOD;
    if(i_mid==mid_pos){
      contador[i_mid]--;
      if(contador[i_mid]==0){
        contador.erase(i_mid);
      }
    }
  }
  res.pop_back();
}
string find_strongest(){
  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  constante=uniform_int_distribution<ll> (1,MOD-1)(rng);
  prefpower[0]=1;
  for(int i=1;i<100;i++){
    prefpower[i]=prefpower[i-1]*constante;
    prefpower[i]%=MOD;
  }
  solve_strong(0);
  return superes;
}
int main(){
  cout << find_strongest();
}