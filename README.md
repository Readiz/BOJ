# BOJ

어떤 환경에서도 커맨드라인만 있다면 문제를 풀 수 있다!

wsl2 환경에서 테스트 되었습니다.


### Setup

Google chrome install

```bash
cd /tmp
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo apt install --fix-missing ./google-chrome-stable_current_amd64.deb
```

Font setup
```bash
sudo apt-get install fonts-nanum
sudo fc-cache -fv
```

To use xwindow (wsl2)
```bash
sudo apt-get install xvfb
sudo apt install libgtk-3-dev libnotify-dev libgconf-2-4 libnss3 libxss1 libasound2
```

```bash
chmod +x ./get
. ./get 문제번호
```


## TODO
- [ ] TC별 소요시간 보여주기
- [ ] TC별 디버깅 가능하게 해보기 (gdbserver)
- [ ] O2 옵션으로 컴파일하기 (cpp)
- [ ] Random TC Generator 기능 추가해보기
