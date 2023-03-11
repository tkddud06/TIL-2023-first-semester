# data.frame() 함수 : 데이터 프레임을 만듬
# c는 자료형이 같은 경우만 사용 가능함.
# 다른 걸 서로 엮으러면, data.frame을 사용하여야함.
# 데이터 프레임은, 행렬과 같은 구조이고, 각 열마다 다른 데이터 형을 가질 수 있다.
# 데이터 프레임은 행렬처럼 접근함
# 데이터 프레임 이름[i번째원소, j번째원소]
# 만약 해당 접근에서 i나 j를 생략하면, 행이나 열을 통째로 출력

x = c("남","여","남")
y = c(20,25,22)
data = data.frame(x,y)
data
data[1,]
data[,2]
###

# read.table() 함수 : 테이블 형식의 외부파일로부터 데이터를 읽어 데이터 프레임을 생성.
# read.table("파일이름", header=T); : 데이터에 header가 있는 경우. 없는 경우는 F씀.
# header는 타이틀이래. 이게 정확히 뭐지.. ??
# 뭐 접근하는 방법 등 얘기해줬는데, 나중에 다시 실습한대.

##

# summary() 함수
# 변수에 대한 기본적인 통계량 값을 모두 알려줌 (info같은 느낌)

# mean() : 평균 계산해줌
# median() : 중앙값 계산해줌

data = c(50000,75000,60000,55000,55000,70000,200000,55000)
# 만약 썼던 이름 또 쓰면, 전에꺼는 없애버리고 다른걸로 덮어씌워짐.
mean(data)
median(data)
var(data)
sd(data)

# 그외 var, sd(스탠다드데비에이션?) 있음
# var() : 분산
# sd() : 표준편차
# 여기서도 함수 값들을 당연하게도 변수에 저장할 수 있음.
# 다만, 저장했을땐 결과를 보기 위해선 따로 또 코드로 찍어줘야 함.
xbar=mean(data)
xmedian=median(data)
s2=var(data)
strdev=sd(data)
strdev

cv = strdev/xbar
cv

max(data)
min(data)

q1=quantile(data,0.25)
q3=quantile(data,0.75)

q1
q3

IQR(data)

summary(data)

# 그 외에, sort() : 오름차순 정렬, min(),max(),
# quantile(자료,prob=0.25or0.75) : 제1사분위수 혹은 제3사분위수
# IQR() : 사분위수 범위, 대문자로 무조건 써야 됨!
# mean은 사실 ()안에 ,trim=0.2 등으로 20% 절사평균 등을 구할 수 있다.
# 등이 있다.

# 사분위 편차는 IQR을 2로 나누면 된다.(수업내용)

# 31페이지 연습문제 3-4

data = c(93.5,105.8,106.5,116.6,152.4,125.0,128.3,132.1,136.7)
summary(data)
xbar = mean(data)
xmedian = median(data)
q1=quantile(data,0.25)
q3=quantile(data,0.75)
iqrdata = IQR(data)
iqrdatas = iqrdata/2
s2=var(data)
strdev=sd(data)

cv = strdev/xbar
cv

# 38p 연습문제 2번

data = c(9,12,18,14,12,14,12,10,16,11,9,11,13,11,13,15,13,14)
mean(data)
sd(data)
median(data)
iqr = IQR(data)
quantile(data,0.75)
iqr
iqrs = iqr/2
iqrs