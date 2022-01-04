//두 정수 사이의 합
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

long long solution(int a, int b){
    long long answer = 0;


    if(a<b){
        for(int i=a; i<=b; i++){
            answer+=i;
        }
    }

    else if(a>b){
        for(int i=b; i<=a; i++){
            answer+=i;
        }
    }

    else if(a==b)
        answer = a;
    
    return answer;
} 

int main(){
    int a,b;

    cin >> a >> b;

    cout << solution(a,b);
}

//자연수 뒤집어서 배열로 만들기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(long long n){
    vector<int> answer;

    while(n){
        answer.push_back(n%10);
        n/=10;
    }
    return answer;

}

//나누어 떨어지는 숫자 배열
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor){
    vector<int> answer;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]%divisor==0){
            answer.push_back(arr[i]);
        }
    }

    if(answer.size()==0){
        answer.push_back(-1);
    }

    sort(answer.begin(), answer.end());

    return answer;

}

//문자열 내 마음대로 정렬하기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int m;
bool cmp(string a, string b){
    if(a[m] != b[m]) // m기준 정렬
        return a[m]<b[m];

    else //default 
        return a<b;
}

vector<string> solution(vector<string>strings, int n){

    m=n;

    sort(strings.begin(), strings.end(), cmp);

    return strings;
}
