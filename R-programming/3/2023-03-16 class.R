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

attach(blood)


data=c(147,153,155,152,146,160,155,146,155,163,151,159)
data

hist(data)

hist(data,right=FALSE) # right=FALSE는 경계값을 빼겠다는 의미. 
# (원래 150이상 160이상 이랬는데, 150미만, 160미만으로 들어가짐. 
# 경계의 오른쪽 끝 구간을 false시킨다)

hist(data,br=seq(140,170,10), right=FALSE) #구간을 140~170까지 줄건데, 간격을 10으로

hist(data,br=seq(140,170,5), right=FALSE) # 구간을 140~170까지 줄건데, 간격을 5로

stem(data) # 줄기 잎 그림

boxplot(data) # 상자그림

students = read.table("C:\\Users\\ProSet\\git\\TIL-2023-summer-season\\R-programming\\3\\10students.txt",header=T)
str(students)
# height = c(162,163,166,168,169,171,173,174,175,179)
 #weight = c(54,56,56,64,62,64,82,67,71,74)
attach(students)
plot(weight,height,main="Scatter plot")
cor(weight,height)