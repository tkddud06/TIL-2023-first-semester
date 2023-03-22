a = 3
c = 3.2
a = int(c)

print(a)

a = 3e10 # 이렇게 저장하면, 실수로 저장
print(a)

print("%d %f" % ((3+5), 3.14))
print("{} {} {}".format(a,c,a))
print(r"\ lol ~~~~")
print(f"{a} {c} {a}")

# https://m.blog.naver.com/rosie018/222637135322 (출력형식 참고.)

c = not (a)
print(c) # 논리 not연산시, false와 true로 값 나옴

c = ~5 # 비트 not 연산시, 각 비트가 뒤집혀짐. ~5의 각 비트를 뒤집은, -6 나옴
print(c)
print(c+1) # 거기에 1을 더하면 원래 수의 음수 버전이 나옴

print(ord('a'), chr(65)) # ord는 문자 > 아스키코드, chr은 아스키코드 > 문자 함수.