#pragma once
#include <iostream>
#include <ctype.h>
#include <string>
#include <stdlib.h>
using namespace std;


class players{
public:
    class White{
        //void White(Board& b, int column, int row);
        bool move_piece(Board& b, int column, int row, int num_piece = 10);
        int getpiece(int num_piece);
    };
    class Black {
        bool move_piece(Board& b, int column, int row, int num_piece = 10);
        int getpiece(int num_piece);
    };

    int num_piece = 10;
};
class rules
{
public:
    rules();
    rules(const rules& orig);
    virtual ~rules();
    bool is_valid_col(char column); // check column availability
    bool is_valid_row(int row);// check row availability
    int to_numeric_col(char column); // Converts an alphabetical value to its equivalent numerical value
    int correct(int row, Board& b); // convert the number to the correct place uppon the y axis

    bool answer_parser(Board& b, string* ans, int* row, int* column, bool* quit);
    void game_over(string player);
    bool check_if_trio(int row, int column, Board& b, char player);

private:
    

    //int b;
};

class Board {
public:
    Board();
    Board(Board& orig);
    void print();
    virtual ~Board();
    //getters and setter
    char get_char_pos(int row, int column) const;
    void set_pos(int row, int column, char player);
    //get columns?
    int get_column() {
        return column;
    }
    int get_row() {
        return row;
    }

    void set_neighbor(); //for saving player adjacency
    int ** get_neighbor(int index_mill);
    int * get_mill(int row, int column, int *index = NULL);

private:
    static const int column = 13;
    static const int row = 7;
    char board[row][column];
    int mills[24][2];
    int *neighbours[24][4];
    int junc[3][7][2];
    enum { max = 24 };
    enum { up = 0, right = 1, down = 2, left = 3 };

};
