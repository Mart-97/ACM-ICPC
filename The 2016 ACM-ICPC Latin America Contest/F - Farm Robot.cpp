#include<bits/stdc++.h>
using namespace std;
int farm[102];
int pos;
int main() {
    int n,c,s,command;
    cin >> n >> c >> s;
    while(c--){
        cin >> command;
        if(command == 1){
            farm[pos]++;
            pos = (pos + 1) % n;
        }else {
            farm[pos]++;
            pos = ( pos + n - 1) % n;
        }
    }
    farm[pos]++;
    printf("%d\n",farm[s - 1]);
    return 0;
}
