import sys
import decimal
input = lambda: sys.stdin.readline().rstrip()

decimal.getcontext().prec = 1000000


def calculate_power(a_str, b_str):
    a = decimal.Decimal(a_str)
    b = int(b_str)
    result = a ** b

    return f"{result:.1000000f}".rstrip('0').rstrip('.')


a,b=input().split()
print(calculate_power(a,b))
