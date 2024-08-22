#!/bin/bash

# 컴파일 단계
# 31614
g++ -std=c++17 solution/main.cpp -o main

# input 디렉토리의 모든 .txt 파일에 대해 루프
for input_file in input/*.txt; do
    # 파일 이름 추출 (경로 및 확장자 제외)
    filename=$(basename -- "$input_file")
    filename="${filename%.*}"

    # 해당하는 output 파일 경로
    output_file="output/${filename}.txt"

    # 프로그램 실행 및 출력 저장
    ./main < "$input_file" > "/tmp/temp_${filename}.txt"

    # diff 명령어로 결과 비교
    diff_result=$(diff -w "/tmp/temp_${filename}.txt" "$output_file")
    if [ $? -eq 0 ]; then
        echo "Test ${filename} Passed"
    else
        echo "Test ${filename} Failed"
        echo "----------------"
        echo "${filename} ANS"
        echo "----------------"
        cat $output_file
        echo ""
        echo "----------------"
        echo "${filename} YOURS"
        echo "----------------"
        cat "/tmp/temp_${filename}.txt"
        echo ""
        # echo "Differences"
        # echo "-----------------"
        # echo "$diff_result"
    fi

    # 임시 파일 삭제
    #rm "/tmp/temp_${filename}.txt"
done
