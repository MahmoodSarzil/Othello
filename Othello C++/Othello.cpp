/****************|****************|***************
Program: Othello.cpp
Mahmood Sarzil

*****************|****************|***************/

#include <iostream>
#include <windows.h>
#include <fstream>
#include<conio.h>
using namespace std;

const int ROWS = 8;
const int COLS = 8;

const char player_1	= 'X';
const char player_2 = 'O';

//Function to Display board
void DisplayBoard(const char board[][COLS])
{
	cout << "\t ";
	for (int a = 0; a < COLS; a++)
		cout <<"  "<< a;
	    cout << endl;
        cout<<"\t +--+--+--+--+--+--+--+--+\n";
    //====================================================
    fstream fr;
    fr.open("game.txt",ios::in|ios::out|ios::app);
    fr << "\t";
    for (int c=0; c < COLS; c++)
        fr <<"  "<< c;
	    fr << endl;
        fr<<"\t +--+--+--+--+--+--+--+--+\n";
    for (int r = 0; r < ROWS; r++)
	{
		fr <<"\t"<< r ;
		for (int c = 0; c < COLS; c++)
			fr <<"| "<< board[r][c];
			fr<<"|";
		fr << endl;
        fr<<"\t +--+--+--+--+--+--+--+--+\n";
	}
	for (int r = 0; r < ROWS; r++)
	{
		cout <<"\t"<< r ;
		for (int c = 0; c < COLS; c++)
			cout <<"| "<< board[r][c];
			cout<<"|";
		cout << endl;
        cout<<"\t +--+--+--+--+--+--+--+--+\n";
	}

}
//Function to place disc
int PlaceDisc(char board[][COLS], int row, int col, char disc)
{
	int num_changed = 0;

	if (board[row][col] != ' ')
		return 0;

	board[row][col] = disc;

	char envious_disc;
	if (disc == player_1)
		envious_disc = player_2;
	else
		envious_disc = player_1;

	int disc_pos = -1;
	for (int c = col + 1; c < COLS && board[row][c] != ' ' && disc_pos == -1; c++)
	{
		if (board[row][c] == disc)
			disc_pos = c;
	}

	if (disc_pos != -1 && disc_pos > col + 1)
	{
		for (int c = col + 1; c < disc_pos; c++)
		{
			board[row][c] = disc;
			num_changed++;
		}
	}

	disc_pos = -1;
	for (int c = col - 1; c >= 0 && board[row][c] != ' ' && disc_pos == -1; c--)
	{
		if (board[row][c] == disc)
			disc_pos = c;
	}

	if (disc_pos != -1 && disc_pos < col - 1)
	{
		for (int c = col - 1; c > disc_pos; c--)
		{
			board[row][c] = disc;
			num_changed++;
		}
	}

	disc_pos = -1;
	for (int r = row - 1; r >= 0 && board[r][col] != ' ' && disc_pos == -1; r--)
	{
		if (board[r][col] == disc)
			disc_pos = r;
	}

	if (disc_pos != -1 && disc_pos < row - 1)
	{
		for (int r = row - 1; r > disc_pos; r--)
		{
			board[r][col] = disc;
			num_changed++;
		}
	}

	disc_pos = -1;
	for (int r = row + 1; r < ROWS && board[r][col] != ' ' && disc_pos == -1; r++)
	{
		if (board[r][col] == disc)
			disc_pos = r;
	}

	if (disc_pos != -1 && disc_pos > row + 1)
	{
		for (int r = row + 1; r < disc_pos; r++)
		{
			board[r][col] = disc;
			num_changed++;
		}
	}

	disc_pos = -1;
	int c = col - 1;
	for (int r = row - 1; c >= 0 && r >= 0 && board[r][c] != ' ' && disc_pos == -1; r--)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c--;
	}

	if (disc_pos != -1 && disc_pos < row - 1)
	{
		c = col - 1;
		for (int r = row - 1; r > disc_pos; r--)
		{
			board[r][c] = disc;
			num_changed++;
			c--;
		}
	}

	disc_pos = -1;
	c = col + 1;
	for (int r = row - 1; c < COLS && r >= 0 && board[r][c] != ' ' && disc_pos == -1; r--)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c++;
	}

	if (disc_pos != -1 && disc_pos < row - 1)
	{
		c = col + 1;
		for (int r = row - 1; r > disc_pos; r--)
		{
			board[r][c] = disc;
			num_changed++;
			c++;
		}
	}

	disc_pos = -1;
	c = col - 1;
	for (int r = row + 1; c >= 0 && r < ROWS && board[r][c] != ' ' && disc_pos == -1; r++)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c--;
	}

	if (disc_pos != -1 && disc_pos > row + 1)
	{
		c = col - 1;
		for (int r = row + 1; r < disc_pos; r++)
		{
			board[r][c] = disc;
			num_changed++;
			c--;
		}
	}

	disc_pos = -1;
	c = col + 1;
	for (int r = row + 1; c < COLS && r < ROWS && board[r][c] != ' ' && disc_pos == -1; r++)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c++;
	}

	if (disc_pos != -1 && disc_pos > row + 1)
	{
		c = col + 1;
		for (int r = row + 1; r < disc_pos; r++)
		{
			board[r][c] = disc;
			num_changed++;
			c++;
		}
	}

	if (num_changed == 0)
		board[row][col] = ' ';

	return num_changed;
}

