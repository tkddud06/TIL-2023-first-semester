# 모평균 구간추정 ~ 모분산 =3.1 표본평균 xbar, 표준오차 se // 표본평균의 분포가 졍규분포인 경우

# 예제 8-6

x = c(89.6,88.8,86.3,82.6,84.7,85.8,80.5,84.3,91.3,86.7,87.6,85.2,78.5,85.3,81.5,83.9,86.9,82.0,83.0,85.5)

sigma = 1.76 # 모표준편차

xbar = mean(x) # 표본평균

n=length(x) # 자료 길이

se = sigma/sqrt(n) # 표준오차

xbar

se

# 모표준편차를 알고 있으니, 정규분포에 적용해서 계산

cl= qnorm(0.995)*se # 100(1-alpha)% 오차한계, 99%계산하라했으니 0.995에
cl

LCL=xbar-cl #하한
UCL=xbar+cl #상한
# 저 상한과 하한의 사이가 99% 신뢰구간.
round(LCL, digits=3) # 반올림 함수
round(UCL, digits=3)

# 모평균 구간추정 = 표본평균 xbar, 표준오차추정량 se // 표본평균의 분포가 t분포인 경우/ 정규모집단 가정

x = c(89.6,88.8,86.3,82.6,84.7,85.8,80.5,84.3,91.3,86.7,87.6,85.2,78.5,85.3,81.5,83.9,86.9,82.0,83.0,85.5)

# 이거 아님! s = 1.76

xbar = mean(x)

n = lenghth(x)

se = sd(x)/sqrt(n) # 표본오차 추정량

xbar

se

cl = qt(0.995,n-1)*se
cl

LCL=xbar-cl
UCL=xbar+cl

round(LCL, digits=3) # 반올림 함수
round(UCL, digits=3)

# 보다시피, 추정된 분산을 사용하다보니, 신뢰구간의 범위가 더 넓어짐.
# t분포는 분산이 더 크다.



# 예제 8-7
# 이 문제에서, "단," 이 나타내는 말은 모집단에 대한 얘기임.
# 이 모집단이 정규분포가 아니라면, t분포나 정규분포에 적용이 불가함. (소표본이니까)

# 허나, 예제 8-8의 경우에는 안 적혀있는 이유가, 대표본이기 때문에, 중심극한정리를 쓰면 되니까.




# 예제 8-8
# t로도 풀어도 되고, 그냥 정규분포에 풀어도 됨. n이 충분히 크니까.(대표본)
# 다만 t가 더 정확할거고, 컴으로 할땐 t에 맞춰 하면 됨.

n = 64
xbar = 3.2
sd = sqrt(1.44) # 1.2

se = sd / sqrt(n)

LCL_n=xbar-qnorm(0.99)*se
UCL_n=xbar+qnorm(0.99)*se

LCL_t=xbar-qt(0.99,n-1)*se
UCL_t=xbar+qt(0.99,n-1)*se

round(LCL_n,digit=3)
round(UCL_n,digit=3)
round(LCL_t,digit=3)
round(UCL_t,digit=3)

# 예제 8-5

n = 3000
x = 1578

phat = x/n

phat

se_phat = sqrt(phat *(1-phat)/n)

cl = qnorm(0.975)*se_phat

LCL = phat - cl
UCL = phat + cl

round(LCL,digit=3)
round(UCL,digit=3) # 책이랑 뭐가 같다는거야....?

# 연습문제 2번. 95% 구간추정도 할 것.

x = c(35, 19, 40, 35, 51, 41, 27, 23, 39, 21, 41, 31, 46, 51, 34, 37, 36, 55, 52, 32)

xbar = mean(x)
xbar

se = sd(x)/ sqrt(length(x))

cl = se*qnorm(0.975)

LCL = xbar - cl
UCL = xbar + cl

round(LCL, digit=3)
round(UCL, digit=3)

# 연습문제 3번.

n = 2000
x = 165

phat = x/n

se_phat = phat*(phat-1)/n #phat 표준오차 왜 이렇게 생겼는지 알아보기.

cl = se+phat*qnorm(0.975)

UCL = phat + cl
LCL = phat - cl

round(LCL, digit=3)
round(UCL, digit=3)