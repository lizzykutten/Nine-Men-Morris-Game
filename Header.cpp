#pragma once

#include "Header.h"

Board::Board() {
    int i, j, k = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            //spaces
            if ((j % 2 == 1) && (j != 0))
                board[i][j] = ' ';
            //avoids center attempt
            else if (i == row / 2 && j == column / 2)
                board[i][j] = '-';
            

            else if ((i * 2 == j) || (j == column / 2) || (i == row / 2) || (i + j == (column - (i + 1)))){
                board[i][j] = 'O';

                //waiting for the mills to be created in set_neighbor
                //mills[k][0] = i;
                //mills[k][1] = j;
                k++;
            }
            //rest of the board
            else
                board[i][j] = '-';
        }

    }
}

//Board::Board(){}

Board::Board(Board& orig) { }

void Board::print()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << board[i][j];
        cout << endl;
    }
}

Board::~Board()
{
}

char Board::get_char_pos(int row, int column) const
{
    return board[row][column];
}

void Board::set_pos(int row, int column, char player)
{
    //should we do 2 players for this? Or just stick with one and call it twice?
    board[row][column] = player;
}

void Board::set_neighbor()
{
    //tried to build map according to the num of horizontal by vertical positions on the board (0-23=24)
    // then mills is the position on the board, saving what it will eventually contain
    // lots and lots of errors, still working on making the board
    neighbours[0][right] = mills[1];
    neighbours[0][down] = mills[9];
    neighbours[1][right] = mills[2];
    neighbours[1][down] = mills[4];
    neighbours[1][left] = mills[0];
    neighbours[2][0] = mills[14];
    neighbours[2][1] = mills[1];
    neighbours[3][0] = mills[4];
    neighbours[3][1] = mills[10];
    neighbours[4][0] = mills[1];
    neighbours[4][1] = mills[5];
    neighbours[4][2] = mills[7];
    neighbours[4][3] = mills[3];
    neighbours[5][0] = mills[13];
    neighbours[5][1] = mills[4];
    neighbours[6][0] = mills[7];
    neighbours[6][1] = mills[11];
    neighbours[7][0] = mills[4];
    neighbours[7][1] = mills[8];
    neighbours[7][2] = mills[6];
    neighbours[8][0] = mills[12];
    neighbours[8][1] = mills[7];
    neighbours[9][0] = mills[0];
    neighbours[9][1] = mills[10];
    neighbours[9][2] = mills[21];
    neighbours[10][0] = mills[3];
    neighbours[10][1] = mills[11];
    neighbours[10][2] = mills[18];
    neighbours[10][3] = mills[9];
    neighbours[11][0] = mills[6];
    neighbours[11][1] = mills[15];
    neighbours[11][2] = mills[10];
    neighbours[12][0] = mills[8];
    neighbours[12][1] = mills[13];
    neighbours[12][2] = mills[17];
    neighbours[13][0] = mills[7];
    neighbours[13][1] = mills[14];
    neighbours[13][2] = mills[20];
    neighbours[13][3] = mills[12];
    neighbours[14][0] = mills[2];
    neighbours[14][1] = mills[23];
    neighbours[14][2] = mills[13];
    neighbours[15][0] = mills[11];
    neighbours[15][1] = mills[16];
    neighbours[16][0] = mills[17];
    neighbours[16][1] = mills[19];
    neighbours[16][2] = mills[15];
    neighbours[17][0] = mills[12];
    neighbours[17][1] = mills[16];
    neighbours[18][0] = mills[10];
    neighbours[18][1] = mills[19];
    neighbours[19][0] = mills[16];
    neighbours[19][1] = mills[20];
    neighbours[19][2] = mills[22];
    neighbours[19][3] = mills[18];
    neighbours[20][0] = mills[13];
    neighbours[20][1] = mills[19];
    neighbours[21][0] = mills[9];
    neighbours[21][1] = mills[22];
    neighbours[22][0] = mills[19];
    neighbours[22][1] = mills[23];
    neighbours[22][2] = mills[21];
    neighbours[23][0] = mills[14];
    neighbours[23][1] = mills[22];
}

int ** Board::get_neighbor(int index)
{

    if (index >= 0 && index < max)
        return neighbours[index];
    return NULL;
}

int * Board::get_mill(int row, int column, int* index)
{
    for (int i = 0; i < max; i++)
        if (mills[i][0] == row && mills[i][1] == column)
        {
            *index = i;
            return mills[i];
        }
    return NULL;
}

rules::rules()
{
}

rules::rules(const rules& orig)
{
}

rules::~rules()
{
}



bool rules::is_valid_col(char col)
{
    return false;
}

bool rules::is_valid_row(int row)
{
    return false;
}

int rules::to_numeric_col(char column)
{
    return 0;
}

int rules::correct(int row, Board& b)
{
    return 0; //need to find a way to correct invalid num selection to correct vertical pos
}


bool rules::answer_parser(Board& b, string* ans, int* row, int* column, bool* quit)
{
    if (ans->length() == 4) //options for answers func
    {
        if (*ans == "quit" || *ans == "QUIT")
        {
            *quit = true;
            return true;
        }
    }
    else if (ans->length() == 2)
    {
        if (is_valid_col(ans->at(0)) && is_valid_row(ans->at(1) - '0'))//(is_vaild_col (ans.at (0)) && is_vaild_row ((atoi(ans.at (1))))
        {
            *row = correct(ans->at(1) - '0', b);
            *column = to_numeric_col(ans->at(0));
            return true;
        }
    }
    return false;
}

void rules::game_over(string player) //end game
{
    cout << player << " wins the game." << endl;

}

bool rules::check_if_trio(int row, static int column, Board& b, char player)
{//checks surrounding pieces
    int cnt;
    int index_of_mill;
    int * current_mill = b.get_mill(row, column, &index_of_mill);
    int **neighbour = b.get_neighbor(index_of_mill);
    if (current_mill != NULL)
    {
        if (b.get_char_pos(*(neighbour[0] + 2), *(neighbour[0] + 1)) == player)
            cnt = 1; //check row and column, cnt is piece there.
    }
    return true;
}




bool players::Black::move_piece(Board& b, int column, int row, int num_piece = 10)
//answer string, sets position
{
    char position = b.get_char_pos(row, column);
    if ((position == '-') || (position == 'W')) //checks if space is available
        return false;
    b.set_pos(row, column, 'B'); //assigns color
    num_piece--; //not sure how to "link" this back to the class
    //just know we need a count bcuz every player starts with 10 pcs
    return true;
}

int players::Black::getpiece(int num_piece)
{
    return 0;
}

bool players::White::move_piece(Board& b, int column, int row, int num_piece = 10)
{//takes answer string to accept move
    char position = b.get_char_pos(row, column);
    if ((position == '-') || (position == 'B'))//checks if space is available
        return false;
    b.set_pos(row, column, 'W'); //assigns color
    num_piece--;//not sure how to "link" this back to the class
    //just know we need a count bcuz every player starts with 10 pcs
    return true;
}

int players::White::getpiece(int num_piece)
{
    return 0;
}