//Function to determine possible moves
int MoveIsPossible(const char board[][COLS], char player)
{
	return 1;
}

//Class for game logics
class GAME{
public:
    int row,col,discs_changed;
    bool invalid_move;

public:
    void Player_1_Move(char board[][COLS])
    {
        fstream fr;
        fr.open("game.txt",ios::in|ios::out|ios::app);

        if (MoveIsPossible(board, player_1))
            {
		do
		{
			invalid_move = false;

			cout << "Enter Row : ";
			fr << "Enter Row : ";
			cin >> row ;
			fr << row <<endl;
			while (row < 0 || row >= ROWS)
			{
				cout << "Please enter a row between 0 and " << (ROWS - 1) << ".\n";
				fr << "Please enter a row between 0 and " << (ROWS - 1) << ".\n";
				cout << "Enter Row : ";
				fr << "Enter Row : ";
				cin >> row;
				fr << row <<endl;
			}

			cout << "Enter Collum : ";
			fr << "Enter Collum : ";
			cin >> col;
			fr<< col <<endl;
			while (col < 0 || col >= COLS)
			{
				cout << "Please enter a column between 0 and " << (COLS - 1) << ".\n";
				fr << "Please enter a column between 0 and " << (COLS - 1) << ".\n";
				cout << "Enter Collum : ";
				fr << "Enter Collum : ";
				cin >> col;
				fr<< col <<endl;
			}

			if (board[row][col] != ' ')
			{
				cout << "Please enter an empty row and column.\n";
				fr << "Please enter an empty row and column.\n";
				invalid_move = 1;
			}
			else
			{
				discs_changed = PlaceDisc(board, row, col, player_1);
				if (discs_changed == 0)
				{
					cout << "Invalid move.\n";
                    fr << "Invalid move.\n";
					invalid_move = true;
				}
				else
					cout << "===Changed " << discs_changed << " disc.===\n\n";
					fr << "===Changed " << discs_changed << " disc.===\n\n";
            }
		} while (invalid_move);
	}
	else
	{
		cout << "X cannot move.\n";
		fr << "X cannot move.\n";
	}
}

//Saving board (Tried Hard couldn't make it work

void SaveBoard(char board[][COLS], char temp_board[][COLS])
{

	for( int i = 0; i < ROWS; i++)
	{
		for(int j =0; j < COLS; j++)
			temp_board[i][j]= board[i][j];
	}
}

void Player_2_Move(char board[][COLS])
{
        fstream fr;
        fr.open("game.txt",ios::in|ios::out|ios::app);

        if (MoveIsPossible(board, player_2))
            {
		do
		{
			invalid_move = false;

			cout << "Enter Row : ";
			fr << "Enter Row : ";
			cin >> row ;
			fr << row <<endl;
			while (row < 0 || row >= ROWS)
			{
				cout << "Please enter a row between 0 and " << (ROWS - 1) << ".\n";
				fr << "Please enter a row between 0 and " << (ROWS - 1) << ".\n";
				cout << "Enter Row : ";
				fr << "Enter Row : ";
				cin >> row;
				fr << row <<endl;
			}

			cout << "Enter Collum : ";
			fr << "Enter Collum : ";
			cin >> col;
			fr<< col <<endl;
			while (col < 0 || col >= COLS)
			{
				cout << "Please enter a column between 0 and " << (COLS - 1) << ".\n";
                fr << "Please enter a column between 0 and " << (COLS - 1) << ".\n";
				cout << "Enter Collum : ";
				fr << "Enter Collum : ";
				cin >> col;
				fr<< col <<endl;
			}

			if (board[row][col] != ' ')
			{
				cout << "Please enter an empty row and column.\n";
				fr << "Please enter an empty row and column.\n";
				invalid_move = 1;
			}
			else
			{
				discs_changed = PlaceDisc(board, row, col, player_2);
				if (discs_changed == 0)
				{
					cout << "Invalid move.\n";
                    fr << "Invalid move.\n";
					invalid_move = true;
				}
				else
					cout << "===Changed " << discs_changed << " disc.===\n\n";
					fr << "===Changed " << discs_changed << " disc.===\n\n";
            }
		} while (invalid_move);
	}
	else
	{
		cout << "O cannot move.\n";
		fr << "O cannot move.\n";
	}
}

//Function for starting a new game

void new_game()
{
    fstream fr;
    fr.open("game.txt",ios::in|ios::out|ios::app);
    int x=2,o=2;
	char board[ROWS][COLS];
	cout <<"\n\n\t     *** NEW GAME ***"<<endl<<endl;
	fr <<"\n\n\t     *** NEW GAME ***"<<endl<<endl;
	strncpy(board[0],"        ", COLS);
	strncpy(board[1],"        ", COLS);
	strncpy(board[2],"        ", COLS);
	strncpy(board[3],"   OX   ", COLS);
	strncpy(board[4],"   XO   ", COLS);
	strncpy(board[5],"        ", COLS);
	strncpy(board[6],"        ", COLS);
	strncpy(board[7],"        ", COLS);

	DisplayBoard(board);
    cout<<endl<<"========================================"<<endl;
	cout << endl;
	fr <<endl<<"========================================"<<endl;
	fr << endl;
    char ch;
	for(int i=1;i<=64;i++){
    cout<<"SCORE:\t O = "<<o<<",  X = "<<x<<endl;
    fr <<"SCORE:\t O = "<<o<<",  X = "<<x<<endl;

    if((i%2)!=0){
    cout << "Current Player:  X\n"<<endl;
    fr << "Current Player:  X\n"<<endl;

    cout << "Super power 1 = a"<<endl;
    cout << "super power 2 = b"<<endl;
    cout << "Any Key for Game Continue..."<<endl;
    cin >> ch;

    fr << "Super power 1 = a"<<endl;
    fr << "super power 2 = b"<<endl;
    fr << "Any Key for Game Continue..."<<endl;
    fr << ch <<endl;

     if(ch=='a'){
        if((x>2)&&(o>=2)){}
        else{
        cout <<"You get to put two markers!"<<endl<<endl;
        fr <<"YOu get to put two markers"<<endl<<endl;
	    Player_1_Move(board);
        x+=discs_changed+1;
        o-=discs_changed;}
    }
    if (ch == 'b')
    {
        cout << "You Win!" <<endl;
        break;
    }
    else{

    Player_1_Move(board);

    x-=discs_changed;
    o+=discs_changed+1;}
    }

	else if((i%2)==0){
    cout << "Current Player:  O\n"<<endl;
    fr << "Current Player:  O\n"<<endl;

    cout << "Super power 1 = a"<<endl;
    cout << "super power 2 = b"<<endl;
    cout << "Any Key for Game Continue..."<<endl;
    cin >> ch;

    fr << "Super power 1 = a"<<endl;
    fr << "super power 2 = b"<<endl;
    fr << "Any Key for Game Continue..."<<endl;
    fr << ch <<endl;

    if(ch=='a'){
        if((x<2)&&(o<2)){}
        else{
        cout <<"You get to put two markers!"<<endl<<endl;
        fr <<"YOu get to put two markers"<<endl<<endl;
	    Player_2_Move(board);
        x+=discs_changed+1;
        o-=discs_changed;}
    }
    if (ch == 'b')
    {
        cout << "You Win!" <<endl;
        break;
    }
    else{

    Player_2_Move(board);

    x-=discs_changed;
    o+=discs_changed+1;}
    }
    DisplayBoard(board);
    cout<<endl<<"========================================"<<endl;
	cout<<endl;
    fr <<endl<<"========================================"<<endl;
	fr <<endl;
	}
	if(x>o){
        cout<<"";
        fr <<"";}
    else if(x<o){
        cout<<"";
        fr <<"";}
    else{
        cout<<"";
        fr <<"";}
}

void new_game(int a,int b)
{
    fstream fr;
    int x=a,o=b;
    fr.open("game.txt",ios::in|ios::out|ios::app);
	char board[ROWS][COLS];
	load_game();
    char ch;
	for(int i=1;i<=64;i++){
    cout<<"SCORE:\t O = "<<o<<",  X = "<<x<<endl;
    fr <<"SCORE:\t O = "<<o<<",  X = "<<x<<endl;
    DisplayBoard(board);
    if((i%2)!=0){
    cout << "Current Player:  X\n"<<endl;
    fr << "Current Player:  X\n"<<endl;

    cout << "Super power 1 = a"<<endl;
    cout << "super power 2 = b"<<endl;
    cout << "Any Key for Game Continue..."<<endl;
    cin >> ch;

    fr << "Super power 1 = a"<<endl;
    fr << "super power 2 = b"<<endl;
    fr << "Any Key for Game Continue..."<<endl;
    fr << ch <<endl;

    if((ch=='a')||(ch=='b')){
        if((x>=2)&&(o>=2)){}
        else{
        cout <<"Sorry You can't proceed to next player"<<endl<<endl;
        fr <<"Sorry You can't proceed to next player"<<endl<<endl;
	    Player_1_Move(board);
        x+=discs_changed+1;
        o-=discs_changed;}
    }
    else{

	Player_1_Move(board);

    x+=discs_changed+1;
    o-=discs_changed;}
    }

	else if((i%2)==0){
    cout << "Current Player:  O\n"<<endl;
    fr << "Current Player:  O\n"<<endl;

    cout << "Super power 1 = a"<<endl;
    cout << "super power 2 = b"<<endl;
    cout << "Any Key for Game Continue..."<<endl;
    cin >> ch;

    fr << "Super power 1 = a"<<endl;
    fr << "super power 2 = b"<<endl;
    fr << "Any Key for Game Continue..."<<endl;
    fr << ch <<endl;

    if((ch=='a')||(ch=='b')){
         if((x>=2)&&(o>=2)){}
         else{
         cout <<"Sorry You can't proceed to next player"<<endl<<endl;
         fr <<"Sorry You can't proceed to next player"<<endl<<endl;
         Player_2_Move(board);
         x-=discs_changed;
         o+=discs_changed+1;}
    }
    else{

    Player_2_Move(board);

    x-=discs_changed;
    o+=discs_changed+1;}
    }
    DisplayBoard(board);
    cout<<endl<<"========================================"<<endl;
	cout<<endl;
    fr <<endl<<"========================================"<<endl;
	fr <<endl;
	}
	if(x>o){
        cout<<"\n\t*** PLAYER 1 WIN ***\n";
        fr <<"\n\t*** PLAYER 1 WIN ***\n";}
    else if(x<o){
        cout<<"\n\t*** PLAYER 2 WIN ***\n";
        fr <<"\n\t*** PLAYER 2 WIN ***\n";}
    else{
        cout<<"\n\t*** GAME DRAWN ***\n";
        fr <<"\n\t*** GAME DRAWN ***\n";}
}

//Function for loading game (Tried hard Couldn't work

void load_game()
{
    char board[ROWS][COLS];
    char ch;
    ifstream fs("game.txt",ios::in);

    ch=fs.get();
    while(fs)

    {
        cout << ch;
        ch=fs.get();
    }

    fs.close();
    getch();
}

};

