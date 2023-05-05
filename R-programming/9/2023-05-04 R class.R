# 모분산 구간추정 (예제 8-1)
data = c(226,228,226,225,232,228,227,229,225,230)

n = length(data)
var = var(data)

ha = (n-1)*var/qchisq(0.025,n-1)
up = (n-1)*var/qchisq(0.975,n-1)

# 내가 생각한거랑 상하가 반대로 나오네, 왜 그러지?
# 왜 왼쪽걸로 나눈게 상한이 되지?
# 교수님이 말씀해주신 식 만드는 과정에서, 역수 되니까 바뀌어서 그렇게 되네.
# 식적으로 봤을때, 그게 맞네여.

UCL = (n-1)*var/qchisq(0.025,n-1)
LCL = (n-1)*var/qchisq(0.975,n-1)

sqrt(UCL)
sqrt(LCL)

# 연습문제 11번, 모분산 95% 신뢰구간

n = 16
xbar = 3.5 # 사실 여기 답 구하는데는 필요없는 값!
var = 0.5

# q1 = qchisq(0.025,n-1)
# q2 = qchisq(0.975,n-1)

UCL = (n-1)*var/qchisq(0.025,n-1)
LCL = (n-1)*var/qchisq(0.975,n-1)

# 연습문제 12번 모평균(95%)과 모분산의 90% 신뢰구간 구하기

data = c(38.0,37.5,38.9,40.0,38.1,35.7,38.2,37.7,35.9,36.8,37.8)
n = 11
xbar = mean(data)
var = var(data)

# se = sqrt(var)/sqrt(n) # se는 표준편차/루트n이다!! 분산에다 하는거 xx 

mu_LCL = qt(0.025,n-1)*sqrt(var)/sqrt(n)+xbar
mu_UCL = qt(0.975,n-1)*sqrt(var)/sqrt(n)+xbar

# qt(0.025,n-1)과, qt(0.975,n-1)은 부호만 다르고 같으므로, 
#사실 하나만 계산하고 부호 붙여도 가능.

bun_LCL = var*(n-1)/qchisq(0.95,n-1)
bun_UCL = var*(n-1)/qchisq(0.05,n-1)

round(bun_LCL,digits=3)
round(bun_UCL,digits=3)

round(mu_LCL,digits=3)
round(mu_UCL,digits=3)

# 연습문제 5번
# 우리는 t에다가 해보래 그냥
n = 50
xbar = 173
s = 3 # 교수님은 std라고 이름 붙이시네
q2 = qt(0.975,n-1)
se = s / sqrt(n)
# error = q2*se
UCL = q2*se+xbar
LCL = (-q2)*se+xbar

round(UCL, digits=3)
round(LCL, digits=3)

q2_norm = qnorm(0.975) # 정규근사 버전
norm_UCL = q2_norm*se+xbar
norm_LCL = (-q2_norm)*se+xbar

round(norm_UCL, digits=3)
round(norm_LCL, digits=3)