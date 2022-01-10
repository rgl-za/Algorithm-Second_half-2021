// 20436
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
   // 왼손의 키보드
   char s_l[] = { 'q','w','e','r','t',
                    'a','s','d','f','g',
                    'z','x','c','v' };
   int s_l_p[][2] = { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, 
                        {1,0}, {1,1}, {1,2}, {1,3}, {1,4}, 
                        {2,0}, {2,1}, {2,2}, {2,3} };

   // 오른손의 키보드
   char s_r[] = { 'y','u','i','o','p',
                    'h','j','k','l',
                    'b','n','m', };
   int s_r_p[][2] = { {0,1}, {0,2}, {0,3}, {0,4}, {0,5},
                        {1,1}, {1,2}, {1,3}, {1,4},
                        {2,0}, {2,1}, {2,2} };

   char l, r;
   string str;
   int l_postion[2] = { 0 }; // 시작위치
   int r_postion[2] = { 0 };

   cin >> l >> r;
   cin >> str;

   // 오른손과 왼손의 시작 위치 저장
   for (int i = 0; i < 14; i++) {
      if (l == s_l[i]) {
         l_postion[0] = s_l_p[i][0];
         l_postion[1] = s_l_p[i][1];
      }
      if (i < 12) {
         if (r == s_r[i]) {
            r_postion[0] = s_r_p[i][0];
            r_postion[1] = s_r_p[i][1];
         }
      }
   }
   
   int time = 0;

   // 입력받은 문자열에 따라 이동하는 시간과 누르는 시간을 저장
   for (int i = 0; i < str.length(); i++) {
      for (int j = 0; j < 14; j++) {
         if (str[i] == s_l[j]) {
            time += abs(l_postion[0] - s_l_p[j][0]) + abs(l_postion[1] - s_l_p[j][1]) + 1;
            l_postion[0] = s_l_p[j][0];
            l_postion[1] = s_l_p[j][1];
         }
         if (j < 12) {
            if (str[i] == s_r[j]) {
               time += abs(r_postion[0] - s_r_p[j][0]) + abs(r_postion[1] - s_r_p[j][1]) + 1;
               r_postion[0] = s_r_p[j][0];
               r_postion[1] = s_r_p[j][1];
            }
         }
      }
   }

   cout << time << "\n";

   return 0;
}


// 2606
#include <iostream>
using namespace std;
 
int v, e;
const int MAX = 101;
int V[MAX][MAX] = { 0, };
bool checked[MAX] = { 0, };
int count = 0;
 
void DFS(int x) {
    checked[x] = true;
    count++;
 
    for (int i = 1; i <= v; i++) {
        if (checked[i] == 0 && V[x][i] == 1) {
            DFS(i);
        }
    }
}
 
int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int n, m;
        cin >> n >> m;
        V[n][m] = 1;
        V[m][n] = 1;
    }
 
    DFS(1);
    
    cout << count - 1;
}


// 22864
#include <iostream>
using namespace std;

int main(){

    int A, B, C, M;
    int fatigue = 0, time = 0, work = 0, rest = 0, burnout = 0;

    cin >> A >> B >> C >> M;

    rest = C;
    burnout = M;

    if(A > M){
        cout << 0 << endl;
        exit(0);
    }
        while(1){
            fatigue +=A;
            if(fatigue>burnout){
                fatigue -=A;
                fatigue -= rest;
                if(fatigue<0){
                    fatigue = 0;
                }
            }
            else{
                work += B;
            }
            time++;

            if(time == 24){
                cout << work << endl;
                break;
            }
        }

    return 0;
}


// 2164
#include <iostream>
#include <queue>
using namespace std;

int main(){

    int n;
    queue<int>q;

    cin >> n;

    for(int i=1; i<=n; i++){
        q.push(i);
    }

    while(q.size() > 1){
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << endl;

    return 0;
}