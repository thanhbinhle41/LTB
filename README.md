# LTB
GameC++
- Thể loại: Hành động
- Ý tưởng: Nhân vật tự động nhảy lên nhảy xuống, dash qua chướng ngoại vật/địch hoặc bắn chết chướng ngoại vật/địch và tính điểm
+ Nhân vật: Tự động nhảy lên nhảy xuống 
            Bắn skill
            Dash (A&D)
+ Chướng ngoại vật/địch: Tự động nhảy lên nhảy xuống (tự động sinh và random size & velocity)
                         Nhân vật đụng vào sẽ chết
- Chức năng đã hoàn thành:
+ Animation
+ Auto Jump
+ Dash
+ Deadth
- Danh sách file CPP gồm có::
+ Animation.cpp: animation của nhân vật và chướng ngoại vật/địch
+ Player.cpp: chứa các tính năng như Auto Jump, Dash, Skill... của nhân vật
+ Enimie.cpp: kế thừa player và thêm 1 tính năng khác
+ Ground.cpp: ground xung quanh game
