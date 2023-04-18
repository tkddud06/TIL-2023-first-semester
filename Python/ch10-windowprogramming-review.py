
from tkinter import *
from tkinter import messagebox # 
from tkinter import filedialog # import는 무조건 모듈을 임포트하는 얘라고 생각하면 됨. 아마 tkinter는 패키지이면서, 모듈로서도 기능하나봄. 메시지박스 등은 애에 속하는 모듈이고,
from tkinter.simpledialog import * # from import 형식도 같음. from에는 모듈이 들가고, import는 그 모듈에 속한 함수. 이렇게하면 .붙이지 않고 바로사용 가능

def printmessagebox():
    messagebox.showinfo("타이틀", "ㅋㅋㅋ")
    # label1.configure(text="내용변경 테스트") # configure 사용해서, 내용 변경 가능
window = Tk()

window.title("윈도창 연습") # 타이틀 선언
window.geometry("800x800") # 사이즈 선언
# window.resizable(width=FALSE, height=FALSE) # 사이즈 조절 가능여부 선언. 기본값 TRUE

label1 = Label(window, text = "텍스트1")
label2 = Label(window, text = "텍스트2", font=("궁서체",30), fg="blue")
label3 = Label(window, text = "텍스트3", bg ="magenta", width= 20, height = 5, anchor = SE) # 여기서 anchor은 width height 지정한 bg크기 기준.
# width,height가 font 크기 변경시에 같이 변화하네? 흠.

photo = PhotoImage(file = "./testimg.png") #
label4 = Label(window, image= photo)

label1.pack()
label2.pack()
label3.pack() # 얘네를 띄우겠다는 선언
label4.place(x=200,y=200) # pack대신 place 사용시, 다른거 다 무시하고, 고정 위치에 띄울 수 있음. pack 쓴 것들이랑 자동으로 맞춰지지는 x. 그냥 덮거나 해버린다.

button1= Button(window, text = "종료" , fg ="red", command=quit) #이미지 등도 가능
chk = IntVar() # IntVar는 tkinter모듈의 함수. 이외에도 StringVar 등 있네용.
checkbox = Checkbutton(window, text="체크", variable=chk, command=printmessagebox)
# quit로 쓰면 되고, quit()는 안 되네. 아마 ()를 일부러 생략 시키는듯? map함수처럼
button1.pack(side=BOTTOM, fill=X, padx=10,pady=10,ipadx=5,ipady=5) # padx,y는 바깥 여백, inpadx,y는 안의 여백.
checkbox.pack()

# print(type(chk)) 해보면, 다들 tkinter 고유의 객체임을 알 수 있다.(참고)

# RadioButton도 만들수 있다. checkButton에서, 매개변수로 value만 value =1 , value=2 식으로 더 받을 수 있음.

# pack에서 수평정렬을 원한다면 side=LEFT or RIGHT로, 상하는 TOP or BOTTOM ("" 안하고 바로 쓴다.) 기본 TOP 인듯?
# 매개변수로 fill=X 를 적어주면, 윈도창 폭에 맞추어 객체들을 띄울 수 있다.

window.mainloop() # 얘는 항상 맨밑에 있어야 하네. 안써주면 화면 출력 xx.
########################

################ 여기까지가 기본 GUI. 아래부터는 마우스 이벤트 처리

window2 = Tk()
window2.title("입출력 검출 테스트")
window2.geometry("400x400")

def mouseactive(event): # 이름은 자유인데, 뒤에 매개변수로는 event를 써야 되나봐.
    messagebox.showinfo("신호 검출", "마우스 신호 검출됨!")
    print(event.x,event.y,sep="  ")
    # 함수 내에서, 매개변수로 받은 event에 대하여.
    # event.num == 왼쪽이면 1, 가운데면 2, 오른쪽이면 3.
    # event.x, event.y 는 각각 클릭된 정확한 좌표를 표시. 해당 x,y는 창 전체가 아닌, 위젯 기준으로의 위치인듯.
window2.bind("<Button-1>", mouseactive) # 마우스 신호 잡아주는 명령줄. 신호의 종류는 ch10 29p 참고
# window2말고, 지정한 위젯, 라벨 등으르도 가능. 아래처럼
button4= Button(window2, text = "종료" , fg ="red", command=quit)
button4.bind("<Enter>",mouseactive) # 다만, 이래놓으니까 버튼을 잘 못 누르겠다. 올려져있는 상태면 계속 함수가 작동되네.
button4.pack()
# 올려지는 순간만이 아니라, 올려져있는 상황을 계속 감지하는건가봄.

# 마우스가 아닌 키보드도 비슷한 방식으로 동작. 38p 참고.,
# 키보드는 입력값 확인으로 마우스에서의 event.num 대신에 event.keycode 사용

window2.mainloop()
# 아마 mainloop를 돌리면, 해당 객체뿐만 아니라, 타 객체에도 영향을 주나봄. 위에꺼 주석 놓고, 밑에거 돌리면 동시에 켜지고,
# 둘다 키면 하나씩 각각 끄고 나니 다시 켜지네.


################################ 여기서부터는 메뉴 관련 내용

window3 = Tk()
window3.title("메뉴 테스트")
window3.geometry("400x400")

mainmenu = Menu(window3)
window3.config(menu = mainmenu)
highmenu = Menu(mainmenu)
mainmenu.add_cascade(label = "상위 메뉴1", menu = highmenu)
highmenu.add_command(label = "하위 메뉴 1", command=printmessagebox)
highmenu.add_separator() # 선 출력. 지금 적어둔 순서대로라면, 하위 메뉴 1과 2 사이에 선 출력됨.
highmenu.add_command(label = "하위 메뉴 2", command=printmessagebox)

# 순서 1. 해당 윈도우의 메뉴 자체를 만든다.
# 순서 2. 메뉴로 고를 수 있는 것들을 만든다.
# 순서 3. 해당 메뉴들의 하위 메뉴들을 만든다.
# 약간 트리 내려오듯이 되는거지.

filename = filedialog.askopenfilename(parent = window3, filetypes = (("GIF 파일","*.gif"),("모든 파일","*.*")))
savefilename = filedialog.asksaveasfile(parent = window3, mode = "w", defaultextension=".jpg", filetypes= (("JPG 파일","*.jpg"),("모든 파일","*.*")))
print(type(savefilename)) # <class '_io.TextIOWrapper'> 라네. 파이선 자체 거, 파일입출력 관련된 얘인것 같다.
savefilename.close()

# from tkinter import filedialog 과 연계된, 파일이름 받아오는 함수, 그리고 특정 파일로서 저장하는 함수.

var1 = askinteger("입력받을 수", "수를 입력하세요", minvalue=0,maxvalue=10)
# from tkinter.simpledialog import *과 연계된, 대화상자 생성하고 입력받는 함수
window3.mainloop()