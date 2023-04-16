#초기하분포, red = 2, white = 3 공 2개 꺼내는 상황

dhyper(x=0,m=2,n=3,k=2) # P(X=0)
dhyper(x=1,m=2,n=3,k=2)
dhyper(x=2,m=2,n=3,k=2)

phyper(q=1, m=2, n=3, k=2) # 누적확률 P(X<=1)
phyper(1, 2, 3, 2)

# 로또 당첨 확률
# x는 확률변수(이게 정확한 표현인가?), m은 진짜개수, n은 가짜개수, k는 뽑는 수
dhyper(x=0,m=6,n=39,k=6)
dhyper(x=1,m=6,n=39,k=6)
dhyper(x=2,m=6,n=39,k=6)
dhyper(x=3,m=6,n=39,k=6)
dhyper(x=4,m=6,n=39,k=6)
dhyper(x=5,m=6,n=39,k=6)
dhyper(x=6,m=6,n=39,k=6)
####### 헷갈려서 다시 봐야겠다.
# 로또 꽝일 확률
phyper(q=2,m=6,n=39,k=6)


# 연습문제 1번 경우에서, 찬성하는 사람이 3명 포함될 확률

dhyper(x=3,m=8,n=7,k=5)


# 이항분포

# 예제 6.2 문제
# size 시도횟수 p 확률
dbinom(x=8, size=20, p=0.3) # 딱 8명 치유할 확률
pbinom(q=11, size=20, p=0.3) # # 11명 이하로 치료할 확률

1-pbinom(q=10,size=20,p=0.3) # 11명 이상 치유 확률.

# P(4<=X<=10)

pbinom(q=10, size=20, p=0.3) - pbinom(q=3, size=20, p=0.3)


# 연습문제 5번, 6번

1 - pbinom(q=5, size = 10, p = 1/5)

1 - pbinom(q=9, size=20, p=0.3)

# 아마 이항분포, 초기하분포까지는 이산이고, 포아송부터 밀도인듯.
# 아 아닌거같은데? 재확인 필요. 포아송도 이산인듯.


dbinom(x=1, size=20, p=0.2)
1- pbinom(q=3, size=20, p=0.2)

# 포아송 분포

dpois(x=4,lambda=6)
dpois(4,6)
ppois(q=3,lambda=6) # 누적확률 P(X<=3)


# 연습문제 7번

dpois(x=1, lambda=3)
ppois(q=5, lambda=3)

dpois(x=0,lambda=0.3)
1-ppois(q=1,lambda=0.3) # 만약 X>=1이면 어카지? 어카긴, 포함해야지. 아마 포아송도 이산인듯.

dpois(x=2,lambda=2)
ppois(q=7,lambda=2)-ppois(q=2,lambda=2) # <=이므로, 3포함 안하게 주의.

# 예제 6-5. 이항분포의 포아송 근사
# 이항분포가 포이송 근사가 되는 조건이나 뭐 이런게 뭐지?

dbinom(x=0, size=1860, p=1/600)
dbinom(x=1, size=1860, p=1/600)
dbinom(x=2, size=1860, p=1/600)
dbinom(x=3, size=1860, p=1/600)


1860/600
dpois(x=0, lambda= 3.1) # 평균 lambda = np;
dpois(x=1, lambda= 3.1)
dpois(x=2, lambda= 3.1)
dpois(x=3, lambda= 3.1)

# 정규분포

# 예제 6-6, 4번

# X ~ N(30, 4^2)
# p(20<=X<=37)=?

pnorm(q=37,mean=30,sd=4) - pnorm(20,30,4)

# 예제 6-7, 3번

# 491 < x < 498

pnorm(498,500,5) - pnorm(491,500,5)


qnorm(0.975,0,1) # 누적 0.975를 달성하는 z값을 찾는거.
qnorm(0.95)

# x ~ n(100, 8^2)에서,
# 어떤 수 i보다 클 확률이 0.025가 될 확률

qnorm(0.975,100,8)

# 연습문제 13번-3번

qnorm(0.05,100,8) # c1
qnorm(0.95,100,8) # c2
# 이 문제는 절대적인 c가 아니라, 무조건 c1 c2로 두개가 나오는 구조. 
# -c로 풀면 안 된다! 값 자체가 양수 음수 구조가 아님! (솔찍히 이해잘 안됨) 
# 중간이 0이 아니니까 그런거! 표준이 아니면!