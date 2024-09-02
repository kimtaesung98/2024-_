#include<stdio.h>
#include<cmath> // sqrt 함수를 사용하기 위해 추가

bool isprime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; i++) { // 제곱근 이하로 검사
        if (num % i == 0) return false;
    }
    return true;
}

bool* prime(int n) {
    bool* p = new bool[n]; // 입력 범위에 따라 배열 크기 조정
    for (int i = 1; i <= n; i += 2) {
        p[i] = false;
    }
    p[2] = true;
    for (int i = 3; i < n; i += 2) { // 홀수만 검사
        p[i] = (isprime(i)) ? true : false;
    }
    return p;
}

int main() {
    bool* p = prime(1000000); // 입력 범위 축소
    int n;
    while (1) {
        scanf_s("%d", &n);
        if (n == 0) break;
        bool a = false;
        for (int i = 3; i <= n; i += 2) {
            if ((p[i] && p[n - i])) {
                a = true;
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }
        if (!a) printf("Goldbach's conjecture is wrong.\n");
    }
    delete[] p;
}