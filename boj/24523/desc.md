# 24523번 - 내 뒤에 나와 다른 수


=======================

1 초

1024 MB

1770

705

573

42.954%

문제
--

길이가 $N$인 수열 $A\_1 \\ A\_2 \\ \\cdots \\ A\_N$이 주어진다. $1\\le i \\le N$인 정수 $i$마다 $i < j \\le N$이고 $A\_i \\ne A\_j$인 정수 $j$중 최솟값을 출력하라. 만약 이러한 $j$가 없다면 $-1$을 출력하라.

입력
--

첫째 줄에 수열 $A$의 크기 $N$이 주어진다. 둘째 줄에는 $A\_1 \\ A\_2 \\ \\cdots \\ A\_N$이 공백으로 구분되어 주어진다. $(1 \\le N \\le 10^6$, $-10^9 \\le A\_i \\le 10^9 )$

입력으로 주어지는 모든 수는 정수이다.

출력
--

각 $i$마다 조건을 만족하는 최솟값 $j$를 출력하라. 만약 이러한 $j$가 없다면 $-1$을 출력하라.

제한
--

예제 입력 1
-------

6
3 3 1 1 4 4

예제 출력 1
-------

3 3 5 5 -1 -1

힌트
--

출처
--

[University](/category/5) > [성균관대학교](/category/468) > [2022 성균관대학교 프로그래밍 경진대회](/category/detail/3031) A번

*   문제를 검수한 사람: [79brue](/user/79brue), [cs71107](/user/cs71107), [hibye1217](/user/hibye1217), [jh05013](/user/jh05013), [jhnah917](/user/jhnah917), [tony9402](/user/tony9402)
*   문제를 만든 사람: [Coxie](/user/Coxie)