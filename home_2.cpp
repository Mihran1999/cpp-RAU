#include <iostream>
#include <vector>

typedef std::vector<char> vector;
typedef std::vector<vector> matrix;

matrix generate_table();

int main()
{
	matrix board = generate_table();
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
			std::cout << board[i][j] << ' ';
		std::cout << std::endl;
	}
}

matrix generate_table()
{
	matrix board(9, vector(9,176));
	for(int i = 1; i < 9; ++i)
		board[8][i] = i + 'a' - 1;
	for(int i = 7; i >= 0; --i)
		board[i][0] = 8 - i + '0';

	board[8][0] = ' ';
	for(int i = 0; i < 8; ++i)
		for(int j = 1; j < 9; ++j)
			if((i + j) % 2 == 0)		// black is even
				board[i][j] = ' ';

	for(int i = 1; i < 9; ++i)
		board[1][i] = 174;				// 42 - black pawn
	for(int i = 1; i < 9; ++i)
		board[6][i] = 253;				// 253 - white pawn

	board[0][1] = board[0][8] = 208;	// 208 - black rook
	board[7][1] = board[7][8] = 210;	// 210 - white rook

	board[0][2] = board[0][7] = 192;	// 192 - black knight
	board[7][2] = board[7][7] = 201;	// 201 - white knight

	board[0][3] = board[0][6] = 209;	// 209 - black bishop
	board[7][3] = board[7][6] = 207;	// 207 - white bishop

	board[0][4] = 216;					// 216 - black queen
	board[7][4] = 206;					// 206 - white queen

	board[0][5] = 181;					// 181 - black king
	board[7][5] = 204;					// 204 - white king

	return board;
}