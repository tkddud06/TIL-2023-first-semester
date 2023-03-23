blood=read.table("C:\\Users\\ProSet\\git\\TIL-2023-summer-season\\R-programming\\2\\blooddatain10p.txt", header=F)
# false가 디폴트
str(blood)
table(blood$V1)
barplot(table(blood$V1)) # 막대그래프

#원형 그래프
slices = c(8,1,10,5) # == table(blood$V1)
lables=c("A ","AB ","B ","O ")
pie(slices,lables,main="Pie Graph(1)")
pie(slices,lables)
# label을 뭐 더 넣어주고 뭐 하는건 스킵한다는데? 뭐말하는거지, 
# 범주,상대도수 결합 이런거 하는거 말하는건가?
# 18p ver2, ver3 말하는 듯.

attach(blood) # 현재 읽은 데이터에서 자료를 변수로서? 고정합니다.
# 추가로 나중에 찾아봐야겠다.


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

stem(data) # 줄기 잎 그림

boxplot(data) # 상자그림

students = read.table("C:\\Users\\ProSet\\git\\TIL-2023-summer-season\\R-programming\\3\\10students.txt",header=T)
# 여기선 header가 있으니 true
str(students)
# height = c(162,163,166,168,169,171,173,174,175,179)
 #weight = c(54,56,56,64,62,64,82,67,71,74)
attach(students)
plot(weight,height,main="Scatter plot")
cor(weight,height) # 공분산