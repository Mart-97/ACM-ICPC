#include <bits/stdc++.h>
using namespace std;
#define INF 1ULL<<30
#define MAXN 100005
#define MOD 2005
#define pb push_back
#define mp make_pair
#define forn(r,a,b) for(int r = a; r<b; r++)
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define fst first
#define snd second
#define B 127
#define endl '\n'
#define pi 3.14159
typedef long long int lli;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,string> iis;
typedef vector<ii> vii;
typedef vector<int> vi;
int city[MAXN];
int n,k,queries;
priority_queue <pair < pair <int,int>, pair <string,int> > > pq;
int main(){
  optimizar_io;
  int tc;
  cin >> tc;
  while(tc--){
    pair<pair<int,int> , pair <string, int> > state;

    int a,b,f;
    string s;
    cin >>  a  >> b;
    for(int i = 0; i<a; i++){
      cin >> s >> f;
      state.fst.fst = -f;
      state.fst.snd = -(i + 1);
      state.snd.fst = s;
      state.snd.snd = f;
      pq.push(state);
    }
    for(int i = 0; i<b; i++){
      state = pq.top();
      cout << -state.fst.fst << " "<< state.snd.fst<<endl;
      pq.pop();
      state.fst.fst = -(-state.fst.fst + (state.snd.snd));
      pq.push(state);
    }
  }
  
  return 0;

}
