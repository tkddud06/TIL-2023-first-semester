a = 10



res = 3 if a == 10 else 10 # 파이썬의 삼항 연산자

print("hello") if a == 10 else print("hgi")
# 이상하게, 삼항 연산자에, 하나는 print, 하나는 대입문 쓴다던가, 5번 문장에 res = 3 해놓고, 뒤에 c = 5 이렇게 쓴다던가가 안 된다.
# 약간 대칭? 형식?? 이라 해야하나. 아무튼 그럼 느낌으로 해야 하나봄. 근데 헷갈려서 안쓰는게 낫겠다.
# 참고. https://blockdmask.tistory.com/551 , https://wikidocs.net/20701


# if else elif 등 함

z = [1,2,3,4,5]
z.append(6)
z.append(7)

if 5 in z:
    print("5 있다!")

for _ in range(10):
    print("%d" % _ )

# 책에서 for문의 변수로서 i를 쓰기 싫으면, _를 쓰라고 언급해서 뭔가 특별한게 있나? 했지만 추정컨데 그냥 변수명이 _가 되는거 같다.

# range는 끝값이 적어둔거 1 전이라는 점. 음수의 경우, 1 전이므로, 더 커짐.

# while문도 함.

# 무한반복도 함. (true 써서)
# 컨트롤 + c로 강종 가능.

# break, continue의 차이 잘 알아둘 것
# break = 아예 반복문 끝냄. 반복문 밖으로 탈출. continue = 끝으로 건너뛴 후, 다시 반복문으로 돌아감. (해당 반복문 단계를 건너뛴다고 보먄 됨.)
