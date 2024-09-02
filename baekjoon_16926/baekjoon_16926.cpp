#include <iostream>
#include <vector>
using namespace std;

vector<int> rotate(vector<int> vec, int r) {
	for (int i = 0; i < r; i++) {
		vec.push_back(vec[i]);
	}
	return vec;
}
vector<int> onion(int** arr, int c_s, int c_e, int r_s, int r_e,int r) {
	vector<int> vec;	int i;
	for (i = r_s; i <= r_e; i++)vec.push_back(arr[c_s][i]);
	for (i = c_s + 1; i <= c_e - 1; i++)vec.push_back(arr[i][r_e]);
	for (i = r_e; i >= r_s; i--)vec.push_back(arr[c_e][i]);
	for (i = c_e - 1; i >= c_s + 1; i--)vec.push_back(arr[i][r_s]);
	return rotate(vec,r);
}
void reverse_onion(vector<int> vec, int** arr, int c_s, int c_e, int r_s, int r_e,int r) {
	int i, j = r;
	for (i = r_s; i <= r_e; i++)arr[c_s][i] = vec[j++];
	for (i = c_s + 1; i <= c_e - 1; i++)arr[i][r_e] = vec[j++];
	for (i = r_e; i >= r_s; i--)arr[c_e][i] = vec[j++];
	for (i = c_e - 1; i >= c_s + 1; i--)arr[i][r_s] = vec[j++];
}
int main() {
	int n, m, r; scanf_s("%d %d %d", &n, &m, &r);
	int mod = (m > n)?n : m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}

	int c_s = 0, r_s = 0, c_e = n - 1, r_e = m - 1;
	for (int i = 0; i < mod / 2; i++) {
		reverse_onion(onion(arr, c_s, c_e, r_s, r_e, r), arr, c_s, c_e, r_s, r_e, r);
		++c_s, ++r_s, --c_e, --r_e;
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
	//printf("\n");
	}
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}