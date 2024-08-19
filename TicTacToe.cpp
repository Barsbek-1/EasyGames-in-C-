// Tic Tac Toe 
// ПК играет в Крестики нолики против пользователя 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 

using namespace std; 
// Глобальные константы 

const char X = 'X'; 
const char O = 'O'; 
const char EMPTY = ' '; 
const char TIE = 'T'; 
const char NO_ONE = 'N'; 

//Прототипы функций 
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0); 
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int movee);
int humanMove(const vector<char>& board, char human); 
int computerMove(vector<char> board, char computer); 
void announceWinner(char winner, char computer, char human); 

//Фукнция main 
int main()
{
	int movee; 
	const int NUM_SQUARES = 9; 
	vector<char> board(NUM_SQUARES , EMPTY); 
	instructions();
	char human = humanPiece();
	char computer = opponent(human); 
	char turn = X; 
	displayBoard(board); 
	while (winner(board) == NO_ONE)
	{
		if(turn == human)
		{
			movee = humanMove(board , human); 
			board[movee] = human; 
		}
		else 
		{
			movee = computerMove(board , computer); 
			board[movee] = computer; 
		}
		displayBoard(board); 
		turn = opponent(turn); 
	}
	announceWinner(winner(board), computer, human);
	return 0; 
}

void instructions()
{
	cout << " Welcome to the ultimate man-machine showdown: TIC-TAC-TOE.\n";
	cout << " --where human brain is pit against silicon processor\n\n"; 
	cout << " Make your move known by entering a number, 0 - 8. The number\n";
	cout << " corresponds to the desired board position, as illustrated:\n\n"; 
	cout << " 0 | 1 | 2\n "; 
	cout << " 3 | 4 | 5\n "; 
	cout << " 6 | 7 | 8\n\n";
	cout << " Prepare yourself , human. The battle is about to begin. \n\n"; 
}

char askYesNo(string question)
{
	char response; 
	do
	{
		cout << question << " (y/n): "; 
		cin >> response; 
	}
	while (response != 'y' && response != 'n');
	return response; 
}

int askNumber(string question, int high, int low)
{
	int number; 
	do
	{
		cout << question << " ( " << low << " _ " << high << "): ";
		cin >> number; 
	}
	while (number > high || number < low); 
	return number; 
}

char humanPiece()
{
	char go_first = askYesNo("Do you require the first move?"); 
	if (go_first == 'y')
	{
		cout << "\n Then take first move. You will need it. \n"; 
		return X; 
	}
	else 
	{
		cout << "\n Your bravely will be your undoing... I will go first. \n"; 
		return O; 
	}
}

char opponent(char piece)
{
	if (piece == X)
	{
		return O; 
	}
	else 
	{
		return X; 
	}
}
void displayBoard(const vector<char>& board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2]; 
	cout << "\n\t" << "---------"; 
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5]; 
	cout << "\n\t" << "---------"; 
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8]; 
	cout << "\n\t"; 
}

char winner(const vector<char>& board)
{
	// все возможные выигрышные ряды
	const int WINNING_ROWS[8][3] = { {0, 1, 2},
		{3, 4, 5}, 
		{6, 7, 8}, 
		{0, 3, 6}, 
		{1, 4, 7}, 
		{2, 5, 8}, 
		{0, 4, 8}, 
		{2, 4, 6} }; 

	const int TOTAL_ROWS = 8; 

	// если в одном из выйгрышных рядов уже присутствуют три одинаковых значения 
	// (причем они не не равны EMPTY), то победитель определился
	for(int row = 0; row < TOTAL_ROWS; ++row)
	{
		if ( (board[WINNING_ROWS[row][0]] != EMPTY) && 
		(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) && 
		(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )
		{
			return board[WINNING_ROWS[row][0]]; 
		}
	}

	// поскольку победитель не определился , проверяем , не наступила ли ничья
	// (остались ли а поле пустые клетки) 
	if (count (board.begin(), board.end(), EMPTY) == 0)
		return TIE;
	// полскольку победитель не определился, но и ничья еще не наступила , 
	// игра продолжается 
		return NO_ONE; 
}

inline bool isLegal(int movee, const vector<char>& board)
{
	return(board[movee] == EMPTY); 
}

int humanMove(const vector<char>& board, char human)
{
	int movee = askNumber(" Where will you move?" , (board.size() - 1)); 
	while(!isLegal(movee, board))
	{
		cout << "\n That square is already occupied, foolish human.\n"; 
		movee = askNumber(" Where will you move?" , (board.size() - 1)); 
	}
	cout << " Fine...\n";
	return movee; 
}

int computerMove(vector<char> board, char computer)
{
	unsigned int movee = 0; 
	bool found = false; 
	// если пк может выйграть следующим ходом , то он делает этот ход 
	while(!found && movee < board.size())
	{
		if(isLegal(movee, board))
		{
			board[movee] = computer; 
			found = winner(board) == computer; 
			board[movee] = EMPTY; 
		}
		if(!found)
		{
			++movee; 
		}
	}
	// иначе , если человек может победить следующим ходом , блокировать этот код 
	if(!found)
	{
		movee = 0; 
		char human = opponent(computer); 
		while(!found && movee<board.size())
		{
			if(isLegal(movee, board))
			{
				board[movee] = human; 
				found = winner(board) == human; 
				board[movee] = EMPTY; 
			}
			if (!found)
			{
				++movee;
			}
		}
	}
	//иначе занять следующим ходом оптимальную свободную клетку
	if(!found)
	{
		movee = 0; 
		unsigned int i = 0; 
		const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7}; 
		// выбрать оптимальную свободную клетку 
		while (!found && i < board.size())
		{
			movee = BEST_MOVES[i]; 
			if (isLegal(movee, board))
			{
				found = true; 
			}
			++i; 
		}
	}
	cout << " I shall take square number " << movee << endl; 
	return movee; 
}

void announceWinner(char winner, char computer, char human)
{
	if(winner == computer)
	{
		cout << winner << "'s won!\n "; 
		cout << " As I predicted, human, I am triumphat once more -- proof\n";
		cout << " that computers are superior to humans in all regards.\n"; 
	}
	else if(winner == human)
	{
		cout << winner << "'s won!\n ";
		cout << " No, no! It cannot be! Somehow you tricked me, human.\n"; 
		cout << " But ever again! I, the computer, so swear it!\n";
	}
	else 
	{
		cout << " It's a tie.\n"; 
		cout << " You were most lucky, human, and somehow managed to tie me.\n";
		cout << " Celebrate... for this is the best you will ever achive.\n"; 
	}
}

