// /******************************************************************************

//                               Online C++ Compiler.
//                Code, Compile, Run and Debug C++ program online.
// Write your code in this editor and press "Run" button to compile and execute it.

// *******************************************************************************/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int N, pick, students[101];
    
//     cin >> N >> pick;
    
//     vector<int>display(N);
    
//     for(int i=1; i<=pick; i++){
//         int recommend;
//         cin >> recommend;
//         students[recommend]++;
//         for(int j=0; j<display.size(); j++){
//             if(students[i]!=0){
//                 display.push_back(students[i]);
//                 if(display.size()<pick){
//                     int min = *min_element(display.begin(), display.end());
//                     display.erase(display()+min);
//                     students[recommend] = 0;
//                     display.insert(min, students[i]);
//                 }
                
//             }
//         }
//         sort(students.begin(), students.end());
        
//         for(int i=0; i<display.size(); i++)
//             cout << display[i];
//     }
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int rcm[110] = {0, }; // 추천수 배열
// int dur[110] = {0, }; // 게시 기간 배열
	
// bool comp(const int o1, const int o2){
// 	if(rcm[o1] == rcm[o2]){
// 		if(dur[o1] < dur[o2]){
// 			return true;
// 		}
// 		else{
// 			return false;
// 		}
// 	}
// 	else if(rcm[o1] > rcm[o2]){
// 		return true;
// 	}
// 	else{
// 		return false;
// 	}
// }

// int main() {
// 	int n, c;
// 	vector<int> photo; // 사진틀
	
// 	scanf("%d %d", &n, &c);
	
// 	for(int i = 0; i < c; i++){
// 		int x;
// 		scanf("%d ", &x); // 후보 입력
		
// 		rcm[x]++;
		
// 		for(int j = 0; j < photo.size(); j++){
// 			dur[photo[j]]++; // 후보 입력마다 사진틀에 게시된 후보 기간 증가
// 		}
		
// 		bool exist = false;
		
// 		for(int j = 0; j < photo.size(); j++){
// 			if(photo[j] == x){
// 				exist = true;
// 				break;
// 			}
// 		}
		
// 		if(!exist){
// 			if(photo.size() < n){
// 				photo.push_back(x);
// 			}else{
// 				sort(photo.begin(), photo.end(), comp);
//                 		// 재정의한 정렬 기준에 따라 사진틀 정렬
// 				rcm[photo.back()] = 0;
// 				dur[photo.back()] = 0;
// 				photo.back() = x;
// 			}
// 		}
		
// 	}
	
// 	sort(photo.begin(), photo.end()); // 후보 오름차순 정렬
	
// 	for(int i = 0; i < photo.size(); i++){
// 		printf("%d ", photo[i]);
// 	}
	
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 101

int n, m;
int recommend[MAX];


int main(){
	

	cin >> n >> m;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		recommend[num]++;

		bool replace = true;
		for (int j = 0; j < n; j++)
		{
			if (v[j].second == 0)
			{
				v[j].second = num;
				v[j].first = i;
				replace = false;
				break;
			}

			else if (v[j].second == num)
			{
				replace = false;
				break;
			}
		}

		if (replace)
		{
			int idx = 0;
			for (int j = 1; j < n; j++)
			{
				if (recommend[v[j].second] == recommend[v[idx].second])
				{
					if (v[j].first < v[idx].first)
					{
						idx = j;
					}
				}
				else if (recommend[v[j].second] < recommend[v[idx].second])
				{
					idx = j;
				}
			}
			recommend[v[idx].second] = 0;
			v[idx].first = i;
			v[idx].second = num;
		}
	}

	vector<int> picture;
	for (int i = 0; i < n; i++)
	{
		picture.push_back(v[i].second);
	}

	sort(picture.begin(), picture.end());
	for (int i = 0; i < n; i++)
	{
		if (picture[i] == 0)
			continue;
		cout << picture[i] << " ";
	}
	return 0;
}