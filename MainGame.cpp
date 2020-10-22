#include <iostream>
#include <cstdlib>
#include <string>
#include "Header.h"
using namespace std;

int main(int player1, char** arg) {

    int row, column;
    string answer;
    Board b;
    string player;
    bool quit = false;
    rules r;
    players::Black black;
    players::White white;
    bool valid = true;

    do {
        do {
            do {
                cout << "Player 1, go:"; //the plays are neither white nor
                //black because it is up to the players who goes first
                //unlike chess
                cin >> answer;
                if (r.answer_parser(b, &answer, &row, &column, &quit)) {
                    valid = true;
                    if (black(b, column, row) && !quit) {

                        b.print();
                        r.check_if_trio(row, column, b, 'B');
                        break;
                    }

                    else if (!quit) //not sure what is causing this
                        //there is an if right after, it looks just like
                        //the one below
                    {
                        cout << "Invalid move. Try again." << endl;
                        valid = false;
                    }
                    else if (quit) {
                        player = "W";
                        break;
                    }


                    else
                    {
                        cout << "Invalid move. Try again." << endl;
                        break;
                    }

                }
            } while (!valid);
            if (quit)
                break;

            do
            {
                cout << "Player 2, go"; //the plays are neither white nor
                //black because it is up to the players who goes first
                //unlike chess
                cin >> answer;
                if (r.answer_parser(b, &answer, &row, &column, &quit))
                {//thinks answer func doesn't take 5???
                    valid = true;
                    if (white(b, column, row) && !quit) //need to find was to link this
                    {
                        b.print(); //finish coding how to print board
                        break;
                    }
                    else if (!quit)
                    {
                        cout << "Invalid move. Try again." << endl;
                        valid = false;
                    }
                    if (quit)
                    {
                        player = "B";
                        break;
                    }
                }
                else
                {
                    cout << "Invalid move. Try again." << endl;
                    break;
                }
            } while (!valid);
            if (quit)
                break;


            //cout << white.getpiece() << endl; //someway to "get" these
            //pieces in the white func


        } while ((white.getpiece()) > 0 && !quit);//someway to "get" these
                //pieces in the white func

        
    } while (!quit);

    //loops to be made for moves, valid and invalid
    //quit option (break;), switch players, etc.


    r.game_over(player); //someone wins
    return 0;

    //we need 2 loops of get_player1 and 2 to return/move or quit
    //still finding a way to create the board
}

