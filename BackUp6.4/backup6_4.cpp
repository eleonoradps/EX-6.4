#include <iostream>
#include <algorithm>
#include <vector>

void GenerateMap(std::vector<char>& board)
{
	const int SizeBoard = 9;

	board.resize(SizeBoard);

	for (int i = 0; i < SizeBoard; i++)
	{
		board[i] = ' ';
	}

	std::cout << "Welcome to Tic Tac Toe Game \n\n\n";
	std::cout << "Make your move by entering a number between 0 and 8 \n\n\n";
	std::cout << "\t 0 | 1 | 2 \n";
	std::cout << "\t ---------- \n";
	std::cout << "\t 3 | 4 | 5 \n";
	std::cout << "\t ---------- \n";
	std::cout << "\t 6 | 7 | 8 \n";

}

void ShowMap(std::vector<char>& board)
{
	std::cout << "\n\n";

	std::cout << "\t" << board[0] << " | " << board[1] << " | " << board[2] << "\n";
	std::cout << "\t---------- \n";
	std::cout << "\t" << board[3] << " | " << board[4] << " | " << board[5] << "\n";
	std::cout << "\t---------- \n";
	std::cout << "\t" << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

void SetNewPosition(std::vector<char>& board, char player)
{
	int IndexBoard = 0;
	bool EmptyCase = false;

	while (!EmptyCase)
	{
		std::cout << "Player make a move \n";
		std::cin >> IndexBoard;

		if (board[IndexBoard] != ' ')
		{
			std::cout << "This case is already occupied \n";
		}
		else
		{
			board[IndexBoard] = player;
			EmptyCase = true;
		}
	}
}

void CheckWin(std::vector<char>& board, char player, bool& winner)
{
	int BoardFull = 0;

	bool winningRow = (board[0] == player && board[1] == player && board[2] == player)
		|| (board[3] == player && board[4] == player && board[5] == player)
		|| (board[6] == player && board[7] == player && board[8] == player);

	bool winningColumn = (board[0] == player && board[3] == player && board[6] == player)
		|| (board[1] == player && board[4] == player && board[7] == player)
		|| (board[2] == player && board[5] == player && board[8] == player);

	bool winningDiagonal = (board[0] == player && board[4] == player && board[8] == player)
		|| (board[2] == player && board[4] == player && board[6] == player);

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i] != ' ')
		{
			BoardFull++;
		}
	}

	if (BoardFull == board.size() && !(winningRow || winningColumn || winningDiagonal))
	{
		std::cout << "This is a tie \n";
		winner = true;
	}
	else if ((winningRow || winningColumn || winningDiagonal))
	{
		std::cout << "Player " << player << " wins \n";
		winner = true;
	}
}

void PlayGame(std::vector<char>& board)
{
	bool winner = false;

	ShowMap(board);

	while (!winner)
	{
		SetNewPosition(board, 'X');

		ShowMap(board);

		CheckWin(board, 'X', winner);

		if (!winner)
		{
			SetNewPosition(board, 'O');

			ShowMap(board);

			CheckWin(board, 'O', winner);
		}
	}
}

int main()
{
	std::vector<char>board;

	GenerateMap(board);

	PlayGame(board);

	system("pause");
	return EXIT_SUCCESS;
}