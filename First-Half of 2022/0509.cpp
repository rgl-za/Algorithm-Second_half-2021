#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,a,b, count[101]={0}, result=0;
    cin >> A>> B >> C;
    for(int i=0; i<3; i++){
        cin >> a >> b;
        for(int j=a; j<b; j++){
            count[j]++;
        }
    }
    for(int i=1; i<101; i++){
        if(count[i]){
            if(count[i]==1) result += count[i]*A;
            else if (count[i] ==2) result +=count[i]*B;
            else if (count[i]==3 ) result += count[i]*C;
        }
    }
    cout << result << "\n";
    return 0;
}