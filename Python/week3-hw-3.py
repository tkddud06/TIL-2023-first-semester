num = 0

num = int(input(" *** 숫자를 입력하세요 : "))
# 너무 자세한 프로그램 작성이 요구되는 건 아닌것 같아, num의 입력 범위는 무조건 1 이상의 자연수라고 가정했습니다.
if num == 1:
    print("%d는 소수가 아닙니다." % num)
    exit(0)

for i in range(2,num):
    if num % i == 0:
        print("%d는 소수가 아닙니다." % num)
        exit(0)
print("%d는 소수입니다." % num)