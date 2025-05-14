int gotoxy(int x, int y);	//Constants 커서옮기기 
void SetColor(int color);	//Constants 색표현 
int init();					//기능상 문제로 쪼개짐 각종변수 초기화 
int show_cur_block(int shape, int angle, int x, int y);	//Renderer 진행중인 블럭을 화면에 표시한다
int erase_cur_block(int shape, int angle, int x, int y);	//Renderer 블럭 진행의 잔상을 지우기 위한 함수
int show_total_block();	//Renderer 쌓여져있는 블럭을 화면에 표시한다.
int show_next_block(int shape); //Renderer
int make_new_block();	//BlockFactory return값으로 block의 모양번호를 알려줌
int strike_check(int shape, int angle, int x, int y);	//Board 블럭이 화면 맨 아래에 부닥쳤는지 검사 부닥치면 1을리턴 아니면 0리턴
int merge_block(int shape, int angle, int x, int y);	//Board 블럭이 바닥에 닿았을때 진행중인 블럭과 쌓아진 블럭을 합침
int block_start(int shape, int* angle, int* x, int* y);	//BlockFactory 블럭이 처음 나올때 위치와 모양을 알려줌
int move_block(int* shape, int* angle, int* x, int* y, int* next_shape);	//Game 게임오버는 1을리턴 바닥에 블럭이 닿으면 2를 리턴
int rotate_block(int shape, int* angle, int* x, int* y); //Block
int show_gameover(); //Renderer
int show_gamestat(); //Renderer
int show_logo(); //Renderer
int input_data(); //inputHandler
int check_full_line(); //Board
int get_valid_int(int min, int max); //InputHandler
void clear_line_mt(int x, int y); //constats
void clear_block(int x, int y); //Constatns
