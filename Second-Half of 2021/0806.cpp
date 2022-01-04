//직사각형 별찍기
#include <iostream>
using namespace std;

int main(){

    int a,b;

    cin >> a >> b;

    for(int i=0; i<b; i++){
        // cout <<"*";
        for(int j=0; j<a; j++){
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}


// x만큼 간격이 있는 n개의 숫자
#include <iostream>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n){
    vector<long long> answer;

    for(int i=1; i<=n; i++){
        answer.push_back(i*x);
    }

    return answer;
}

int main(){

    int n, x;

    cin >> x >> n;

    vector<long long> result(n);

    result=solution(x,n);

    for(int i=0; i<result.size(); i++){
        cout << result[i];
    }
    return 0;
}

//제일 작은 수 제거하기

//내가 짠 코드 뭔가 의도는 비슷하나 접근이 이상함
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr){

    vector<int> answer;
    int min;

    min=*min_element(arr.begin(), arr.end());

    erase(remove(arr.begin(), arr.end(), min), arr.end());
    

    if(arr.size()<=1){
        return -1;
    }

    return answer;

}

// 참고한 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr){
    vector<int> answer;

    if(arr.size()==1){
        answer.push_back(-1);

        return answer;
    }

    arr.erase(min_element(arr.begin(), arr.end()));
    answer=arr;

    return answer;
}


//정수 제곱근 판별
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n){
    long long answer=0;
    long long check = sqrt(n);

    if(check * check == n)
        answer = (check+1) * (check+1);
    else
        answer = -1;

    return answer;
}

int main(){
    int n;

    cin >> n;

    cout << solution(n);
}


