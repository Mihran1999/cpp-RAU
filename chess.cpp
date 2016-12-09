// Created with Love. M. D. A.

#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<char> vector;
typedef std::vector<vector> matrix;
typedef std::pair<int, int> iCoord;
typedef std::pair<char, int> chCoord;

matrix generate_table();
bool black_step(const matrix&, chCoord);
bool white_step(const matrix&, chCoord);
bool is_empty(const matrix&, chCoord);
bool check_pawn_step(const matrix&, chCoord, chCoord);
bool check_knight_step(const matrix&, chCoord, chCoord);
bool check_rook_step(const matrix&, chCoord, chCoord);
std::pair<iCoord, iCoord> get_coords(chCoord, chCoord);

int main()
{
	matrix board = generate_table();
	board[2][1] = 'P';
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			std::cout << board[i][j] << ' ';
		std::cout << std::endl;
	}

	chCoord a,b;
	std::cin >> a.first >> a.second >> b.first >> b.second;
	if (check_knight_step(board, a, b))
		std::cout << 1;

}

matrix generate_table()
{
	matrix board(9, vector(9, '@'));	// @ - is white
	for (int i = 1; i < 9; ++i)
		board[8][i] = i + 'a' - 1;
	for (int i = 7; i >= 0; --i)
		board[i][0] = 8 - i + '0';

	board[8][0] = ' ';
	for (int i = 0; i < 8; ++i)
		for (int j = 1; j < 9; ++j)
			if ((i + j) % 2 == 0)		// black is even
				board[i][j] = ' ';

	for (int i = 1; i < 9; ++i)
		board[1][i] = 'p';				// 'p' - black pawn
	for (int i = 1; i < 9; ++i)
		board[6][i] = 'P';				// 'P' - white pawn

	board[0][1] = board[0][8] = 'r';	// 'r' - black rook
	board[7][1] = board[7][8] = 'R';	// 'R' - white rook

	board[0][2] = board[0][7] = 'h';	// 'h' - black knight
	board[7][2] = board[7][7] = 'H';	// 'H' - white knight

	board[0][3] = board[0][6] = 'b';	// 'b' - black bishop
	board[7][3] = board[7][6] = 'B';	// 'B' - white bishop

	board[0][4] = 'q';					// 'q' - black queen
	board[7][4] = 'Q';					// 'Q' - white queen

	board[0][5] = 'k';					// 'k' - black king
	board[7][5] = 'K';					// 'K' - white king

	return board;
}

bool white_step(const matrix& board, chCoord coords)		//true - if no white
{
	int i, j;														
	j = coords.first - 'a' + 1;
	i = 8 - coords.second;

	return (board[i][j] != 'P' && board[i][j] != 'R' && board[i][j] != 'H' &&
		board[i][j] != 'B' && board[i][j] != 'Q' && board[i][j] != 'K');
}

bool black_step(const matrix& board, chCoord coords)		//true - if no black
{
	int i, j;
	j = coords.first - 'a' + 1;
	i = 8 - coords.second;

	return (board[i][j] != 'p' && board[i][j] != 'r' && board[i][j] != 'h' &&
		board[i][j] != 'b' && board[i][j] != 'q' && board[i][j] != 'k');
}

bool is_empty(const matrix& board, chCoord coords)			//is no figure
{
	return(white_step(board, coords) && black_step(board, coords));
}

bool out_of_range(int i1, int i2, int j1, int j2)
{
	if (i1 > 7 || i1 < 0 || i2 > 7 || i2 < 0 || j1 < 1 || j1 > 8 || j2 < 1 || j2 > 8)
		return true;
	return false;
}

bool check_pawn_step(const matrix& board, chCoord begin, chCoord end)
{
	std::pair<iCoord, iCoord> p = get_coords(begin, end);
	int i1 = p.first.first, j1 = p.first.second, i2 = p.second.first, j2 = p.second.second;

	if (out_of_range(i1, i2, j1, j2))
		return false;

	if (board[i1][j1] == 'P')		//white
	{
		if (j1 == j2 && is_empty(board, end) && ((i1 == 6 && i1 - i2 == 2) || i1 - i2 == 1))	//go forward
			return true;
		if (i1 - i2 == 1 && white_step(board, end) && std::abs(j1 - j2) == 1)			//eat
			return true;
	}
	else if (board[i1][j1] == 'p')		//black
	{
		if (j1 == j2 && is_empty(board, end) && ((i1 == 1 && i2 - i1 == 2) || i2 - i1 == 1))	//go forward
			return true;
		if (i2 - i1 == 1 && black_step(board, end) && std::abs(j1 - j2) == 1)			//eat
			return true;
	}
	return false;
}

bool check_knight_step(const matrix& board, chCoord begin, chCoord end)
{
	std::pair<iCoord, iCoord> p = get_coords(begin, end);
	int i1 = p.first.first, j1 = p.first.second, i2 = p.second.first, j2 = p.second.second;

	if (board[i1][j1] == 'H' &&					// white horse move and eat
		(!out_of_range(i1, i2, j1, j2) &&
		((std::abs(i1 - i2) == 1 && std::abs(j1 - j2) == 2) || (std::abs(i1 - i2) == 2 && std::abs(j1 - j2) == 1)) &&
			white_step(board, end)))
		return true;
	else if (board[i1][j1] == 'h' &&			// black horse move and eat
		(!out_of_range(i1, i2, j1, j2) && 
		((std::abs(i1 - i2) == 1 && std::abs(j1 - j2) == 2) || (std::abs(i1 - i2) == 2 && std::abs(j1 - j2) == 1)) &&
			black_step(board, end)))
		return true;
	return false;
}

bool check_rook_step(const matrix& board, chCoord begin, chCoord end)
{
	std::pair<iCoord, iCoord> p = get_coords(begin, end);
	int i1 = p.first.first, j1 = p.first.second, i2 = p.second.first, j2 = p.second.second;

	if(board[i1][j1] == 'R' && !out_of_range(i1, i2, j1, j2))
	{
		//grel for vor@ kstugi sagh togh kam syun@
	}
	else if(board[i1][j1] == 'r')		//Black Rook Step
	{

	}
	return false;
}

std::pair<iCoord, iCoord> get_coords(chCoord begin, chCoord end)
{
	iCoord p1, p2;
	p1.first = begin.first - 'a' + 1;
	p1.second = 8 - begin.second;
	p2.first = end.first - 'a' + 1;
	p2.second = 8 - end.second;
	return std::make_pair(p1, p2);
}