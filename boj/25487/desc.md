# 25487번 - 단순한 문제 (Large)


=========================

2.4 초

1024 MB

833

480

407

58.900%

문제
--

세 양의 정수 $a$, $b$, $c$가 주어질 때, 다음 조건을 만족하는 정수 쌍 $(x, y, z)$의 개수를 구하시오.

*   $1 \\le x \\le a$
*   $1 \\le y \\le b$
*   $1 \\le z \\le c$
*   $(x\\,\\bmod\\,y) = (y\\,\\bmod\\,z) = (z\\,\\bmod\\,x)$

$(A\\,\\bmod\\,B)$는 $A$를 $B$로 나눈 나머지를 의미한다.

입력
--

첫째 줄에 테스트 케이스의 수 $T$가 주어진다. $(1 \\le T \\le 600\\,000)$

다음 $T$개의 각 줄에는 세 정수 $a$, $b$, $c$가 공백으로 구분되어 주어진다. $(1 \\le a, b, c \\le 100\\,000)$

출력
--

한 줄에 하나씩 정답을 출력한다.

제한
--

예제 입력 1
-------

2
1 2 3
3 2 4

예제 출력 1
-------

1
2

힌트
--

출처
--

[Camp](/category/220) > [ICPC Sinchon Algorithm Camp](/category/499) > [2022 ICPC Sinchon Summer Algorithm Camp Contest](/category/798) > [중급](/category/detail/3172) A번

*   문제를 검수한 사람: [bnb2011](/user/bnb2011), [djs100201](/user/djs100201), [gumgood](/user/gumgood), [jthis](/user/jthis), [lky7674](/user/lky7674), [meque98](/user/meque98), [tony9402](/user/tony9402), [wonsei](/user/wonsei)
*   문제를 만든 사람: [tlsdydaud1](/user/tlsdydaud1)