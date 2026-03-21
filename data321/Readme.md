# 분수 ADT (Fraction Abstract Data Type)
## 1. 데이터 정의

분수(Fraction)는 **정수형 분자(numerator)** 와 **정수형 분모(denominator, ≠ 0)** 로 구성된 자료형이다.
Fraction = { num: 정수, den: 양의 정수 }
분모는 항상 양수로 유지되며, 음의 분수는 분자의 부호로 표현한다.
## 2. 연산 정의 (ADT)

## reduce
reduce : Fraction → Fraction
- 입력: 분수 f
- 출력: f를 기약분수로 변환한 결과
- 방법: GCD(|분자|, 분모)로 분자와 분모를 각각 나눔
- 조건: 분모 ≠ 0, 결과의 분모는 항상 양수

### frac_add
frac_add : (Fraction, Fraction) → Fraction
f1 + f2 = (f1.num × f2.den + f2.num × f1.den) / (f1.den × f2.den)
결과에 reduce 적용하여 기약분수로 반환

### frac_sub
frac_sub : (Fraction, Fraction) → Fraction
f1 - f2 = (f1.num × f2.den - f2.num × f1.den) / (f1.den × f2.den)
결과에 reduce 적용하여 기약분수로 반환

### frac_mul
frac_mul : (Fraction, Fraction) → Fraction
f1 × f2 = (f1.num × f2.num) / (f1.den × f2.den)
결과에 reduce 적용하여 기약분수로 반환

### frac_div
frac_div : (Fraction, Fraction) → Fraction
f1 ÷ f2 = (f1.num × f2.den) / (f1.den × f2.num)   (f2.num ≠ 0)
결과에 reduce 적용하여 기약분수로 반환

### str_to_frac
str_to_frac : String → Fraction
- 입력: "A/B" 형식의 문자열 (A, B는 정수)
- 출력: 해당 분수를 나타내는 Fraction
- 정수 "A"만 입력된 경우 A/1 로 처리

### print_frac
print_frac : Fraction → void
- Fraction을 "A/B" 형태로 표준 출력에 출력
- 분모가 1인 경우 "A"만 출력

## 3. 파일 구조
my_fraction.h   ← Fraction 타입 및 함수 선언
my_fraction.c   ← 함수 구현 (GCD 포함)
main.c          ← 메인 프로그램 (사칙연산 계산기)
