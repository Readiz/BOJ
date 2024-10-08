# 1799번 - 비숍


============

10 초

128 MB

29631

7430

5173

24.489%

문제
--

서양 장기인 체스에는 대각선 방향으로 움직일 수 있는 비숍(bishop)이 있다. < 그림 1 >과 같은 정사각형 체스판 위에 B라고 표시된 곳에 비숍이 있을 때 비숍은 대각선 방향으로 움직여 O로 표시된 칸에 있는 다른 말을 잡을 수 있다.

![](https://upload.acmicpc.net/c3f4ac55-3e37-4bed-a381-7d407b2f9b4f/-/preview/)

< 그림 1 >

그런데 체스판 위에는 비숍이 놓일 수 없는 곳이 있다. < 그림 2 >에서 체스판에 색칠된 부분은 비숍이 놓일 수 없다고 하자. 이와 같은 체스판에 서로가 서로를 잡을 수 없도록 하면서 비숍을 놓는다면 < 그림 3 >과 같이 최대 7개의 비숍을 놓을 수 있다. 색칠된 부분에는 비숍이 놓일 수 없지만 지나갈 수는 있다.

![](https://upload.acmicpc.net/3d44f5a2-bd28-41bd-9959-0f8f8bfbff3f/-/preview/)

< 그림 2 >

![](https://upload.acmicpc.net/49405f78-09c9-4220-8687-ec3269dd6c1b/-/preview/)

< 그림 3 >

정사각형 체스판의 한 변에 놓인 칸의 개수를 체스판의 크기라고 한다. 체스판의 크기와 체스판 각 칸에 비숍을 놓을 수 있는지 없는지에 대한 정보가 주어질 때, 서로가 서로를 잡을 수 없는 위치에 놓을 수 있는 비숍의 최대 개수를 구하는 프로그램을 작성하시오.

입력
--

첫째 줄에 체스판의 크기가 주어진다. 체스판의 크기는 10이하의 자연수이다. 둘째 줄부터 아래의 예와 같이 체스판의 각 칸에 비숍을 놓을 수 있는지 없는지에 대한 정보가 체스판 한 줄 단위로 한 줄씩 주어진다. 비숍을 놓을 수 있는 곳에는 1, 비숍을 놓을 수 없는 곳에는 0이 빈칸을 사이에 두고 주어진다.

출력
--

첫째 줄에 주어진 체스판 위에 놓을 수 있는 비숍의 최대 개수를 출력한다.

제한
--

예제 입력 1
-------

5
1 1 0 1 1
0 1 0 0 0
1 0 1 0 1
1 0 0 0 0
1 0 1 1 1

예제 출력 1
-------

7

힌트
--

출처
--

[Olympiad](/category/2) > [한국정보올림피아드](/category/55) > [한국정보올림피아드시․도지역본선](/category/57) > [지역본선 2007](/category/68) > [초등부](/category/detail/361) 5번

*   데이터를 추가한 사람: [altale](/user/altale), [phpmysql](/user/phpmysql)

채점 및 기타 정보
----------

*   이 문제의 채점 우선 순위는 2이다.