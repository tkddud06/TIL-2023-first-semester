#예제 8-11번

data = c(226,228,226,225,232,228,227,229,225,230)
xbar = mean(data)
var = var(data)
n = 10

LCL = (n-1)*var/qchisq(0.975,n-1)
UCL = (n-1)*var/qchisq(0.025,n-1)

sqrt(LCL)
sqrt(UCL)

# 연습문제 12번
# 모평균 95퍼, 모분산 90퍼
data = c(38.0,37.5,38.9,40.0,38.1,35.7, 38.2, 37.7, 35.9, 36.8, 37.8)

n = length(data)
xbar = mean(data)
var = var(data)
se = sqrt(var)/sqrt(n) # 분산 / n이 아니라, 표본편차 / sqrt n

myu_LCL = xbar -qt(0.975,n-1)*se
myu_UCL = xbar + qt(0.975,n-1)*se # xbar 빼먹으면 안되지.

bun_LCL = (n-1)*var/qchisq(0.95,n-1)
bun_UCL = (n-1)*var/qchisq(0.05,n-1)

round(myu_LCL,3)
round(myu_UCL,3)

round(bun_LCL,3)
round(bun_UCL,3)

# 연습문제 9번

n = 100
phat = 0.2

se = sqrt(phat*(1-phat)/n) # sqrt 꼭 주의
error = qnorm(0.975)*se

LCL = phat-error
UCL = phat+error

round(LCL,3)
round(UCL,3)

# 연습문제 10번

n = 200
phat = 112/200
se = sqrt(phat*(1-phat)/n)
error = qnorm(0.95)*se

LCL = phat-error
UCL = phat+error

round(LCL,3)
round(UCL,3)

# 연습문제 13번
d = 20
sigma=100
z_inv = qnorm(0.975) # z_0.025=1.96

n =(z_inv*sigma)^2/d^2
# n이 96.03~~ 나오므로, 적어도 97개 필요하다는 소리.

# 연습문제 14번
d = 0.05
z_inv = qnorm(0.99)
n = z_inv^2/(4*d^2)
n

# 직접계산법은 아래와 같음.
(2.326^2)/(4*0.05^2)

# 연습문제 15번
# 신뢰구간 길이 == 상한에서 하한값을 뺸것