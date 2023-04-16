# 알아둘 것
a = c(1,2,3,4,5) # 콤바인. 뒤에거 받기.
seq(from,to,by)
rep(val,howmany)
matrix(val,nrow,ncol) #기본은 nrow. 원한다면 ncol.
data = scan() # 키보드로부터 입력받는거. 기본적으로 숫자받음.
data = scan(what=character(0)) # 문자열 받기

# 파일로부터 데이터 받을땐 scan 씀. scan("절대경로"). \ 말고, 파일경로는 /로 바꿔쓰기.

x = c(1,2,3)
y = c(4,5,6)
# data.frame(x,y...) 각 열이 x,y의 성분들을 갖게 함.
# x,y 행수 다르니까 안되더라.

# 행렬 접근은 c언어 비슷하긴한데, data[1,3] 이런식으로 한번에 묶어서 함.

# read.table("파일절대경로", header=T) 기본값 T. 헤더는 범주 말하는거.

# 이렇게 접근시, 각 자료 접근할 때, data=read.table~~~했다면 
# data$data1 이런식으로 해야함. $가 접근자.
# 남자만 검색하거나, 조건을 걸어 검색할 수 있음. data[data$data1>1] 이런식. sql마냥.

# attach(data) 한다면, $안붙이고 사용가능.

# summary(data) 총통계 보기
# table(data&gender) 이런식으로 쓰면 범주별 도수 알 수 있음.
# IQR(data) 사분위범위,
# quantile(data, 0.25) 제1사분위계수 0.75쓰면 제3
# mean 평균 median 중앙값 sd 표준편차 var 분산 length 변수개수 min max
# sort 정렬하기. sum(이터레이터) 합계

# 사분위편차랑 변동계수는 수동으로 구해야됨 각각 IQR/2, sd/mean

# 공분산이나 상관계수는 알아보기. str이 정확히 뭔지 알아보기.
# 수업자료 뒷 실습부분이나, 그래프 그리기는 해보기.


#### 2023-04-17

# 수업 시간에 했던 블러드 자료 도수분표포? 만들기 쓸때(table) c 형태로 묶은걸로는 안 되고,
# 그를 data.frame으로 묶은 경우는 가능하다. 아마 범주(header)가 달리기 때문인 것 같다.