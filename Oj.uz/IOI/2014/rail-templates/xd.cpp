/* This is sample grader for the contestant */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int distan[5000][5000];
typedef struct Station {
  int index;
  int type;
  int location;
  int L,R;
}STATION;
long long cnt;
static int S,SUBTASK;
static STATION stations[10004];

int cmp_fun_1(const void *a,const void *b)
{
	STATION c,d;
	c = *(STATION*)(a);
	d = *(STATION*)(b);
  	return c.location < d.location ? -1 : 1;
}

int cmp_fun_2(const void *a,const void *b)
{
	STATION c,d;
	c = *(STATION*)(a);
	d = *(STATION*)(b);
  	return c.index < d.index ? -1 : 1;
}

void now_I_want_to_getLR(){
  int now = stations[S-1].index,i;
  for(i=S-2;i>=0;i--){
    stations[i].R = now;
    if(stations[i].type==2)	now = stations[i].index;
  }
  now = stations[0].index;
  for(i=1;i<S;i++){
    stations[i].L = now;
    if(stations[i].type==1)	now = stations[i].index;
  }
}

int getDistance(int x,int y)
{
  cnt++;
  if(x==y)	return 0;
  if(x<0 || x>=S || y<0 || y>=S)    return -1;
  if(stations[x].location > stations[y].location){
  	int tmp = x;
	x = y;
	y = tmp;
  }
  int ret = 0;
  if(stations[x].type==1 && stations[y].type==1){
    ret = stations[stations[y].R].location-stations[x].location+stations[stations[y].R].location-stations[y].location;
  }else if(stations[x].type==1 && stations[y].type==2){
    ret = stations[y].location-stations[x].location;
  }else if(stations[x].type==2 && stations[y].type==2){
    ret = stations[x].location-stations[stations[x].L].location+stations[y].location-stations[stations[x].L].location;
  }else if(stations[x].type==2 && stations[y].type==1){
    ret = stations[x].location-stations[stations[x].L].location+stations[stations[y].R].location
      -stations[stations[x].L].location+stations[stations[y].R].location-stations[y].location;
  }
  return ret;
}


void getInput()
{
  int g;
  g = scanf("%d",&SUBTASK);
  g = scanf("%d",&S);
  int s;
  for (s = 0; s < S; s++) {
    int type, location;
    g = scanf(" %d %d",&type,&location);
    stations[s].index = s;
    stations[s].location = location;
    stations[s].type = type;
    stations[s].L = -1;
    stations[s].R = -1;
  }
  qsort(stations, S, sizeof(STATION), cmp_fun_1);
  now_I_want_to_getLR();
  qsort(stations, S, sizeof(STATION), cmp_fun_2);
}

int serverGetStationNumber()
{
  return S;
}

int serverGetSubtaskNumber()
{
  return SUBTASK;
}

int serverGetFirstStationLocation()
{
  return stations[0].location;
}

int ask(int x,int y){
    if(x>y){
        swap(x,y);
    }
    if(distan[x][y]==0){
        distan[x][y]=getDistance(x,y);
    }
    return distan[x][y];
}
void findLocation(int N, int first, int location[], int stype[])
{
    stype[0]=1;
    location[0]=first;
    int mini=1e9,posde,posiz;
    vector<pair<int,int>> dist(N-1);
    for(int i=1;i<N;i++){
        dist[i-1]={ask(0,i),i};
    }
    sort(ALL(dist));
    set<int> izquierda,derecha;
    int izq=0,der=dist[1].second;
    izquierda.insert(location[izq]);
    derecha.insert(location[der]);
    location[der]=first+dist[1].first;
    stype[der]=2;
    for(int i=2;i<N;i++){
        int x=ask(izq,dist[i].second),y=ask(der,dist[i].second);
        //op1 esta directo con izq
        auto p=izquierda.lower_bound(location[izq]+x);
        p--;
        if(location[der]-*p+location[izq]+x-*p==y){
            stype[dist[i].second]=2;
            location[dist[i].second]=location[izq]+x;
            derecha.insert(location[dist[i].second]);
            if(location[dist[i].second]>location[der]){
                der=dist[i].second;
            }
        }else{
            stype[dist[i].second]=1;
            location[dist[i].second]=location[der]-y;
            izquierda.insert(location[dist[i].second]);
            if(location[dist[i].second]<location[izq]){
                izq=dist[i].second;
            }
        }
    }
    return;
}
int main()
{
  int i;
  getInput();
  cnt = 0;
  
  int location[10005];
  int type[10005];
  int ok = 1;
  findLocation(S, serverGetFirstStationLocation(),location, type);
  if(SUBTASK==3 && cnt>S*(S-1))	ok = 0;
  if(SUBTASK==4 && cnt>3*(S-1))	ok = 0;
  
  
  for (i = 0; i < S; i++){
    //cout << type[i] << ' ' << location[i] << endl;
    if(type[i]!=stations[i].type || location[i]!=stations[i].location)
      ok = 0;
  }
  if(ok==0)	printf("Incorrect");
  else	printf("Correct");
  return 0;
}
