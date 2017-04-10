#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int n;
unsigned num;
unsigned comb, res, aux;
int e;

int main(){
	res = pow(2,32)-1;
	scanf("%d", &n);
	while(n--){
		comb = 0;
		scanf("%u", &num);
		for(int i = 0; i < 32; i++){
			if(i < 28){
				aux = 1 << ((num & (31 << i)) >> i);
			}else{
				e = 32 - i;
				switch(e){
					case 1:
						e = (num & 15) << 1;
						break;
					case 2:
						e = (num & 7) << 2;
						break;
					case 3:
						e = (num & 3) << 3;
						break;
					case 4:
						e = (num & 1) << 4;
						break;
				}
				aux = 1 << (31 & ((num >> i) | e));
			}
			comb |= aux;
		}
		 comb == res ? printf("yes\n") : printf("no\n");
	}

	return 0;
}
