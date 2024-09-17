# 27065번 - 2022년이 아름다웠던 이유


==========================

1 초

1024 MB

775

472

428

66.563%

문제
--

Good Bye, BOJ 2022! 대회는 2022년의 끝을 기념하는 알고리즘 문제해결 대회이다. [leejseo](/user/leejseo)라는 핸들을 사용하는 [종서](https://leejseo.com)는 자신의 22번째 생일인 2022년 12월 31일에 Good Bye, BOJ 2022!를 개최하기로 결심했다.

정휘는 Good Bye, BOJ 2022!가 개최된다는 소식에 기뻐 제목을 뚫어져라 보다가, 2022가 정말 아름다운 수라는 사실을 깨달았다.

자기 자신을 제외한 약수들의 합이 자기 자신보다 작은 수를 부족수, 자기 자신보다 큰 수를 과잉수, 자기 자신과 같은 수를 완전수라고 하자.

그러면 2022는 과잉수이면서 2022의 자기 자신을 제외한 모든 약수는 모두 부족수이거나 완전수이다. 과잉과 부족의 조화라니, 이 얼마나 아름다운 수인가! 다음에 이런 년도가 오려면 2044년이 되어야 한다.

양의 정수 $n$이 주어진다. $n$이 과잉수이면서 $n$을 제외한 $n$의 모든 약수가 부족수이거나 완전수인지 판별하는 프로그램을 작성하여라.

입력
--

첫째 줄에 테스트 케이스의 개수 $T$가 주어진다.

이후 $T$개의 줄에 걸쳐 테스트 케이스가 한 줄에 하나씩 주어진다. 각 테스트 케이스는 한 줄로 구성되며, 각각 한 개의 양의 정수 $n$이 주어진다.

출력
--

각 테스트 케이스에 대해, $n$이 과잉수이면서 $n$을 제외한 $n$의 모든 약수가 부족수이거나 완전수라면 `Good Bye`, 그렇지 않다면 `BOJ 2022`를 한 줄에 하나씩 차례로 출력하여라.

제한
--

*   $1 \\le T \\le 500$
*   $1 \\le n \\le 5\\,000$

예제 입력 1
-------

3
2022
2023
2044

예제 출력 1
-------

Good Bye
BOJ 2022
Good Bye

힌트
--

출처
--

[Contest](/category/45) > [BOJ User Contest](/category/984) > [Good Bye, BOJ](/category/469) > [Good Bye, BOJ 2022!](/category/detail/3426) A번

*   문제를 검수한 사람: [cgiosy](/user/cgiosy), [chansol](/user/chansol), [edenooo](/user/edenooo), [gustjwkd1007](/user/gustjwkd1007), [hibye1217](/user/hibye1217), [junseo](/user/junseo), [kyo20111](/user/kyo20111), [leejseo](/user/leejseo), [man\_of\_learning](/user/man_of_learning), [ryute](/user/ryute), [stonejjun03](/user/stonejjun03)
*   문제를 만든 사람: [jhnah917](/user/jhnah917)