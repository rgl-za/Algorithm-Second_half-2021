//11047
#include <iostream>
using namespace std;

int main(){
    int n, k;

    cin >> n >> k;

    int coins[n];

    for(int i=0; i<n; i++){
        cin >> coins[i];

    }
    int count = 0;
    for(int i = n-1; i>0;){
        if(coins[i]>k){
            i--;
            continue;
        }
        k-=coins[i];
        count++;
    }

    cout << count;

   return 0;
}

//2875
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, k;
    int team=0, total=0;
    cin >> n >> m >> k;
    
    total=n+m-k;

    while(n>1 && m>0 && total >2){
        n-=2;
        m-=1;
        total-=3;

        team++;
    }
    
    cout << team;

    return 0;
}
