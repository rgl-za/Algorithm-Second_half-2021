//124 나라의 숫자

//내가 시도한 방법
#include <iostream>
#include <vector>
#include <string>
// #include <initializer_list>

using namespace std;

// #define V {1, 2, 4}

string solution(int n){
    string answer="";
    vector<int> v = {1, 2, 4};

    if(n<=3){
        for(int i=0; i<v.size(); i++){
            answer=v[i];
        }
    }

    if(n>=4){
        while(n/3 > 0){
            answer = v[n%3]+answer;
            n /= 3;
        }
        answer=v[n%3]+answer;
    }
    return answer;
}

//참고한 코드
#include<iostream>
#include<vector>
#include<string>

using namespace std;

string solution(int n){
    string answer="";

    string str[3]={"4", "1", "2"};

    while(n){
        answer=str[n%3]+answer;

        if(!(n%3))
            n=n/3-1;
        else    
            n=n/3;
    }
    return answer;
}

int main(){
    
    int n;

    cin >> n;

    cout << solution(n);
}



//3진법 뒤집기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int n){
    int answer = 0;
    vector<int> v;

   while(n){
       v.push_back(n%3);

       n/=3;
   }
   reverse(v.begin(), v.end());

   for(int i=0; i<v.size(); i++){
       answer+=pow(3,i)*v[i];
   }
   return answer;
}

int main(){

    int n;

    cin >> n;

    cout << solution(n);
}
