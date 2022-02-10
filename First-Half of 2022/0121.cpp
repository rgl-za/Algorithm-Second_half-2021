#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, sum, digit;

    cin >> n;

    for(int i=1; i<n; i++){
        sum = i;
        digit = i;
        while(digit){
            sum += digit % 10;
            digit /= 10;
        }
        if(n == sum){
            cout << i << endl;
            return 0;
        }
    }
    cout << "0" << endl;

    return 0;
}