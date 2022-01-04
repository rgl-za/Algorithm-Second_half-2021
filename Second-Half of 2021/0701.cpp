#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, s;

    cin >> n >> s;
    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    int start = 0, end = 0, sum = 0, len = n;
    bool flag = false;

    while(start<=end){
        if(sum>=s){
            flag=true;
            len=min(len,end-start);
            sum-=v[start++];
        }
        else if(end == n)
            break;
        else 
            sum+=v[end++];
    }
    if(flag)
        cout << len << endl;
    else    
        cout << 0;

    return 0;
}