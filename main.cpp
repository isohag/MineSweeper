#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include "minesweeper.h"
#include "bonus.h"
using namespace std;

void playTime(minesweeper& play);
void viewStatistics();
int userMenu();
void printBoard(minesweeper& play, vector<vector<bool>>& markVec);

/*
 *
 */

int main() {
    while (1){
        //  Loop until proper input recieved.
        int choice;
        do {
            if(cin.fail()){
                cout << "Invalid input!"<<endl;
                cin.clear();
                cin.ignore(100,'\n');
            }
            cout <<"Menu"<<endl;
            cout << "1. Start Game"<<endl;
            cout << "2. View Stats"<<endl;
            cout << "3. Quit Program"<<endl;
            cin >> choice;
        } while (choice!=1 && choice!=2 && choice!=3 && cin.fail());

        //  Run appropriate functions based on input
        if (choice == 3)
            return 0;
        else if (choice == 2)
            viewStatistics();
        else {
            //  Proper input for Load File.
            string load;
            do {
                cout << "Load from file? (y or n)" << endl;
                cin >> load;
                cin.clear();
                cin.ignore(100,'\n');
            } while (load[0]!='y' && load[0]!='n' && load.length()!=1);
            char loaded = load[0];

            //  User selected Yes.
            //  Initialize MineSweeper Object(Default constructor) and field.
            if (loaded == 'y') {
                minesweeper game;
                string fileName;
                cout << "File path: "<< endl;
                cin >> fileName;
                game.initialMineField(fileName);
                playTime(game);
                //printBoard(play, markVec);
            }
            
            //  User Selected No.
            //  Initialize MineSweeper Object(Optional constructor) and field.
            if (loaded == 'n') {
                
                //////  First Turn  ///////////
                /* m = row & n = column in this case */
                int n, m, mines;
                do {
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    cout <<"Number Rows(n): ";
                    cin >> n;
                    cout <<"Number of Columns(m): ";
                    cin >> m;
                    cout <<"Number of Mines: ";
                    cin >> mines;
                    if (cin.fail() || n<1 || m<1 || mines<0)
                        cout << "Invalid Input !" << endl;
                } while (cin.fail() || n<1 || m<1 || mines<0);
                minesweeper game(m, n, mines);
                playTime(game);
            }
        }
    }
    
    return 0;
}

/* This should be your game UI function. If a user decides to play a game of minesweeper,
 * UI interaction with a minesweeper object should be done here. For example, the repeated
 * printing of the board state and handling of user game action such as left/right click
 * on a particular cell should be done here
 */

