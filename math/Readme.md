# GCD / LCM
## GCD (최대공약수)

### 원리
두 정수 a, b에 대해 `GCD(a, b) = GCD(b, a % b)` 가 성립하며,
`b = 0` 이 되면 `a` 가 최대공약수이다.

### Pseudo 코드
function GCD(a, b):
    while b ≠ 0:
        temp ← b
        b    ← a mod b
        a    ← temp
    return a

## LCM (최소공배수)

### 원리
LCM(a, b) = |a × b| / GCD(a, b)
오버플로우 방지를 위해 먼저 나눈 뒤 곱한다.
LCM(a, b) = |a / GCD(a, b)| × b

### Pseudo 코드
function LCM(a, b):
    if a = 0 or b = 0:
        return 0
    return |a / GCD(a, b) * b|

## 파일 구조
my_math.h        ← gcd, lcm 함수 선언
my_math.c        ← gcd, lcm 함수 구현
main.c           ← 메인 프로그램
