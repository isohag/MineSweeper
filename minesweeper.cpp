#include "minesweeper.h"
#include <fstream>
#include <string>

using namespace std;

minesweeper::minesweeper() {
	// TODO - default two dimension array is 9 X 9 with 10 mines
    colNum = 9;
    rowNum = 9;
    minesNum = 10;
    end = 0;
    resizeVectors();
}

minesweeper::minesweeper(int col, int row, int numOfMines) {
	// TODO Auto-generated constructor stub
	// TODO - two dimension gameboard size col x num with numOfMines mines
    colNum = col;
    rowNum = row;
    minesNum = numOfMines;
    end = 0;
    resizeVectors();
}

minesweeper::~minesweeper() {
	// TODO Auto-generated destructor stub
}

/**
 * Returns int representing number of rows of current playing field.
 *
 * @return      Number of rows on playing field
 * */
int minesweeper::getRowNum()
{
    return rowNum;
}

/**
 * Returns int representing number of columns of current playing field.
 *
 * @return      Number of rows on playing field
 * */
int minesweeper::getColNum()
{
    return colNum;
}
/**
 * Returns int representing number of mines on current playing field.
 * Includes both hidden and revealed mines.
 *
 * @return      Number of rows on playing field
 * */
int minesweeper::getMinesNum()
{
    return minesNum;
}

/**
 * Returns int randomly generated between 0 and num
 *
 * @param   num Upper limit of randomly generated number
 * @return      Number of rows on playing field
 * @see         initialMineField()
 * */
int minesweeper::randomPick(int num)
{
    return rand()%(num+1);
}

/**
 * Generates mine field after accepting player's first turn.
 * Does not have to avoid first turn game over. 
 *
 * @param   fpX X-coordinate of first pick
 * @param   fpY Y-coordinate of first pick
 * @see     calculateSurrounding()
 * @see     randomPick()
 * */
void minesweeper::initialMineField(int fpX, int fpY) {
	//Generate our map and mask
	//TODO - generate all mines randomly
	//surrounding tile values should be updated to reflect presence of adjacent mine
    int randcol, randrow;

    for(int x=0;x<minesNum;x++)
    {
        do
        {
            randcol=randomPick(colNum-1);
            randrow=randomPick(rowNum-1);
        }
        while((randcol==fpY && randrow==fpX) || (mineField[randrow][randcol]==-1));
        mineField[randrow][randcol]=-1;
        calculateSurrounding(randrow, randcol);
    }
     for(int a=0;a<rowNum;a++)
    {
        for(int b=0;b<colNum;b++)
        {
            cout<<mineField[a][b]<<"\t";
        }
        cout<<endl;
     }
}

/**
 * Generates mine field based on file. This option
 * does not have to check the user's first turn for 1-turn game over.
 *
 * @param   path to load MineField from
 * */
void minesweeper::initialMineField(string path) { 
	//TODO - load mine field from path
	//Is not concerned with user's first tile
    ifstream fin;
    char ch1,ch2;
    int r,c;
    
    fin.open(path.c_str());
    
        fin>>colNum>>rowNum>>minesNum;
        
            resizeVectors();
            for(int x=0;x<minesNum;x++)
            {
                fin>>ch1>>r>>c>>ch2;
                
                mineField[r][c]=-1;
                calculateSurrounding(r,c);
            }
}



/**
 * Generates numbers for surrounding tiles of mines. The only
 * tiles with numbers are those surrounding mines; these tiles are
 * updated as mines are generated.

 *
 * @param   row Row number of generated mine
 * @param   col Column number of generated mine
 * @see     initialMineField()
 * */
void minesweeper::calculateSurrounding(int row, int col) {
	//TODO - should update surrounding tiles to reflect
	//presence of adjacent mine
    for(int a=row-1;a<row+2;a++)
    {
        for(int b=col-1;b<col+2;b++)
        {
            if(a<0 || a>rowNum-1 || b<0 || b>colNum-1 || (a==row && b==col))
                continue;
            if(mineField[a][b]!=-1)
                mineField[a][b]++;
        }
    }
}

/**
 * Updates bitField with user selection of revealed location.
 * Reveals current location and immediately checks mineField
 * for mine. Recursively calls helper function unmask for blank
 * tiles. 
 *
 * @param   row Row number of user selected tile
 * @param   col Column number of user selected tile
 * @see         unmask();
 * */
