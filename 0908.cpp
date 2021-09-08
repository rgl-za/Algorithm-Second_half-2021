//행렬의 곱셈
//처음 시도한 풀이
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int sum;
    vector<int> temp;
    for(int i=0; i<arr1.size(); i++){
        for(int j=0; j<arr2.size(); j++){
           sum = 0;
           for(int k=0; k<arr1.size(); k++){
               sum += arr1[i][k] * arr2[k][j];
           }
           //answer[i][j].push_back(sum);
           //answer[i][j] = sum;
           temp.push_back(sum);
        }
        answer.push_back(temp);
    }

    return answer;
}

//최종
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int sum;
    
    for(int i=0; i<arr1.size(); i++){
        vector<int> temp;
        for(int j=0; j<arr2[0].size(); j++){
           sum = 0;
           for(int k=0; k<arr1[i].size(); k++){
               sum += arr1[i][k] * arr2[k][j];
           }
           //answer[i][j].push_back(sum);
           //answer[i][j] = sum;
           temp.push_back(sum);
        }
        answer.push_back(temp);
    }

    return answer;
}



//피보나치 수
//처음 시도한 풀이
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n){
    int answer=0;

    vector<int> nums(n+1);

    nums[0]=0;
    nums[1]=1;

    for(int i=2; i<=n; i++){
        nums[i]=nums[i-1]+nums[i-2];
    }

    for(int i=0; i<nums.size(); i++){
        answer=nums[i-1]+nums[i-2];
    }

    return answer;
}

// 최종
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n){
    int answer=0;

    vector<int> nums(n+1);

    nums[0]=0;
    nums[1]=1;

    for(int i=2; i<=n; i++){
        nums[i]=(nums[i-1]+nums[i-2])%1234567;
    }

    return nums[n];
}