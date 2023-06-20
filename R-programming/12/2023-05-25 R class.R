#201쪽 참고. 예제 10-1

x = c(105,108,86,103,104,107,124,105)
y = c(89,92,84,97,103,107,111,97,101,106)

x
y

n1 = length(x)

n2 = length(y)

n1
n2

f0 = var(x)/var(y)
f0

falpha = qf(0.95,n1-1,n2-1) # 기각치
falpha

pval = 1-pf(f0,n1-1,n2-2) # p-value
pval

round(c(f=f0, CV=falpha, p_value=pval),4)
# 귀무가설 채택, 등분산이다.

var.test(x,y) # 등분산 추정, 양측검정 ( 기본값 95% 추정)

var.test(x,y,alt="greater",conf.level=0.9) # 등분산 추정, 단측검정

n1 = length(x)
n2 = length(y)
n1
n2

sp2 = ((n1-1)*var(x)+(n2-1)*var(y)/(n1+n2-2)
sp2
sp=sqrt(sp2)

talpha = qt(0.975,n1+n2-2) # 임계치

se=sp*sqrt(1/n1+1/n2) # 표준오차

error = talpha*se # 95% 오차한계

LCL = (mean(x)-mean(y))-error # 하한값
UCL = (mean(x)-mean(y))+ error # 상한값


t0 = (mean(x)-mean(y))/(sp*sqrt(1/n1+1/n2)) # 검정통계량
#pval에 2를 곱해준 이유는 양측 검정이라서.
pval= 2*(1-pt(,t0,n1+n2-2))


t.test(x,y,var.equal=T)
# 여기선 t 나온거 보고 검증가능이네(검정통계량)

#pval이 작아야, 귀무가설 기각(그집 자식일 가능성이 작다)

before=c(128,131,131,127,132,125,141,137,118,132,129,135)
after = c(120,124,130,118,140,128,140,135,126,130,126,127)

d = before-after # 책기준으로, 둘을 바꾸고 d0를 -5에서 5로 바꾼 차이
d0 = 5
n=length(before)
se=sqrt(var(d)/n) # 표준오차
cv=qt(0.975,n-1) # 임계치
t0=(mean(d)-d0)/se # 검정통계량
pval=2*(pt(t0,n-1)) # p-value # 여기서 1을 안 빼주는 이유. 지금 이미 -값이고, 왼쪽부터 누적된 값이기 때문.
round(c(mean_after=mean(after),mean_before=(mean(before)),T=t0,CV=cv,p_value=pval),3)

t.test(before, after, mu=5, paired=T) # paired를 써줘야 대응비교가 가능.
