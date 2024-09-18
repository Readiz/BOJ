from decimal import Decimal, getcontext
import random
import math

# 소수점 아래 230자리로 정밀도 설정 (여유분 포함)
getcontext().prec = 230

# 정삼각형의 세 꼭짓점 정의
A = (Decimal('0'), Decimal('0'))
B = (Decimal('1'), Decimal('0'))
sqrt3_over_2 = Decimal(3).sqrt() / Decimal('2')
C = (Decimal('0.5'), sqrt3_over_2)

def generate_point(triangle, depth):
    """
    시에르핀스키 삼각형 내에서 균등하게 점을 생성하는 함수.
    재귀적으로 삼각형을 분할하여 점을 선택함.
    
    Parameters:
        triangle: 현재 삼각형의 꼭짓점 좌표 [(x1, y1), (x2, y2), (x3, y3)]
        depth: 분할 깊이
    
    Returns:
        (x, y): 생성된 점의 좌표
    """
    if depth == 0:
        # 깊이가 0이면 현재 삼각형의 무게 중심을 반환
        x = (triangle[0][0] + triangle[1][0] + triangle[2][0]) / Decimal('3')
        y = (triangle[0][1] + triangle[1][1] + triangle[2][1]) / Decimal('3')
        return (x, y)
    else:
        # 세 개의 중간 삼각형으로 분할
        mid_AB = ((triangle[0][0] + triangle[1][0]) / 2, (triangle[0][1] + triangle[1][1]) / 2)
        mid_AC = ((triangle[0][0] + triangle[2][0]) / 2, (triangle[0][1] + triangle[2][1]) / 2)
        mid_BC = ((triangle[1][0] + triangle[2][0]) / 2, (triangle[1][1] + triangle[2][1]) / 2)
        
        # 세 개의 작은 삼각형 중 하나를 랜덤하게 선택
        choice = random.randint(1, 3)
        if choice == 1:
            new_triangle = [triangle[0], mid_AB, mid_AC]
        elif choice == 2:
            new_triangle = [mid_AB, triangle[1], mid_BC]
        else:
            new_triangle = [mid_AC, mid_BC, triangle[2]]
        
        return generate_point(new_triangle, depth - 1)

def decimal_sqrt(value):
    """
    Decimal 객체의 제곱근을 계산하는 함수.
    
    Parameters:
        value: Decimal 객체
    
    Returns:
        Decimal 객체의 제곱근
    """
    return value.sqrt()

def compute_distance(p1, p2):
    """
    두 점 사이의 거리를 계산하는 함수.
    
    Parameters:
        p1, p2: 두 점의 좌표 [(x1, y1), (x2, y2)]
    
    Returns:
        Decimal 형태의 거리
    """
    dx = p1[0] - p2[0]
    dy = p1[1] - p2[1]
    distance_squared = dx * dx + dy * dy
    return decimal_sqrt(distance_squared)

def simulate_jiae_constant(trials, depth):
    """
    지애 상수를 시뮬레이션하는 함수.
    
    Parameters:
        trials: 시뮬레이션할 시행 횟수
        depth: 시에르핀스키 삼각형 생성 시 재귀 깊이
    
    Returns:
        Decimal 형태의 지애 상수
    """
    total_distance = Decimal('0')
    
    for _ in range(trials):
        # 두 점 P와 Q를 생성
        P = generate_point([A, B, C], depth)
        Q = generate_point([A, B, C], depth)
        
        # 두 점 사이의 거리 계산
        distance = compute_distance(P, Q)
        # 거리 합산
        total_distance += distance
    
    # 평균 거리 계산
    average_distance = total_distance / Decimal(trials)
    return average_distance
import os

def load_state():
    if os.path.exists("state.txt"):
        with open("state.txt", "r") as f:
            current_file = f.readline().strip()
            count = int(f.readline().strip())
        return current_file, count
    else:
        return "results_1.txt", 0

def save_state(current_file, count):
    with open("state.txt", "w") as f:
        f.write(f"{current_file}\n")
        f.write(f"{count}\n")

def write_to_file(filename, count, jiae_constant):
    # 파일이 없으면 새로운 파일 생성
    if not os.path.exists(filename):
        with open(filename, "w") as f:
            f.write("0\n")  # 첫 줄에 저장된 갯수 기록
    # 파일에 값 추가
    with open(filename, "a") as f:
        f.write(f"{jiae_constant}\n")
    # 파일의 첫 줄(저장된 갯수) 업데이트
    lines = open(filename).readlines()
    lines[0] = f"{count}\n"
    with open(filename, "w") as f:
        f.writelines(lines)

def main():
    # 상태 파일에서 현재 파일과 저장된 갯수 불러오기
    current_file, count = load_state()
    trials = 10000
    depth = 100
    
    mcnt = 0
    msum = 0
    while True:
        jiae_constant = simulate_jiae_constant(trials, depth)
        msum += jiae_constant
        mcnt += 1
        print(msum / mcnt)
        
        # 값 저장
        count += 1
        write_to_file(current_file, count, jiae_constant)
        
        # 만약 10,000개를 넘었으면 새로운 파일로 변경
        if count >= 10000:
            file_num = int(current_file.split('_')[1].split('.')[0]) + 1
            current_file = f"results_{file_num}.txt"
            count = 0
        
        # 상태 저장
        save_state(current_file, count)

if __name__ == "__main__":
    main()

# 0.4227021810348385578571