//Function for Help

void help()
{
    cout << "How to play the game" << endl;
        cout << "****************" << endl;
        cout << "1. 'x' always moves first." << endl;
        cout << "2. If on your turn you cannot outflank and flip at least one opposing"<<endl;
        cout << "space your turn is forfeited and your opponent moves again."<<endl;
        cout << " However, if a move is available to you, you may not forfeit your turn." << endl;
        cout << "3. A space may outflank any number of spaces in one or more rows"<<endl;
        cout << "in any number of directions at the same time horizontally,vertically/diagonally."<<endl;
        cout << "(A row is defined as one or more spaces in a continuous straight line )." << endl;
        cout << "4. You may not skip over your own declared space to outflank an opposing space." << endl;
        cout << "5. Spaces may only be outflanked as a direct result of a move and must fall " << endl;
        cout << "in the direct line of the space placed down."<<endl;
        cout << "6. When it is no longer possible for either player to move, the game is over."<<endl;
        cout << "Spaces are counted and the player with the majority " << endl;
        cout << "of his or her declared spaces on the board is the winner."<<endl;
}

/****************************************************************************/

//Main Function
int main()
{
    cout<<endl;
    cout << ".d88b.    88888    8   8    8888    8       8       .d88b." <<endl;
    cout << "8P  Y8      8      8www8    8www    8       8       8P  Y8" <<endl;
    cout << "8b  d8      8      8   8    8       8       8       8b  d8" <<endl;
    cout << "`Y88P'      8      8   8    8888    8888    8888    `Y88P'" <<endl;
    cout << "                                         by MAHMOOD SARZIL" <<endl;

    // Main Menu
    GAME G;
    int ip;
    cout << "\n1. New Game" << endl;
    cout << "2. Help" << endl;
    cout << "3. Load Game"<<endl;
    cout << "4. Quit" << endl;
    cin >> ip;

    switch (ip)
    {
        case 1 : G.new_game();
        break;
        case 2 : help();
                 main();
        case 3 : G.load_game();
        case 4 : break;
        default : main();
    }
}

