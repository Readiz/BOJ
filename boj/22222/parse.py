from decimal import Decimal, getcontext, ROUND_HALF_UP
getcontext().prec = 300
getcontext().rounding = ROUND_HALF_UP

with open('results.txt', 'r') as file:
    numbers = []
    
    # 파일에서 줄별로 숫자 읽기
    for line in file:
        try:
            number = Decimal(line.strip())
            numbers.append(number)
        except ValueError:
            # 숫자가 아닌 줄은 무시
            pass

# 숫자 개수 확인
count = len(numbers)
print(count)
# 평균 계산
if count > 0:
    average = sum(numbers) / count
    print(f"숫자들의 평균: \n{average}")
else:
    print("파일에 숫자가 없습니다.")
    
    
# 22자리
# 0.4227021810348385578571
# 0.422936636209503108673940943540856828078771567749786373021347225537970443251118511067710289328473067320393160359383683079802559954619997514500890055066589525191201535264638493378231544333331453244618562193094871574566810139248485377292170060751515642896342168717475300243652262611291488104692005775139