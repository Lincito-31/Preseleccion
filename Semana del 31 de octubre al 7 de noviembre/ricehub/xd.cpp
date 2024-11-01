#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int besthub(int R, int L, int X[], long long B)
{
  vll psum(R+1);
  psum[0]=0;
  psum[1]=X[0];
  for(int i=2;i<=R;i++){
    psum[i]=psum[i-1]+X[i-1];
  }
  int iz=0,de=0;
  int can=1;
  bool xd=false;
  while(iz<R && !xd){
    de=max(de,iz);
    int mid=(iz+de)/2;
    ll sum=(ll)((ll)X[mid]*(mid-iz)-(ll)(psum[mid]-psum[iz]));
    sum+=(ll)((ll)psum[de+1]-(ll)psum[mid+1]-(ll)X[mid]*(de-mid));
    while(sum<=B){
      de++;
      if(de>=R){
        xd=true;
        break;
      }
      sum=(ll)((ll)X[mid]*(mid-iz)-(ll)(psum[mid]-psum[iz]));
      sum+=(ll)((ll)psum[de+1]-(ll)psum[mid+1]-(ll)X[mid]*(de-mid));
    }
    can=max(can,de-iz);
    cout << iz << " " << de << " " << sum << endl;
    iz++;
  }
  return can;
}

#define MAX_R  1000000

static int R, L;
static long long B;
static int X[MAX_R];
static int solution;

inline 
void my_assert(int e) {if (!e) abort();}

static void read_input()
{
  int i;
  my_assert(3==scanf("%d %d %lld",&R,&L,&B));
  for(i=0; i<R; i++)
    my_assert(1==scanf("%d",&X[i]));
  my_assert(1==scanf("%d",&solution));
}

int main()
{
  int ans;
  read_input();
  ans = besthub(R,L,X,B);
  /*if(ans==solution)
    printf("Correct.\n");
  else
    printf("Incorrect.  Returned %d instead of %d.\n",ans,solution);*/

  return 0;
}
