//완주하지 못한 선수
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion){
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<participant.size(); i++){
        if(participant[i] != completion[i])
            return participant[i];
    }
}


//실패율 (개어렵다 이게 레벨1이라고?)
//내가 생각한 풀이
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp()

vector<int> solution(int N, vector<int> stages){
    vector<int> answer;
    vector<int> temp;
    int check =0;

    sort(stages.begin(), stages.end());

    for(int i=0; i<stages.size(); i++){
        for(int j= i+1; j<stages.size(); j++){
            if(stages[i] == stages[j]){
                check++;
            }
            erase(i,j);
        }
    temp.push_back((check/stages.size))
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}


//참고한 풀이
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages){
    vector<int> answer;
    vector<double> rate;
    double user=stages.size();

    for(int i=1; i<=N; i++){
        double count=0;

        for(int j=0; j<stages.size(); j++){
            if(stages[j]==i)
                count++;
        }

        if(count==0)
            rate.push_back(0);

        else
            rate.push_back(count/user);

        user-=count;
    }

    for(int i=0; i<N; i++){
        auto itr=max_element(rate.begin(), rate.end());

        answer.push_back(itr-rate.begin()+1);

        *itr=-111;
    }
    return answer;
}

/*
모든 스테이지의 실패율을 구했으면 실패율을 내림차순으로 나열했을 때의 스테이지 번호를

answer에 넣어주어야 한다.

약간(?) 헷갈릴 수 있는 부분이다.

auto itr = max_element(rate.begin(), rate.end();

를 사용하였다.

auto는 자동으로 형을 정해주기 때문에 많이 활용된다..!

max_element()함수는 반복자를 리턴해주므로 itr은 결국 iterator형이 된다.

rate.begin()부터 rate.end()까지 가장 큰 값을 가지는 곳의 반복자를 리턴해준다..!

그렇다면 answer에는 itr - rate.begin() + 1을 하여 스테이지의 번호를 넣어주면 된다..!

+1을 하는 이유는 인덱스는 0부터 시작하기 때문이다..!

그리고 *itr = -111을 하여 해당 스테이지의 실패율을 가장 낮게 만들어준다..!

 
*/

//소수 만들기
//처음에 조합으로 접근함
#include <iostram>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> comb;
int n = nums.size();
int r = 3;


int solution(vector<int>nums){
    
    int answer = 0;
    int sum=0;

    if(comb.size()==r){
        for(int i=0; i<comb.size(); i++){
            sum+=comb[i];
        }
    }

    else{
        comb.push_back(k);
        combination(k+1);
        comb.pop_back();
        combination(k+1);
    }

    if(sum<2)
        return false;

    int num=(int)sqrt(sum);

    for(int i=2; i<= num; i++)
        if(sum %i=0)
            return false;
        answer++;


    return answer;
} 

//다시 생각한 풀이
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool check(int sum){
    for(int i=2; i<=sqrt(sum); i++){
        if((sum%i)==0)
            return false;
    }
    return true;
}

int solution(vector<int> nums){
    int answer=0;

    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                if(check(nums[i]+nums[j]+nums[k]))
                    answer++;
            }
        }
    }
    return answer;
}