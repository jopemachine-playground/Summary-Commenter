<h2>Outline</h2>
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/144828b21cf043aa9fc8381b95ec8bae)](https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jopemachine/CommentHelper&amp;utm_campaign=Badge_Grade)

2019 Personal Project


## Comment Helper

지정한 프로젝트 내 타겟 확장자 파일들에 지정한 주석을 추가하는 일종의 매크로 프로그램



## Development Environment



> Windows 10,  64 bit
>
> Qt 5.12.4 (MSVC 2017, 32bit)
>
> Qt Creator 4.9.2



## How to work

**chs 파일** : comment helper가 사용하는 설정 파일. 정규식을 이용해 읽어들임. 기본적으로 아래 값 들을 갖고 있고,  
`{ fileName }::[ desc | issue | urls ] += { content }` 형식으로 값을 작성해,  해당 파일 주석에 값을 추가할 수 있음.

```
# Flags
flag.Author   			=   1
flag.Last_Edited   		=   1
flag.Desc   			=   1
flag.Issue   			=   1
flag.Sup_Div_Line   	        =   1
flag.Sub_Div_Line  		=   1
flag.Email   			=   1
flag.Telephone   		=   1
flag.Github_Account   	        =   1
flag.Ref_URLs   		=   1

# Globals
global.Extension        =  
global.Project_Path     =  
global.Author           =  
global.Separator        =  
global.Sub_Div_Line     = 
global.Sup_Div_Line     =  
global.Email            =   
global.Telephone        =   
global.Github_Account   =   
```



아래처럼 desc, issue, urls 값만 명시한 chs 파일의 경우 Open하면 flag, global 값은 변하지 않고 import한 파일의 설정만 추가하는 식으로 이용할 수도 있음.



```
# [*.chs]
constant.h::desc       	+=              상수 값들을 모아놓은 헤더 파일
mainwindow.cpp::desc	+=		이벤트 처리 메인 윈도우 구현 파일
gamemanager.cpp::issue	+=		버그 있음
gamemanager.cpp::urls	+=		https://urlexample.com
constant.h::urls        +=		https://urlexample2.com
```



**chproj 파일** : Run 후 지정된 경로에 생성됨.  주석을 추가한 파일의 이름들을 갖고 있는 파일. chproj 파일을 통해 Remove Comments 버튼을 눌러 comment helper가 추가했던 주석을 제거할 수 있다.



**chlately 파일** : 최근 열었던 chs 파일들의 경로를 5개 까지 기억하고 있음. comment helper 실행 시 가장 최근에 열렸던 chs 파일을 자동으로 셋팅하며, Open Recents 버튼으로 이 경로의 chs 파일들에 접근할 수 있음.





## Caution

프로그램 작동 상 주의할 점은 아래와 같다.

* 지정한 디렉토리 내에 중복되는 이름을 가진 파일이 없다고 가정하고 작동한다. 중복되는 이름이 있는 파일이 있는 경우, Desc, Issue 등이 파일에 제대로 추가되지 않을 수 있음.
* 지정 디렉토리 폴더에 chproj 파일이 존재해야만 주석을 삭제하는 기능을 사용할 수 있다. 
* 주석을 삭제하는 기능은 chproj 파일에 명시된 파일들의 맨 처음 나온 주석을 제거한다. comment helper가 추가한 주석 위에 다른 주석이 달려 있다면, comment helper가 추가한 주석이 제거되지 않을 수 있음.
* chproj 파일을 임의로 삭제하거나 변경하면, 주석 업데이트 시 중복 주석이 추가될 수 있음



<h2>Screen shots</h2>



<img src="ScreenClip.png">



위 설정으로 만들 수 있는 주석의 예.

```
// ==============================+=====================================...
// @ Author : jopemachine
// @ Last Edited : 2019-08-13, 18:35:15
// @ Desc : 
// @     1. 메인 윈도우의 구현 파일이다.
// @ Issue : 
// @ Email : jopemachine@naver.com
// @ Contact : 012-345-6789
// @ Github Account : gravityc95@gmail.com
// @ Ref URLs : 
// @     1. https://github.com/jopemachine/CommentHelper
// @     2. https://github.com/jopemachine/Gomoku-Qt
// @ Memo : 
//  1. 메모 1
//  2. 메모 2
//  3. 메모 3
// ==============================+=====================================...
```

