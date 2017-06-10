#include <bits/stdc++.h>
using namespace std;
#define INF 1 << 30
#define MAXN 1000000
#define MOD 2005
#define pb push_back
#define mp make_pair
#define forr(i,a,b) for(int i = (a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define fst first
#define snd second
#define B 127
#define endl '\n'
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,string> iis;
typedef vector<ii> vii;
typedef vector<ll> vi;
vi primes;
ll expBin(ll a,ll n){
  if(n == 0) return 1;
  if(n == 1) return a;
  ll nextPow = expBin(a, n/2);
  nextPow = (nextPow * nextPow); /// % MOD
  if(n % 2 == 0)
    return nextPow;
  return (nextPow * a); /// % MOD
}


bool isprime[2*MAXN];
void criba(){
  ///memset(isprime,true,sizeof isprime);
  for(ll i = 2; i<MAXN;i++){
    //cout << i<< endl;
    if(!isprime[i]){
      for(ll j = i * i; j<MAXN; j+=i){
        ///cout << "j " << j << endl;
        isprime[j] = true;
      }
      primes.pb(i);
    }
  }

}
ll sumDiv(ll n){
  ll pf_idx = 0, PF = primes[pf_idx],ans = 1;
  while(PF * PF <=n){
    ll power = 0;
    while(n % PF == 0) {
      n /= PF; 
      power++;
    }
    ans*= (expBin(PF,power + 1)-1) / (PF - 1); 
    PF = primes[++pf_idx];
  }
  if(n != 1) ans*= (expBin(n,2)-1) / (n - 1); 
  return ans;
}
int main(){
  int n;
  optimizar_io;
  criba();
  cin >> n;
  forn(i,n){
    ll a;
    cin >> a;
    ll ans = sumDiv(a) - a;
    if(ans < a) cout << "deficient";
    if(ans == a) cout << "perfect";
    if(ans > a ) cout << "abundant";
    cout << endl;
  }
  return 0;
}
