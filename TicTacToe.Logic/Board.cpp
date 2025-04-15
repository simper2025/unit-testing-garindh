#include "pch.h"
#include "Board.h"


void Board::SetBoard(char setup[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] = setup[i][j];
		}
	}
}

char Board::GetSquare(int row, int col) const
{
	return grid[row][col];
}

bool Board::SetSquare(int row, int col, char player)
{
	if (grid[row][col] == ' ')
	{
		grid[row][col] = player;
		return true;
	}
	return false;
}

char Board::GameStatus()
{
	bool won = false;
	int numChars = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[i][j] != ' ')
			{
				numChars++;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (grid[0][i] != ' ' && grid[1][i] == grid[0][i] && grid[2][i] == grid[0][i])
		{
			won = true;
			return grid[0][i];
		}

		if (grid[i][0] != ' ' && grid[i][1] == grid[i][0] && grid[i][2] == grid[i][0])
		{
			won = true;
			return grid[i][0];
		}

	}

	if (numChars == 9 && !won)
	{
		return 'T';
	}
	else
	{
		return ' ';
	}
}

