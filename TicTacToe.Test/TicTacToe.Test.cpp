#include "pch.h"
#include "CppUnitTest.h"
#include "../TicTacToe.Logic/Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToeTest
{
	TEST_CLASS(TicTacToeTest)
	{
	public:

		TEST_METHOD(TestTrue)
		{
			Assert::AreEqual(true, true);
		}

		TEST_METHOD(TestSetSquare)
		{
			//Arrange
			Board b;
			
			//Act
			b.SetSquare(0, 0, 'X');

			//Assert
			Assert::AreEqual('X', b.GetSquare(0,0));
		}

		TEST_METHOD(TestSetTwoSquares)
		{
			//Arrange
			Board b;

			//Act
			b.SetSquare(0, 0, 'X');
			b.SetSquare(1, 1, 'O');

			//Assert
			Assert::AreEqual('X', b.GetSquare(0, 0));
			Assert::AreEqual('O', b.GetSquare(1, 1));
		}

		TEST_METHOD(TestBoardCreate)
		{
			Board b;
			char setup[3][3] = { {'X',' ',' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GetSquare(0, 0));
		}

		TEST_METHOD(TestGameStatusInProgress)
		{
			Board b;
			char setup[3][3] = { {'X',' ','O'}, {' ', 'O', ' '}, {' ', 'X', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual(' ', b.GameStatus());
		}

		TEST_METHOD(TestGameStatusInProgressTwo)
		{
			Board b;
			char setup[3][3] = { {'X','O','X'}, {'O', 'X', 'O'}, {'O', 'O', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual(' ', b.GameStatus());
		}

		TEST_METHOD(TestGameStatusTie)
		{
			Board b;
			char setup[3][3] = { {'X','X','O'}, {'O', 'O', 'X'}, {'X', 'X', 'O'} };
			b.SetBoard(setup);
			Assert::AreEqual('T', b.GameStatus());
		}

		TEST_METHOD(TestGameStatusVerticalWIn)
		{
			Board b;
			char setup[3][3] = { {'X',' ',' '}, {'X', ' ', ' '}, {'X', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GameStatus());
		}

		TEST_METHOD(TestGameStatusVerticalWinTwo)
		{
			Board b;
			char setup[3][3] = { {' ','O',' '}, {' ', 'O', ' '}, {' ', 'O', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('O', b.GameStatus());
		}

		TEST_METHOD(TestGameStatusHorizontalWin)
		{
			Board b;
			char setup[3][3] = { {'O','O','O'}, {' ', ' ', ' '}, {' ', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('O', b.GameStatus());
		}

		TEST_METHOD(TestGameStatusHorizontalWinTwo)
		{
			Board b;
			char setup[3][3] = { {' ',' ',' '}, {'X', 'X', 'X'}, {' ', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GameStatus());
		}

		TEST_METHOD(TestGameStatusDiagonalLRWin)
		{
			Board b;
			char setup[3][3] = { {'X',' ',' '}, {' ', 'X', ' '}, {' ', ' ', 'X'} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GameStatus());
		}

		TEST_METHOD(TestGameStatusDiagonalRLWin)
		{
			Board b;
			char setup[3][3] = { {' ',' ','O'}, {' ', 'O', ' '}, {'O', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('O', b.GameStatus());
		}
	};
}