void minesweeper::revealLocation(int x, int y) {
	//TODO - update the bitField to reflect the user's
	//tile selection. Should rely on unmask to do actual
	//reveal operation.
    if(mineField[x][y]==-1)
    {
        end=-1;
        unmask(x,y);
    }
    else
    {
        unmask(x,y);
    }
}

/**
 * Allow the user to mark a cell as a potential mine. Marking an already
 * marked cell will remove the mark for that cell
 *
 * @param x column number of the cell selected
 * @param y row number of the cell selected
 */
void minesweeper::markLocation(int x, int y) {
    // TODO - update the display for the selected cell, change it
    // to marked if it's not marked, or to unmarked if it's already marked
    if(markField[x][y])
    {
        markField[x][y]=false;
    }
    else
    {
        markField[x][y]=true;
    } 
}

/**
 * Checks end game status (int end). End -1 is loss condition.
 * Also checks onlyMines() for a win condition. onlyMines will
 * update the end game status and endGame should return this value.
 *
 * @return      end game status (-1 loss, 0 ongoing, 1 win)
 * @see         onlyMines();
 * @see		revealLocation();
 * */
int minesweeper::endGame() {
	//TODO - return current end game status.
	//Calling this method should only update int end with
	//win or ongoing condition. revealLocation should
	//update if there is loss condition.
    if(end==-1)
    {
        return end;
    }
    else
    {
        onlyMines();
        return end;
    }
}

/**
 * Checks end game status (int end). End 1 is win condition;
 * end 0 is ongoing. onlyMines will only update end with these
 * two conditions. onlyMines will check the entire playing field
 * (does not rely on numMines or any internal counter). 
 *
 * @see         endGame();
 * */
void minesweeper::onlyMines() {
	//TODO - check for win condition, otherwise ongoing
    bool win=true;
    for(int a=0;a<rowNum;a++)
    {
        for(int b=0;b<colNum;b++)
        {
            if(mineField[a][b]>=0 && bitField[a][b])
            {
                win=false;
            }
        }
    }
    if(!win)
    {
        end=0;
    }
    else
    {
        end=1;
    }
}

/**
 * Checks if the selected position should be visible
 *
 * @param   row Row number of user selected tile
 * @param   col Column number of user selected tile
 * @see         valueOf();
 * */
bool minesweeper::isRevealed(int x, int y) {
	//TODO - check if a user has revealed a specific tile
    if(!bitField[x][y])
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/**
 * Checks if the value of selected tile. isRevealed
 * should be called before this for correct gameplay. 
 * 
 * @param   row Row number of user selected tile
 * @param   col Column number of user selected tile
 * @see         isRevealed();
 * */
int minesweeper::valueOf(int x, int y) {
	//TODO - returns the value of specific tile.
	//should only be called if tile isRevealed.
    return mineField[x][y];
}

/**
 * Reveals surrounding tiles. Should only be called if
 * user selected tile was not mine or had no surrounding
 * mines. Will recursively call itself to reveal all
 * adjacent blank tiles.
 *
 * @param   row Row number of user selected tile
 * @param   col Column number of user selected tile
 * @see         revealLocation();
 * */
void minesweeper::unmask(int row,int col) {
	//TODO - reveal the tile here.
	//This method should reveal surrounding tiles
	//if the tile revealed had a value of 0
    if(row<0 || row>=rowNum || col<0 || col>=colNum || !bitField[row][col] || markField[row][col])
    {
        return;
    }
    else 
    {
        bitField[row][col]=false;
        if(mineField[row][col]==0)
        {
            unmask(row-1,col);
            unmask(row,col-1);
            unmask(row+1,col);
            unmask(row,col+1);
            unmask(row+1,col+1);
            unmask(row-1,col+1);
            unmask(row-1,col-1);
            unmask(row+1,col-1);
        }
    }
}

void minesweeper::resizeVectors()
{
    mineField.resize(rowNum);
    bitField.resize(rowNum);
    markField.resize(rowNum);
    for(int c=0;c<rowNum;c++)
    {
        mineField[c].resize(colNum);
        bitField[c].resize(colNum);
        markField[c].resize(colNum);
    }
      for(int a=0;a<rowNum;a++)
    {
        for(int b=0;b<colNum;b++)
        {
            mineField[a][b]=0;
            bitField[a][b]=true;
            markField[a][b]=false;
        }
    }
}