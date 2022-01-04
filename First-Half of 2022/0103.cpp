// BOJ 1158 요세푸스 문제
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, K;
    queue<int>circle;

    cin >> N >> K;

    for(int i=0; i<N; i++)
        circle.push(i+1);
    
    cout << "<";
    while(circle.size()-1){
        for(int i=0; i<K-1; i++){
            circle.push(circle.front());
            circle.pop();
        }
        cout << circle.front() << ",";
        circle.pop();
    }
    cout << circle.front() << ">";
    return 0;
}


// BOJ 10828 스택
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int N;
    stack<int>S;

    cin >> N;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;

        if(str == "push"){
            int x;
            cin >> x;
            S.push(x);
        }
        else if(str == "top"){
            if(S.empty()) cout << "-1" << endl;
            else cout << S.top() << endl;
        }
        else if(str == "pop"){
            if(S.empty()) cout << "-1" << endl;
            else{
                cout << S.top() << endl;
                S.pop();
            }
        }
        else if (str == "empty")
            cout << S.empty() << endl; 
        else
            cout << S.size() << endl;
    }
    return 0;
}