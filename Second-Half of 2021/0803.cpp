//수박수박수

#include <string>
#include <vector>

using namsespace std;

string solution(int n){
    string answer="";
    
    for(int i=0; i<n; i++){
        if(i%2 ==0)
            answer += "수";
        else
            answer += "박";
    }
    return answer;
} 


//정수 내림차수 배치

#include <iostream>
#include <string>
#include <vector>
#include <sort>

using namespace std;

long long solution(long long n){
    long long answer=0;

    string conversion = to_string(n);

    sort(conversion.begin(), conversion.end(), greater<char>());
    
    answer=stoll(conversion); //string을 longlong으로 변환

    return answer;
}

//문자열 정수로 변환
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    answer=stoi(s);
    
    return answer;
}



