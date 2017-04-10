#include <cstdio>
#include <cmath>

int main(){
	long long c, s, res;
	scanf("%lld", &c);
	for(int i=0; i<c; i++){
		scanf("%lld", &s);
		printf("%lld\n", (s*s)+(2*s));
	}
	return 0;
} 
