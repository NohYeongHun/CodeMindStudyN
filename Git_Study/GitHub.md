# Git 공부

# git init 
- 해당 폴더를 git 명령어를 이용할 수 있는 폴더로 만듬.
  로컬 git 저장소가 생성된다고 생각하면 편함.

# git clone
- 원격 저장소(웹에 존재하는 저장소)를 지역 저장소에 복제.
  .git 폴더 까지 포함해서 소스를 제공 받을 수 있음.
  github에서 만든 원격저장소로 시작하고 싶을 때 자주 사용(로컬
  저장소에 그대로 폴더 복제.)
- 특정 repository를 내 local machine에 복사하여 새로운 저장소를 만듬.
  clone한 원본 repository를 remote 저장소 origin으로 가지고 있음. 권한이
  없는 경우 해당 저장소로 push 불가.
  또한 기존의 제

# git remote 
- 해당 지역 저장소가 원격 저장소에 연결되어 있는지 확인.
- git remote add {별칭}{원격 저장소 url} - 해당 지역 저장소를
  원격저장소에 연결
- 작업폴더 -> 인덱스 -> 저장소(Head - Repository, 로컬 저장소와   
  원격 저장소)

# branch
- pull과 fetch의 차이 : merge의 여부
- git pull : git fetch + git merge
  ex) git pull origin{branch name} - origin에 연동된 원격 저장소에서 특정
  브랜치만 pull 해옴.
  git merge : local branch와 local branch를 merge(병합)한 commit 생성.
  git pull : local branch와 remote branch를 merge(병합)한 commit 생성.
  git pull의 사용처는 보통 local/master 브랜치로 remote/master 브랜치를 가져올 때 사용.

# fork
- 다른 사람의 Github repository에서 내가 어떤 부분을 수정하거나 추가 기능을
  넣고 싶을 때 해당 repository를 내 Github repository로 그대로 복제하는
  기능. fork한 저장소는 원본과 연결되어 있음. 여기서 연결의 의미는 original repository에 변화가 생기면(새로운 commit) 이는 그대로 forked된 repository로 반영이 가능. 이 때 fetch나 rebasae의 과정 필요.
  이 후 original repository에 변경 사항을 적용하고 싶으면 해당 저장소에 pull request를 해야함. pull request가 original repository의 관리자로부터
  승인 되었으면 내가 만든 코드가 commit, merge되어 original에 반영. pull
  request 하기 전까지는 내 github에 있는 forked repository에만 change가 적용됨.
- ex) 가져오고 싶은 repository가 저장된 github 주소로이동.
fork 클릭 시 내 repository에 그 사람의 repository가 저장됨.

  
