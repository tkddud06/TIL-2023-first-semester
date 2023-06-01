x = c(154,154,186,143,159,174,183,163,172,181,180)
n = length(x)
xbar = mean(x)
se = sd(x)/sqrt(n)

error = qt(0.975,n-1)*se

LCL = xbar - error
UCL = xbar + error

t=(xbar-170)/se

v_LCL = (n-1)*var(x)/qchisq(0.975,n-1)
v_UCL = (n-1)*var(x)/qchisq(0.025,n-1)

chisq = ((n-1)*var(x))/(10*10)

a = c(30,18,42,28,45,17,10,20,29,25,19,25)
b = c(10,9,15,24,10,7,16,14,13,18,17,14,12,10,5)

n1 = length(a)
n2 = length(b)


# 집단 개수쪽 부분은 조금 더 봐야할 듯.


before = c(67,88,82,79,76,56,67,77,70,58,61,71)
after = c(60,89,79,76,70,50,61,73,72,54,57,70)
t.test(before,after, alt="less", mu=0, paired=T)

n=80
phat = 0.2
se = sqrt(phat*(1-phat)/n)
error = qnorm(0.975)*se
LCL = phat - error
UCL = phat + error
z = (phat-0.18)/sqrt(0.18*(1-0.18)/n)

phat1=420/500
phat2=380/500

se= sqrt(((phat1*(1-phat1))/500)+((phat2*(1-phat2))/500))
LCL = phat1-phat2 - qnorm(0.975)*se
UCL = phat1-phat2 + qnorm(0.975)*se