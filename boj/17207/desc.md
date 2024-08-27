# 17207번 - 돌려막기


===============

0.1 초

256 MB

349

232

210

67.742%

문제
--

인서와 준석 그리고 정우, 진우 마지막으로 영기는 대회를 준비하느라 정신이 없다. 그러던 어느 날 급하게 처리해야 할 일이 생기고 말았다. 피자를 숟가락으로 떠먹는 등의 일로 바빴던 5명은 서로에게 일을 떠넘기기에 급급했다. 그러던 어느 날 더 이상 일을 미룰 수 없다고 판단한 다섯은 일처리를 누가 맡을지 이야기하여, 아래와 같은 자신들의 계산법을 바탕으로 최종 일량을 계산해 가장 일이 바쁘지 않은 사람에게 일처리를 맡기기로 하였다.

1.  5개의 일이 존재한다.
2.  인서는 1번, 준석이는 2번, 정우는 3번, 진우는 4번, 영기는 5번으로 각자에게 번호를 부여한다.
3.  행렬 A는 인서, 준석, 정우, 진우, 영기가 예상하는 각 일의 난이도를 **각 행**에 일의 순서대로 나열한 5×5의 행렬이다. 즉, x행 y열의 값은 x번 사람이 예상한 y번째 일의 난이도이다. 예를 들어 **2행 1열**의 값은 2번인 준석이가 예상한 1번째 일의 난이도, **5행 2열**의 값은 5번인 영기가 예상한 2번째 일의 난이도이다.
4.  행렬 B는 인서, 준석, 정우, 진우, 영기가 예상한 각 일의 처리시간을 **각 행**에 일의 순서대로 나열한 5×5의 행렬이다. 즉, x행 y열의 값은 x번 사람이 예상한 y번째 일의 처리시간이다. 예를 들어 **2행 1열**의 값은 2번인 준석이가 예상한 1번째 일의 처리시간, **5행 2열**의 값은 5번인 영기가 예상한 2번째 일의 처리시간이다.
5.  x번 사람의 y번째 일의 예상 일량은 아래와 같다.  
    $\\left(x\\text{번 사람의 }y\\text{번째 일의 예상 일량}\\right) = \\sum\_{i=1}^5 \\left(\\left(x\\text{번 사람이 예상한 }i\\text{번째 일의 난이도}\\right) \\times \\left(i\\text{번 사람이 예상한 }y\\text{번째 일의 처리시간}\\right)\\right)$
6.  각자의 최종 일량은 1번째 일부터 5번째 일까지 그 사람의 예상 일량을 모두 합한 값이다.
7.  최종 일량이 가장 작은 사람이 가장 일이 바쁘지 않은 사람이다.

이 계산법으로 작동하는 프로그램을 구현하여 가장 일이 바쁘지 않은 사람을 구하여라.

입력
--

5×5 행렬 _A_의 값 _a1 ~ a25_가 5줄에 걸쳐 순서대로 주어지며, 이후 5×5 행렬 _B_의 값 _b1 ~ b25_가 5줄에 걸쳐 순서대로 주어진다. 단, _ai_는 1보다 크거나 같고 1000보다 작거나 같은 정수이며, _bi_는 1보다 크거나 같고 100보다 작거나 같은 정수이다.

출력
--

가장 일이 바쁘지 않은 사람의 이름(Inseo, Junsuk, Jungwoo, Jinwoo, Youngki)을 출력한다. 만약, 가장 일이 바쁘지 않은 사람이 둘 이상일 경우 Youngki, Jinwoo, Jungwoo, Junsuk, Inseo 순서로 가장 앞서는 사람의 이름을 출력한다.

제한
--

예제 입력 1
-------

40 50 20 70 10
80 20 20 20 50
50 20 10 30 60
90 10 30 20 40
10 30 60 10 70
10 30 20 20 20
50 10 10 10 10
30 10 10 10 40
60 10 10 10 10
10 20 40 10 10

예제 출력 1
-------

Jungwoo

인서의 최종 일량은 18400, 준석이의 최종 일량은 18300, 정우의 최종 일량은 16200, 진우의 최종 일량은 18500, 영기의 최종 일량은 17000이다.

예제 입력 2
-------

40 50 20 70 10
80 20 20 20 50
50 20 10 30 60
90 10 30 20 40
50 20 10 30 60
10 30 20 20 20
50 10 10 10 10
30 10 10 10 40
60 10 10 10 10
10 20 40 10 10

예제 출력 2
-------

Youngki

인서의 최종 일량은 18400, 준석이의 최종 일량은 18300, 정우의 최종 일량은 16200, 진우의 최종 일량은 18500, 영기의 최종 일량은 16200이다.

힌트
--

![행렬사진](https://upload.acmicpc.net/c8397d59-2e79-4c5a-a902-6f58ea2cbd8a/)

위의 그림과 같이 행렬에서 행은 가로줄, 열은 세로줄을 의미한다.

출처
--

[University](/category/5) > [중앙대학교](/category/400) > [2019 NPC (Newbie Programming Contest)](/category/detail/2030) G번

*   문제를 만든 사람: [junsuk0522](/user/junsuk0522)