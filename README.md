# Setup

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
chmod +x ./setup.sh
./setup.sh 문제번호
```
