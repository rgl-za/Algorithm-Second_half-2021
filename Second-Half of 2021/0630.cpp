#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int main() {
	int N, K, skip = 0, cnt = 0;
	cin >> N >> K;
	int arr[101];
	for (int k = 0; k < K; k++) cin >> arr[k];
	
	for (int i = 0; i < K; i++) {
		skip = 0;
		for (int j = 0; j < v.size(); j++) {
			if (arr[i] == v[j]) { //멀티탭에 꽂혀있는 제품일 경우
				skip = 1;
				break;
			}
		}
		if (!skip) {
			if (v.size() < N) v.push_back(arr[i]); //멀티탭을 다 안 채웠을 경우
			else { //플러그를 빼야하는 경우
				cnt++;
				int Max = 0, idx = 0, exit = 0;
				for (int k = 0; k < N; k++) {
					for (int j = i + 1; j < K; j++) {
						if (v[k] == arr[j]) {
							if (j > Max) { //가장 마지막에 쓰일 플러그를 저장한다
								Max = j;
								idx = k;
							}
							break;
						}
						else if (j == K - 1) { //쓰이지 않을 플러그가 있으면 그걸 뽑는다
							idx = k;
							exit = 1;
						}
					}
					if (exit) break;
				}
				v[idx] = arr[i];
			}
		}
	}
	cout << cnt;
	return 0;
}