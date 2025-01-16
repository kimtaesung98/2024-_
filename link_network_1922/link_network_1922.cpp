#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int* parent;
int* union_find;
int find(int a) {
	
}
class line {
public:
	int x, y, weight;
	line(int a, int b,int c) :x(a), y(b), weight(c){}
};
int main() {
	int n, m,a,b,c;
	vector<line> l;
	scanf_s("%d %d",&n,&m);
	l = new vector<line>[m];
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d %d", &a, &b, &c);
		l[i] = line(a, b, c);
	}
}