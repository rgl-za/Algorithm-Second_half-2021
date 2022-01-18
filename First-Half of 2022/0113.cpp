// BOJ 5597
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int students[31]={0};
    int n;

    for(int i=1; i<=28; i++){
        cin >> n;
        students[n]=1;

    }

    for(int i=1; i<=30; i++){
       if(students[i]==0)
           cout << i << '\n';
       
    }

    return 0;
}

// BOJ 1260
// DFS: 깊이 <-> BFS: 넓이
