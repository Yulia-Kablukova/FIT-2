#include "GameView.h"

void GameView::startMessage()
{
	std::cout << "����� ����������!\n������� ���������� �������:" << std::endl;
}

void GameView::numberOfPlayersMessage()
{
	std::cout << "���� ��������� �� 1 ��� 2 ������!" << std::endl;
}

void GameView::getNumber(int player)
{
	std::cout << "�����" << player << ", ��������� �����: " << std::endl;
}

void GameView::badNumberMessage()
{
	std::cout << "������� ����� �� 4 ��������������� ����!" << std::endl;
}

void GameView::randomResultMessage(int player)
{
	std::cout << "�����" << player << " ����� ������!" << std::endl;
}

void GameView::requestAnswer(int player)
{
	std::cout << "\n�����" << player << ": " << std::endl;
}

void GameView::resultsMessage(int bulls, int cows)
{
	std::cout << "�����: " << bulls << ", �����: " << cows << std::endl;
}

void GameView::winMessage(int player)
{
	std::cout << "\n�����" << player << " �������!" << std::endl;
}
