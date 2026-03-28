## GCD의 시간복잡도와 Big-O계산
# GCD의 시간 복잡도를 실행 횟수로 직접 나타내면 

'''
int gcd(int a, int b) {
    if (a < 0) a = -a;    1회
    if (b < 0) b = -b;    1회
    while (b != 0) {      n+1회  
        int temp = b;     n회
        b = a % b;        n회
        a = temp;         n회
    }
    return a;             1회
}
'''

# 이므로 다 더하면 4n+4 입니다
# Big-O 표시법으로 나타내면 O(log min(a, b)) 입니다.
