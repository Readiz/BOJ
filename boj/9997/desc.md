# 9997번 - 폰트


============

1 초

256 MB

2215

834

608

36.538%

문제
--

상근이는 자신이 만든 폰트를 테스트하기 위한 문장을 만들려고 한다. 폰트에는 알파벳 소문자만 포함되어 있기 때문에, 문장은 알파벳 소문자로 작성해야 한다.

테스트 문장에는 알파벳 소문자 26개가 모두 포함되어 있어야 한다.

사실 문제를 많이 풀어본 사람이라면, 문제를 여기까지 읽어도 무슨 문제인지 감이 잡혀야 한다.

상근이는 단어 N개가 포함되어 있는 사전을 하나 가지고 있다. 테스트 문장은 사전에 포함된 단어만 이용해서 만들 수 있으며, 각 단어는 한 번씩만 사용해야 한다. 또, 단어의 순서는 중요하지 않다. (“uvijek jedem sarmu” 와 “jedem sarmu uvijek”는 같은 문장이다)

상근이가 만들 수 있는 테스트 문장의 개수를 구하는 프로그램을 작성하시오.

입력
--

첫째 줄에 단어의 개수 N (1 ≤ N ≤ 25)가 주어진다. 다음 N개 줄에는 사전에 포함되어있는 단어가 주어진다. 단어의 길이는 100을 넘지 않으며, 중복되는 단어는 주어지지 않는다.

출력
--

상근이가 만들 수 있는 테스트 문장의 개수를 출력한다. 

제한
--

예제 입력 1
-------

9
the
quick
brown
fox
jumps
over
a
sleazy
dog

예제 출력 1
-------

2

예제 입력 2
-------

3
a
b
c

예제 출력 2
-------

0

예제 입력 3
-------

15
abcdefghijkl
bcdefghijklm
cdefghijklmn
defghijklmno
efghijklmnop
fghijklmnopq
ghijklmnopqr
hijklmnopqrs
ijklmnopqrst
jklmnopqrstu
klmnopqrstuv
lmnopqrstuvw
mnopqrstuvwx
nopqrstuvwxy
opqrstuvwxyz

예제 출력 3
-------

8189

힌트
--

출처
--

[Contest](/category/45) > [Croatian Open Competition in Informatics](/category/17) > [COCI 2013/2014](/category/272) > [Contest #6](/category/detail/1239) 2번

*   문제를 번역한 사람: [baekjoon](/user/baekjoon)
*   데이터를 추가한 사람: [kcm1700](/user/kcm1700)