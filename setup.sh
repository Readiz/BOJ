#!/bin/bash
if [ ! -d "node_modules" ]; then
  echo "node_modules folder not found. Running npm install..."
  npm install
fi
# 스크립트가 인자로 전달된 모든 값을 전달하여 node 명령어 실행
node . "$@"
cd ./boj/$@
