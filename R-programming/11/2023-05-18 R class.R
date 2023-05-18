# 예제 10-1

x = c(105,108,86,103,104,107,124,105)

y = c(89,92,84,97,103,107,111,97,101,106)

x
y

n1 = length(x)

n2 = length(y)

n1
n2

F0 = var(x)/var(y) # s1^2 / s2^2이 된 셈.
F0

falpha = qf(0.95,n1-1,n2-1) # 임계치 찾기. 책기준으로 보면, a 0.05 찾은 셈
falpha

pval = 1-pf(F0, n1-1, n2-1) # p-value 구하기. 배운걸로 치면, 2번째 방법. 검정추정량말고.
pval
# 보다시피 , a보다 크다. 오류범할확률 허용해준것보다 크므로, 귀무가설 기각 못하는것.

round(c(F=F0, CV=falpha, p_value = pval),4)



### var.test == 등분산 검정 함수 이름


# 뜨는거. F, x자유도, y자유도, p-value, alter~~ : 대립 가설,
# 95% 신뢰구간, 그 안에 밑에 뜨는 F가 포함되어있는지 확인하면됨.
# 혹은 p-value가 신뢰구간보다 작거나 크거나 확인
# sample estimates : 추정된 표본에서 구한 분산비
var.test(x,y)
# 기본은 양측, 따로 적어주면 단측 가능. 기본 95%임
var.test(x,y,alt="greater",conf.level=0.95) # alt= 대립가설

#예제 10-7에서 검정은 단측으로, 신뢰구간은 양측으로 하고싶다.
# 그러면 

var.test(x,y,alt="greater",conf.level=0.90) # 하고, 
#( 유의수준 5%이므로 근데 왜 5%인데 90으로 두는거지?)
var.test(x,y,conf.level=0.9) # 하면 된다.

x = c(105,108,86,103,104,107,124,105)

y = c(89,92,84,97,103,107,111,97,101,106)

x
y

n1 = length(x)

n2 = length(y)

n1
n2

sp2=((n1-1)*var(x)+(n2-1)*var(y))/(n1+n2-2) #공통분산추정량

sp=sqrt(sp2)

talpha =qt(0.975,n1+n2-2)

se=sp*sqrt(1/n1+1/n2) # 표준오차

error = talpha*se # 95% 오차한계

LCL = (mean(x)-mean(y))-error
UCL = (mean(x)-mean(y))+error

LCL
UCL

# 구간추정 먼저 한 것.

t0=(mean(x)-mean(y))/(sqrt(sp2*(1/n1+1/n2))) # 검정통계량 sp2를 앞으로 sp로 빼도됨.

# t0=(mean(x)-mean(y))/se #로 해도 됨

t0

pval=2*(1-pt(t0,n1+n2-2))
pval
round(c(Sp2=sp2,T=t0,p_value=pval),4)


