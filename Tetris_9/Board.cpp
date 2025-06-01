#include "Board.h"
#include "Constants.h"
#include "Renderer.h"
#include "Block.h"
#include "StoryManager.h"
#include"PurpleBlock.h"
#include <cstdlib>   
#include <ctime>    
#include <cstring>   
#include <vector>


void Board::init() {
    // 전체 블록 배열을 0으로 초기화
    std::memset(total_block, 0, sizeof(total_block));

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // 벽 생성
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 14; ++j) {
            total_block[i][j].occupied = (j == 0 || j == 13) ? 1 : 0;
        }
    }

    // 바닥 생성
    for (int j = 0; j < 14; ++j) {
        total_block[20][j].occupied = 1;
    }
}




int Board::check_full_line(int& level, int& score, bool& bomb)
{
	int i, j, k;
	for (i = 0; i < 20; i++)
	{
		for (j = 1; j < 13; j++)
		{
			if (total_block[i][j].occupied == 0)
				break;
		}
		if (j == 13)	//한줄이 다 채워졌음
		{
			// Yellow 블록 처리를 위한 임시 배열
			Cell temp_row[14];
			bool has_remaining_yellow = false;

			// Yellow 블록 처리 및 데이터 연산
			for (j = 1; j < 13; j++) {
				// Yellow 블록 능력이 활성화되어 있고, Yellow 블록이 처음 지워지는 경우에만 특수 처리
				if (stage_data[level].abilities.yellowBlockAbility &&
					total_block[i][j].color == YELLOW &&
					total_block[i][j].count == 0) {
					// Yellow 블록이 처음 지워지는 경우
					temp_row[j] = total_block[i][j];
					temp_row[j].count = 1;  // 카운트 증가
					has_remaining_yellow = true;
				}
				else {
					temp_row[j].occupied = 0;
					temp_row[j].color = total_block[i][j].color;
					temp_row[j].count = 0;
				}
			}

			// 시각적 효과 표시 (Yellow 블록이 처음 지워지는 경우는 제외)
			gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++) {
				if (!(temp_row[j].color == YELLOW && temp_row[j].count == 1)) {  // Yellow 블록이 처음 지워지는 경우 제외
					SetColor(temp_row[j].color);
					cout << "□";
					SetColor(BLACK);
					cout << "□";
					Sleep(10);
				}
				else {
					SetColor(YELLOW);
					cout << "■";  // Yellow 블록 위치는 이펙트 없이 빈칸
					SetColor(BLACK);
					cout << "□";
					Sleep(10);
				}
			}
			gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++) {
				if (!(temp_row[j].color == YELLOW && temp_row[j].count == 1)) {
					cout << "  ";
					Sleep(10);
				}
			}

			// 블록 이동 처리
			if (has_remaining_yellow) {
				// Yellow 블록이 있는 경우, 각 열마다 개별적으로 처리
				for (j = 1; j < 13; j++) {
					if (temp_row[j].color != YELLOW || temp_row[j].count != 1) {
						// Yellow 블록이 아닌 위치만 위에서 내려오기
						for (k = i; k > 0; k--) {
							total_block[k][j] = total_block[k - 1][j];
						}
						// 최상단 초기화
						total_block[0][j].occupied = 0;
						total_block[0][j].color = 0;
						total_block[0][j].count = 0;
					}
				}
				// Yellow 블록 복원
				for (j = 1; j < 13; j++) {
					if (temp_row[j].color == YELLOW && temp_row[j].count == 1) {
						total_block[i][j] = temp_row[j];
					}
				}
				check_full_line(level, score, bomb);
			}
			else {
				// 일반적인 줄 제거 처리
				for (k = i; k > 0; k--) {
					for (j = 1; j < 13; j++) {
						total_block[k][j] = total_block[k - 1][j];
					}
				}
				// 최상단 줄 초기화
				for (j = 1; j < 13; j++) {
					total_block[0][j].occupied = 0;
					total_block[0][j].color = 0;
					total_block[0][j].count = 0;
				}
			}

			Renderer::show_total_block(level);

			Renderer::particle(level);
			score += 10;
			Renderer::show_gamestat(level, score, bomb);
			Sleep(20);
			if (stage_data[level].score <= score)	//클리어 조건달성
			{
				if(level != 6) {
					level++;
					bomb = true;
					StoryManager::showLevelUp(level);
					Renderer::showWizard(level);
					score = 0;
				}
			}
			Renderer::show_gamestat(level, score, bomb);
		}
	}
	return 0;
}

bool Board::strikeCheck(unique_ptr<Block>& b)
{
	int i, j;
	int block_dat = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (((b->getX() + j) == 0) || ((b->getX() + j) == 13))
				block_dat = 1;
			else if (b->getY() + i >= 0)
				block_dat = total_block[b->getY() + i][b->getX() + j].occupied;
			else
				block_dat = 0;

			if ((block_dat == 1) && (block[b->getShape()][b->getAngle()][i][j] == 1))			//좌측벽의 좌표를 빼기위함
			{
				return true;
			}
		}
	}
	return false;
}

void Board::mergeBlock(unique_ptr<Block>& b)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if ((b->getY() + i) < 0 || (b->getX() + j) < 0) {
				continue;  // 음수 인덱스는 건너뜁니다
			}
			if (block[b->getShape()][b->getAngle()][i][j] == 1) {
				total_block[b->getY() + i][b->getX() + j].occupied = 1;
				total_block[b->getY() + i][b->getX() + j].color = b->getColor();
			}
		}
	}
}

