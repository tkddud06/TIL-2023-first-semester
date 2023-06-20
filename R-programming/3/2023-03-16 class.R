blood=read.table("C:/Users/tkddu/git/TIL-2023-summer-season/R-programming/2/blooddatain10p.txt", header=F)
# false가 디폴트
str(blood)
table(blood$V1)
barplot(table(blood$V1)) # 막대그래프

#원형 그래프
slices = c(8,1,10,5) # == table(blood$V1)
lables=c("A ","AB ","B ","O ")
pie(slices,lables,main="Pie Graph(1)") # 위 barplot처럼 테이블을 바로 쓰면, label을 쓰지 않아도 자동으로 해줌.
pie(slices,lables)


attach(blood) # 현재 읽은 데이터에서 자료를 변수로서 고정합니다.
# 추가로 나중에 찾아봐야겠다.
# 공통적으로 계속 사용되는 대상 데이터 프레임을 지정(활성화 한다고 함)할 때는 attach(), 
# 다른 데이터 프레임으로 바꾸고자 기존의 지정(활성화)된 데이터 프레임을 해제하고자 할때는 detach() 함수를 사용합니다.
# detach는 배우지는 않았다.

data=c(147, 150, 153,152,146,146,163,151,159,165)
# 원래 교수님이 제시해주신 데이터는 아래고, 위는 테스트용.
data=c(147,153,155,152,146,160,155,146,155,163,151,159)
data

hist(data, freq=T)
hist(data, freq=F)

hist(data,right=FALSE) # right=FALSE는 경계값을 빼겠다는 의미. 
# (원래 150이상 160이상 이랬는데, 150미만, 160미만으로 들어가짐. 
# 위에건 좀 애매하고, 밑말이 정확함. 실행시켜보면 앎.

# 찾아본 결과 : https://kin.naver.com/qna/detail.naver?d1id=1&dirId=104&docId=297983615&qb=ciBoaXN0IHJpZ2h0&enc=utf8&section=kin.ext&rank=2&search_sort=0&spq=0
# 맨왼쪽 막대는 예외로, 왼쪽끝값 무조건 포함이고, 그 외에는 오른쪽끝만 포함. (오른쪽이 이하, 기본값, true)
# 오른쪽 막대는 예외로, 오른쪽끝값 무조건 포함이고, 그 외는 왼쪽끝만 포함 (왼쪽이 이상, false)

hist(data,br=seq(140,170,10), right=FALSE) #구간을 140~170까지 줄건데, 간격을 10으로
hist(data,br=seq(140,170,5), right=FALSE) # 구간을 140~170까지 줄건데, 간격을 5로
# 여기서 br은 브레이크를 의미. 저 지점들이, 각각 막대의 잘리는 부분이 됨. 즉, 브레이크포인트가 된다. seq는 연속형
# 자료 만드는거니, 실제론 140, 150, 160, 170 이런식으로 되있는거고 말이야.
stem(data) # 줄기 잎 그림

boxplot(data) # 상자그림

students = read.table("C:\\Users\\ProSet\\git\\TIL-2023-summer-season\\R-programming\\3\\10students.txt",header=T)
# 여기선 header가 있으니 true
str(students)
# height = c(162,163,166,168,169,171,173,174,175,179)
 #weight = c(54,56,56,64,62,64,82,67,71,74)
attach(students)
plot(weight,height,main="Scatter plot")
cor(weight,height) # 상관계수
cov # 가 공분산