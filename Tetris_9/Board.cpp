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
    // ��ü ��� �迭�� 0���� �ʱ�ȭ
    std::memset(total_block, 0, sizeof(total_block));

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // �� ����
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 14; ++j) {
            total_block[i][j].occupied = (j == 0 || j == 13) ? 1 : 0;
        }
    }

    // �ٴ� ����
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
		if (j == 13)	//������ �� ä������
		{
			// Yellow ��� ó���� ���� �ӽ� �迭
			Cell temp_row[14];
			bool has_remaining_yellow = false;

			// Yellow ��� ó�� �� ������ ����
			for (j = 1; j < 13; j++) {
				// Yellow ��� �ɷ��� Ȱ��ȭ�Ǿ� �ְ�, Yellow ����� ó�� �������� ��쿡�� Ư�� ó��
				if (stage_data[level].abilities.yellowBlockAbility &&
					total_block[i][j].color == YELLOW &&
					total_block[i][j].count == 0) {
					// Yellow ����� ó�� �������� ���
					temp_row[j] = total_block[i][j];
					temp_row[j].count = 1;  // ī��Ʈ ����
					has_remaining_yellow = true;
				}
				else {
					temp_row[j].occupied = 0;
					temp_row[j].color = total_block[i][j].color;
					temp_row[j].count = 0;
				}
			}

			// �ð��� ȿ�� ǥ�� (Yellow ����� ó�� �������� ���� ����)
			gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++) {
				if (!(temp_row[j].color == YELLOW && temp_row[j].count == 1)) {  // Yellow ����� ó�� �������� ��� ����
					SetColor(temp_row[j].color);
					cout << "��";
					SetColor(BLACK);
					cout << "��";
					Sleep(10);
				}
				else {
					SetColor(YELLOW);
					cout << "��";  // Yellow ��� ��ġ�� ����Ʈ ���� ��ĭ
					SetColor(BLACK);
					cout << "��";
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

			// ��� �̵� ó��
			if (has_remaining_yellow) {
				// Yellow ����� �ִ� ���, �� ������ ���������� ó��
				for (j = 1; j < 13; j++) {
					if (temp_row[j].color != YELLOW || temp_row[j].count != 1) {
						// Yellow ����� �ƴ� ��ġ�� ������ ��������
						for (k = i; k > 0; k--) {
							total_block[k][j] = total_block[k - 1][j];
						}
						// �ֻ�� �ʱ�ȭ
						total_block[0][j].occupied = 0;
						total_block[0][j].color = 0;
						total_block[0][j].count = 0;
					}
				}
				// Yellow ��� ����
				for (j = 1; j < 13; j++) {
					if (temp_row[j].color == YELLOW && temp_row[j].count == 1) {
						total_block[i][j] = temp_row[j];
					}
				}
				check_full_line(level, score, bomb);
			}
			else {
				// �Ϲ����� �� ���� ó��
				for (k = i; k > 0; k--) {
					for (j = 1; j < 13; j++) {
						total_block[k][j] = total_block[k - 1][j];
					}
				}
				// �ֻ�� �� �ʱ�ȭ
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
			if (stage_data[level].score <= score)	//Ŭ���� ���Ǵ޼�
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

			if ((block_dat == 1) && (block[b->getShape()][b->getAngle()][i][j] == 1))			//�������� ��ǥ�� ��������
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
				continue;  // ���� �ε����� �ǳʶݴϴ�
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


			if ((block_dat == 1) && (block[b->getShape()][rotateAngle][i][j] == 1))																							//�������� ��ǥ�� ��������
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

	b->setY(b->getY() + 1);   //���� ��ĭ �Ʒ��� ����


	if (strikeCheck(b) == true)
	{
		if (b->getY() < 0)   //���ӿ���
		{
			return 1;
		}
		b->setY(b->getY() - 1);
		mergeBlock(b);

		// ����� ������ ������ �ϴû� ��� üũ
		checkAndRemoveCyanBlocks(level);

		// --- �ɷ� �ߵ� ���� ---
		// ������ ����� �ɷ� ���� üũ �� �ɷ� �ߵ�
		if (b->check(*this, level)) {// check ������ ������
			b->active(*this); // active�� �ɷ� �ߵ�
			if (b->getColor() == RED) {
				score += 20;
				Renderer::show_gamestat(level, score, bomb);
				Sleep(20);
				if (stage_data[level].score <= score)	//Ŭ���� ���Ǵ޼�
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
		// �������� �۵��Ǵ��� Ȯ��
		if (stage_data[level].abilities.purpleBlockAbility) {
			PurpleBlock::update();
		}
		check_full_line(level, score, bomb);
		Renderer::show_total_block(level);

		

		for (int i = 1; i < 13; i++) { // 0�κа� 13�κ��� �׵θ��� �����ؾ���
			if (total_block[0][i].occupied == 1) {
				return 1;
			}
		}
		return 2;
	}
	return 0;
}


void Board::checkAndRemoveCyanBlocks(int& level) {
	// ���� ������������ �ϴû� ����� �ɷ��� ��Ȱ��ȭ�Ǿ� �ִٸ� false ��ȯ
	if (!stage_data[level].abilities.cyanBlockAbility) {
		return;
	}
	vector<pair<int, int>> cellsToRemove;

	// ������ ��� �ϴû� ��� Ȯ��
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

	// ī��Ʈ�� 5 �̻��� �ϴû� ��� ����
	for (const auto& [y, x] : cellsToRemove) {
		// �ð��� ȿ��
		SetColor(BLUE);
		gotoxy(x * 2 + ab_x, y + ab_y);
		cout << "��";
		Sleep(40);

		gotoxy(x * 2 + ab_x, y + ab_y);
		cout << "  ";
		Sleep(10);

		// �� ����
		total_block[y][x].occupied = 0;
		total_block[y][x].color = 0;
		total_block[y][x].count = 0;
	}

	//// ��������� ������ ȭ�� ����
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
				case 0: SetColor(YELLOW); cout << "��"; break;
				case 1: SetColor(RED); cout << "��"; break;
				case 2: SetColor(DARK_RED); cout << "��"; break;
				}
			}
		}
		Sleep(100); // ������ ����
	}
	// ������ �̵� ó�� (�Ʒ��ʺ��� ���� �÷����̱�)
	for (i = 19; i >= lines; i--) {
		for (j = 1; j < 13; j++) {
			total_block[i][j] = total_block[i - lines][j];
		}
	}

	// �ֻ�� lines�� �ʱ�ȭ
	for (i = 0; i < lines; i++) {
		for (j = 1; j < 13; j++) {
			total_block[i][j].occupied = 0;
			total_block[i][j].color = 0;
			total_block[i][j].count = 0;
		}
	}
	Renderer::show_total_block(level);
}