void playTime(minesweeper& play) {
    //TODO - Begin the minesweeper game function; should interact with minesweeper class/object here
    vector<vector<bool>> markVec(play.getRowNum(),vector<bool>(play.getColNum(),false));
    printBoard(play, markVec);

    //////  User Interaction  ///////////
    char click,coma;
    int row, col;
    do {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Click(l to reveal & r to mark i.e. \"l,row,col\"): ";
        cin >> click >> coma >> row >> coma >> col;
        //  Display invalid input.
        if((click!='l' && click!='L' && click!='r' && click!='R') || row<0 || row>play.getRowNum()-1 || col<0 || col>play.getColNum()-1)
            cout << "Invalid Input !" << endl;
    } while ((click!='l' && click!='L' && click!='r' && click!='R') || row<0 || row>play.getRowNum()-1 || col<0 || col>play.getColNum()-1);
    
    ////////  Mark Location Selected    //////
    
    while (click=='r' || click=='R') {
        play.markLocation(row, col);
        if (markVec[row][col])
            markVec[row][col] = false;
        else
            markVec[row][col] = true;
        printBoard(play, markVec);
        /////  User Input  ////////////////////////
        do {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Click(l to reveal & r to mark i.e. \"l,row,col\"): ";
            cin >> click >> coma >> row >> coma >> col;
            //  Display invalid input.
            if((click!='l' && click!='L' && click!='r' && click!='R') || row<0 || row>play.getRowNum()-1 || col<0 || col>play.getColNum()-1)
                cout << "Invalid Input !" << endl;
        } while ((click!='l' && click!='L' && click!='r' && click!='R') || row<0 || row>play.getRowNum()-1 || col<0 || col>play.getColNum()-1);
    }
    //  First Turn.
    play.initialMineField(row, col);
    play.revealLocation(row,col);
    
    ////////////    Rest of the Game    ///////////////
    
    while (play.endGame()==0) {
        printBoard(play,markVec);   //  Print Board.
        /////  User Input  ////////////////////////
        do {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Click(l to reveal & r to mark i.e. \"r,row,col\"): ";
            cin >> click >> coma >> row >> coma >> col;
            //  Display Invalid input
            if((click!='l' && click!='L' && click!='r' && click!='R') || row<0 || row>play.getRowNum()-1 || col<0 || col>play.getColNum()-1)
                cout << "Invalid Input !" << endl;
        } while ((click!='l' && click!='L' && click!='r' && click!='R') || row<0 || row>play.getRowNum()-1 || col<0 || col>play.getColNum()-1);
        
        //  Mark Location according to user input.
        if (click=='r' || click=='R') {
            play.markLocation(row, col);
            if (!play.isRevealed(row, col)) {
                if (markVec[row][col])
                    markVec[row][col] = false;
                else
                    markVec[row][col] = true;
            }
            else
                cout << "Cannot mark revealed tile." << endl;
        }
        //  Reveal Location according to user input.
        else{
            if (!markVec[row][col])
                play.revealLocation(row, col);
            else
                cout << "Cannot reveal marked tile! " << endl;
        }
    }
    
    //  Player Won!
    if(play.endGame()==1) {
        cout << "YOU WIN!!!!!!!" << endl;
        // Reveal locations
        for (int i=0;i<play.getRowNum();i++) {
            for (int j=0;j<play.getColNum();j++) {
                play.revealLocation(i, j);
            }
        }
    }
    
    //  Player Lost!
    else {
        cout<<"YOU LOSE!!!!!!!!"<<endl;
        // Reveal locations
        for (int i=0;i<play.getRowNum();i++) {
            for (int j=0;j<play.getColNum();j++) {
                play.revealLocation(i, j);
            }
        }
    }
    
    printBoard(play, markVec);
}

/* display the statistics of the game. This is a bonus point function
 */
void viewStatistics() {
    cout << "Currently Not Supported \n" << endl;
}

void printBoard(minesweeper& play, vector<vector<bool>>& marked){
    int nCol = play.getColNum();
    int nRow = play.getRowNum();
    char tile;
    cout << endl;
    //  Column Index
    
    cout << ' ' << ' ' ;
    if (nRow>9){
        cout << ' ' ;
    }
    for (int k=0;k<nCol;k++){
        if (k>10){cout << setw(2);}
        else if (nCol>9){
            cout << setw(2);
            cout << ' ' ;
        }
        
        cout << ' ' << k;
    }
    cout << "\n" << endl;

    //  Actual board
    for (int i=0; i<nRow;i++){
        
        cout << i << ' ' ;  //  Row Index
        if (i>9){}
        else if (nRow>9){
            cout << ' ';
        }
        for (int j=0;j<nCol;j++){
            
            //  printing Tiles //
            if (marked[i][j])
                tile = 'M';
            else if (play.isRevealed(i, j)) {
                if (play.valueOf(i, j)>0)
                    tile = play.valueOf(i, j) + 48;
                else if (play.valueOf(i, j)<0)
                    tile = '*';
                else
                    tile = ' ';
            }
            else
                tile = '?';
            if (nCol>=10){
                cout <<' ';
                cout << setw(2);
            }
            cout << ' ' << tile ;
        }
        cout << endl;
        cout << endl;
    }
}
