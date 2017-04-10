#include <bits/stdc++.h>
using namespace std;
#define INF 1ULL<<30
#define MAXN 5004
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define forn(r,a,b) for(int r = a; r<b; r++)
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define fst first
#define snd second

typedef long long int lli;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,string> iis;
typedef vector<iii> viii;
typedef vector<int> vi;
vi primes;
int MAX = 5000;
bool isprime[MAXN];
lli C[MAXN][MAXN];
lli divisores[MAXN];
void Pascal(int n,int k){
  /*for(int i = 0; i<=k; i++){
    C[0][i] = 1;
  }*/
  for(int i = 0; i<=n; i++){
    C[i][0] = 1;
  }
  for (int i = 1; i <= n; i++){
    for(int j = 1; j<=k; j++){
      if(i == 1 || i == j){
        C[i][j] = 1;
      }else {
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
      }

    }
  }
}
lli nCr(int n,int k){
  return C[n][k];
}
void factorizar(int n){
  for(int i = 2; i<=n; i++){
    int aux = i;
    int divs = 1,sum;
    int j = 0;
    while(aux != 1){
      sum = 1;
      while(aux % primes[j] == 0){
        aux = aux / primes[j];
        sum++;
      }
      j++;
      divs = ((divs % MOD) * (sum % MOD)) %MOD; 
    }
    divisores[i] = divs;
  }
}
void criba(int n){
  ///int root = sqrt(n);
  for(int i = 2; i<=n; i++){
    if(!isprime[i]){
      for(int j = i * i; j<=n; j+=i){
        isprime[j]= true;
      }
      primes.pb(i);
    }
  }
}

int main(){
  criba(MAX);
  Pascal(MAX,MAX);
  factorizar(MAX);
  int tc;
  scanf("%d",&tc);
  while(tc--){
    int n,k;
    scanf("%d %d",&n,&k);
    int sum = 0;
    int count = 1;
    int div_actual;
    for(int i = 2; i<=n; i++){
      if(divisores[i] > k) div_actual = k;
      else div_actual = divisores[i] - 1;
      sum = ((sum % MOD) + ((div_actual) % MOD)) %MOD;
      if(divisores[i] - 1 > k){
        count = ((count % MOD) * (nCr(divisores[i]-1,k) % MOD)) %MOD;
      }
    }
    printf("%d %d\n",sum,count);
  }
  return 0;
    
}
