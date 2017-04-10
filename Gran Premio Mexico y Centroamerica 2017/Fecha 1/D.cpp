#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair


using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int root = sqrt(n);
		int ans = 1;
		for(int i = 2; i<=root; i++){
			if(n % i == 0){
				ans += i + n/i;
				///printf("%d %d ",i, n / i);
			}
		}
		if(root * root == n) ans-= root;
		///printf("%d\n",ans);
		if(ans > n) puts("abundant");
		if(ans == n) puts("perfect");
		if(ans < n) puts("deficient");
	}
	return 0 ;
}