bool Board::rotateStrikeCheck(unique_ptr<Block>& b)
{
	int i, j;
	int block_dat = 0;

	int rotateAngle = (b->getAngle() + 1) % 4;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (((b->getX() + j) == 0) || ((b->getX() + j) == 13))
				block_dat = 1;
			else if (b->getY() + i >= 0)
				block_dat = total_block[b->getY() + i][b->getX() + j].occupied;


			if ((block_dat == 1) && (block[b->getShape()][rotateAngle][i][j] == 1))																							//좌측벽의 좌표를 빼기위함
			{
				return true;
			}
		}
	}
	return false;
}

bool Board::tryRotate(unique_ptr<Block>& b, int i)
{
	Renderer::eraseCurBlock(b);
	b->setX(b->getX() - i);
	if (rotateStrikeCheck(b) == false)
	{
		Renderer::eraseCurBlock(b);
		b->setAngle((b->getAngle() + 1) % 4);
		Renderer::showCurBlock(b);
		return true;
	}
	b->setX(b->getX() + i);
	Renderer::showCurBlock(b);
	return false;
}

int Board::moveBlock(unique_ptr<Block>& b, int& level, int& score, bool& bomb)
{
	Renderer::eraseCurBlock(b);

	b->setY(b->getY() + 1);   //블럭을 한칸 아래로 내림


	if (strikeCheck(b) == true)
	{
		if (b->getY() < 0)   //게임오버
		{
			return 1;
		}
		b->setY(b->getY() - 1);
		mergeBlock(b);

		// 블록이 착지할 때마다 하늘색 블록 체크
		checkAndRemoveCyanBlocks(level);

		// --- 능력 발동 구간 ---
		// 착지한 블록의 능력 조건 체크 및 능력 발동
		if (b->check(*this, level)) {// check 조건이 맞으면
			b->active(*this); // active로 능력 발동
			if (b->getColor() == RED) {
				score += 20;
				Renderer::show_gamestat(level, score, bomb);
				Sleep(20);
				if (stage_data[level].score <= score)	//클리어 조건달성
				{
					if (level != 6) {
						level++;
						bomb = true;
						StoryManager::showLevelUp(level);
						Renderer::showWizard(level);
						score = 0;
					}
				}
				Renderer::show_gamestat(level, score, bomb);
			}
		}
		// 보라색블록 작동되는지 확인
		if (stage_data[level].abilities.purpleBlockAbility) {
			PurpleBlock::update();
		}
		check_full_line(level, score, bomb);
		Renderer::show_total_block(level);

		

		for (int i = 1; i < 13; i++) { // 0부분과 13부분은 테두리로 제외해야함
			if (total_block[0][i].occupied == 1) {
				return 1;
			}
		}
		return 2;
	}
	return 0;
}


void Board::checkAndRemoveCyanBlocks(int& level) {
	// 현재 스테이지에서 하늘색 블록의 능력이 비활성화되어 있다면 false 반환
	if (!stage_data[level].abilities.cyanBlockAbility) {
		return;
	}
	vector<pair<int, int>> cellsToRemove;

	// 보드의 모든 하늘색 블록 확인
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (total_block[y][x].occupied && total_block[y][x].color == SKY_BLUE) {
				total_block[y][x].count++;
				if (total_block[y][x].count >= 5) {
					cellsToRemove.emplace_back(y, x);
				}
			}
		}
	}

	// 카운트가 5 이상인 하늘색 블록 제거
	for (const auto& [y, x] : cellsToRemove) {
		// 시각적 효과
		SetColor(BLUE);
		gotoxy(x * 2 + ab_x, y + ab_y);
		cout << "□";
		Sleep(40);

		gotoxy(x * 2 + ab_x, y + ab_y);
		cout << "  ";
		Sleep(10);

		// 셀 제거
		total_block[y][x].occupied = 0;
		total_block[y][x].color = 0;
		total_block[y][x].count = 0;
	}

	//// 변경사항이 있으면 화면 갱신
	//if (!cellsToRemove.empty()) {
	//	Renderer::show_total_block(0);
	//}
}

void Board::clearBottomLines(int& level, int lines) {
	int i, j;
	for (int phase = 0; phase < 3; phase++) {
		for (i = 20 - lines; i < 20; i++) {
			for (j = 1; j < 13; j++) {
				gotoxy(j * 2 + ab_x, i + ab_y);
				switch (phase) {
				case 0: SetColor(YELLOW); cout << "●"; break;
				case 1: SetColor(RED); cout << "◈"; break;
				case 2: SetColor(DARK_RED); cout << "■"; break;
				}
			}
		}
		Sleep(100); // 깜빡임 간격
	}
	// 데이터 이동 처리 (아래쪽부터 위로 올려붙이기)
	for (i = 19; i >= lines; i--) {
		for (j = 1; j < 13; j++) {
			total_block[i][j] = total_block[i - lines][j];
		}
	}

	// 최상단 lines줄 초기화
	for (i = 0; i < lines; i++) {
		for (j = 1; j < 13; j++) {
			total_block[i][j].occupied = 0;
			total_block[i][j].color = 0;
			total_block[i][j].count = 0;
		}
	}
	Renderer::show_total_block(level);
}