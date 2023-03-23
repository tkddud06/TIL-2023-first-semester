# 16일차 내용 복습. attach 부분, 스킵하긴 했지만, pie 교과서부분 더 자세히 알아봐야 함.
# barplot, pie, read.table 등 함.

# pie(slice,label) : slice는 테이블 의미. 각각 몇 도수인지. label은 각 범주 이름.

# hist 얘기도 함

# hist freq 개념. 기본 true고, y축을 도수로 나타내줌. 만약 이게 아니면, density로 보여줌.
# 아마 여기서 density는 확률. 총합은 1이다. 아래 링크와, dataa 참고.
# https://rdrr.io/r/graphics/hist.html 참고.

dataa = c(1,2,3,4,5)
hist(dataa,freq=F)

# stem 줄기와 잎 그림

# boxplot 상자그림

# plot: plot(x축, y축, 타입(type, "l" = line), 제목(main) 등)

x = seq(-4,4,by=0.01)

plot(x, dnorm(x), type="l", main="Normal dist") # type 숫자 아니고, 영어입니다. l = line

# dnorm = d 노말. 정규분포 함수. x에 해당하는 y축값,(밀도)를 찍어주라는 얘기