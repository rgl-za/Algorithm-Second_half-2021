/*
//유클리드 호제법
int gcd(int n, int m){
    int r;
    while(m!=0){
        r=n%m;
        n=m;
        m=r;
    }
    return n;
}

int main(){
    int n, m;
    cin >> n >> m;

    cout << gcd(n,m) << (n*m)/gcd(n,m);
}
*/
/*
//최대공약수와 최소공배수
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a, b, r;
    
    a = n;
    b = m;
    
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;        
    }
    
    answer.push_back(a);
    answer.push_back(n * m / a);
    
    return answer;
}
*/

//하샤드 수

//숫자 자릿수 분리하기 a%10 -> a/=10
/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x){
    bool answer = true;
    vector<int>temp;
    int r;

    r=x;

    while(r != 0){
        temp.push_back(r%10);
        r/=10;
    }
    int sum=0;
    for(int i=0; i<temp.size(); i++){
        sum+=temp[i];
    }
    if(x%sum==0)
        answer = true;
    else if(x%sum !=0) 
        answer = false;

    return answer;
}

int main(){
    int x;

    cin >> x;

    cout << solution(x);
}
*/
/*
//콜라츠 추측

//간과한 점 정수가 int형 범위를 넘어갈 수 있는 점
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num){
    long long temp = num;
    int answer=0;

    while(1){
        if(temp == 1)
            break;

        if(temp%2==0){
            temp=temp/=2;
        }
        else{
            temp=temp*3+1;
        }
        answer++;

        if(answer == 500)
            return -1;
    }
    return answer;
}

int main(){
    int num;

    cin >> num;

    cout << solution(num);
}
*/

//핸드폰 번호 가리기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number){
    string answer="";

    for(int i=0; i<phone_number.size()-4;i++){
        answer.push_back('*');
    }
    for(int i=phone_number.size()-4; i<phone_number.size(); i++){
        answer.push_back(phone_number[i]);
    }

    return answer;
}

int main(){
    string phone_number;

    cin >> phone_number;

    cout << solution(phone_number);
}

