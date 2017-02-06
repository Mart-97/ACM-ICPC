#include <bits/stdc++.h>

using namespace std;
int a,b,c,d;
int main(){
    cin >> a >> b >> c >> d;
    int p1 = abs(a+b-(c+d));
    int p2 = abs(a+c-(d+b));
    int p3 = abs(a+d-(b+c));
    printf("%d\n",min(p1,min(p2,p3)));
return 0;
}
