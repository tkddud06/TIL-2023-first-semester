# 16일차 내용 복습.

### 교수님이 수업은 안했지만, 책에 있는 내용.
slices = c(8,1,10,5)
labels = c("A","AB","B","O")
labels = paste(slices,labels) # paste는 두 내용을 붙여준다는 내용인가봄
labels
pie(slices,labels = labels, col = rainbow(length(labels))) # 아마 col은 컬러를 뜻하나봄. 레인보우가 됐다.
# length는 개수인가봄. 개수 맞춰서, 색 바꿔주나봐.
# 그외에, 상대도수 (어떤값에대한 도수/전체도수) 구해서 그거 paste하는것도 있음. 성분으로 sep이 있네. 
# sep은 파이썬이랑 같네.

# hist, 그리고 plot 성분 중에 xlab, ylab이 있음. 이건 x축 제목, y축 제목인듯. (라벨 축약자가 아닐까싶다)
# plot의 경우, xlim 이라는 성분이 있다. x축의 최솟값, 최댓값을 정하는 것인거 같다.
# (리미트 약자?)

# 비슷하게, stem에서는 scale이 구간을 어떻게 나눌지래요. 클수록 구간이 많아지고.

# cumsum은 누적합 함수임. 하나씩 더할때마다, 값 뽑아주나본데?


###

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

plot(x, dnorm(x), type="l", main="Normal dist") # type 1아니고, 영어임. l = line, o면 점과 선 동시에.

# dnorm = d 노말. 정규분포 함수. x에 해당하는 y축값,(밀도)를 찍어주라는 얘기