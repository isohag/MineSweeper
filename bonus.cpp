
#include <fstream>
#include <iostream>
#include <string>
#include "bonus.h"

using namespace std;

         
         /*
         int bonus::saveGame(std::string path) //Save minesweeper object state to file
         {
             
         }
         */
             
         /*
         int bonus::loadGame(std::string path) //Load minesweeper object state from file
         {
             
         }
          */
         
         int bonus::saveStatistics(std::string path) //Save overall game statistics to file
         {
            ofstream stat;
            stat.open("game_stat.dat");
            stat.setf(ios::fixed);
            stat.precision(2);
            //print game statistics
            stat<<"Game statistics: "<<endl<<"---- ----------"<<endl<<endl;
            stat<<"Win(s)-  "<<wins<<endl;
            stat<<"Loss(s)-  "<<loss<<endl;
            stat<<"win-loss-ratio-  "<<ratio<<endl;
            stat<<"Current win streak-  "<<winStreak<<endl;
            stat<<"Longest win streak-  "<<longestWinStreak<<endl;
            return 1;
         }
         
         /*int bonus::loadStatistics(std::string path)  //Load overall game statistics from file
         {
             
         }
          */
         
         int bonus::getWins()                         //Returns # of wins
         {
             return wins; 
         }
         
         void bonus::setWins()                       //Modify # of wins
         {
             wins++; 
         }
         
         int bonus::getLoss()                        //Returns # of losses
         {
             return loss;
         }
         
         void bonus::setLoss()                       //Modify # of losses
         {
             loss++;
         }
         double bonus::getRatio()                   //Returns Win/loss Ratio
         {
             return ratio;
         }
         int bonus::getWinStreak() //Returns current Win Streak (consecutive wins)
         {
            return winStreak; 
         }
         void bonus::setWinStreak() //Modifies current Win Streak # (consecutive wins)
         {

             winStreak++;
         }
         int bonus::getLongestWinStreak() //Returns longest Win Streak (largest win streak seen)
         {
             return longestWinStreak;
         }
         void bonus::setLongestWinStreak() //Modifies longest Win Streak (largest win streak seen)
         {
             if(longestWinStreak<winStreak)
                longestWinStreak=winStreak;
         }
	 void bonus::initialMineField(int fpX, int fpY)	//Initialize game board given first revealed tile.
							//Overrides minesweeper.initialMineField(fpX,fpY)
         {
                
         }
         void bonus::calcRatio()   //Calculates Win/loss Ratio
         {
             ratio=wins/loss;
         }

         
	 
    
   