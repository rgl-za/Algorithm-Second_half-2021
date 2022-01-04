
//약수의 합
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            answer+=i;
        }
    }
    return answer;
}

// 평균 구하기
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    double sum = 0;
    
    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
        
    }
    answer= sum/arr.size();
    
    return answer;
}

// 짝수와 홀수
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    
    if(num%2==0)
        answer="Even";
    else
        answer= "Odd";
    
    return answer;
}

// 자릿수 더하기
#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;
    string conversion;

    
    conversion = to_string(n);
        
    for(int i=0; i<conversion.size(); i++){
        answer += conversion[i]-'0';
    }

    return answer;
}


