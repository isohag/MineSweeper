MM   MM   IIII   N     N  EEEEE     SS    WW WW WW  EEEEE  EEEEE   PPPP   EEEEE   RRRRR
M MMM M    II    N N   N  EE      SS  SS  WW WW WW  EE     EE     P    P  EE     RR   RR
M  M  M    II    N  N  N  EEEEE   SS      WW WW WW  EEEEE  EEEEE  P    P  EEEEE  RRRRRR
M  M  M    II    N   N N  EEEEE     SS    WW WW WW  EEEEE  EEEEE  PPPPP   EEEEE  RRRRR
M  M  M    II    N    NN  EE      S   SS   WWWWWW   EE     EE     PP      EE     RR  RR
M  M  M   IIII   N     N  EEEEE    SSSS     WWWW    EEEEE  EEEEE  PP      EEEEE  RR   RR
________________________________________________________________________________________


A) Introduction

B) How to play
	a) Start Game
	b) View Status
	c) Quit Program
	d) Error Checking

C) Bonus features

________________________________________________________________________________________





A)  Introduction:

This game is a grid based program where after starting the game, 

follow the instruction closely to allow the game to continue.

----------------------------------------------------------------------------------------

B)  How to play:

Initialize the program using NetBeans IDE.  

After loading the program into the complier, run the program.  

This will display the main Menu.

|	Menu			|
|	1. Start Game		|
|	2. View Status		|
|	3. Quit Program		|

Choose one of the three options:  Enter single number 1, 2, or 3.

	
a)  Start the Game:

	1)  Choose 1 to start the game.

	|  Click(l for left(Reveal) r for right(Mark) ex. \"r,0,0\"): |

	2)  Enter the input in the corresponding format: 
    	 Letter l for left (indication of left click on a mouse) = Reveal: 
                       		If the reveal does not hit a mine, a number is displayed on
                        	the game board to show the number of adjacent mine(s).

	Example Output:
	|          0 1 2 3 4 5 6 7 8		|
	|	0  ? ? ? ? ? ? ? ? ?		|
	|	1  ? ? ? ? ? ? ? ? ?		|
	|	2  ? ? ? ? ? ? ? ? ?		|
	|	3  ? ? ? ? ? ? ? ? ?		|
	|	4  ? ? ? ? 2 ? ? ? ?		|
	|	5  ? ? ? ? ? ? ? ? ?		|
	|	6  ? ? ? ? ? ? ? ? ?		|
	|	7  ? ? ? ? ? ? ? ? ?		|
	|	8  ? ? ? ? ? ? ? ? ?		|

	|  Click(l for left(Reveal) r for right(Mark) ex. \"r,0,0\"): |

     	Letter r for Right (indication of right click on a mouse) = Mark: place a mark.  
                                        	On the grid letter M is displayed as marked.
                                       		 l,#,# or r,#,#. (#,# is the coordinate of the grid)

	Example Output:
	|          0 1 2 3 4 5 6 7 8		|
	|	0  ? ? ? ? ? ? ? ? ?		|
	|	1  ? ? ? ? ? M ? ? ?		|
	|	2  ? ? ? ? ? ? ? ? ?		|
	|	3  ? ? ? ? ? ? ? ? ?		|
	|	4  ? ? ? ? ? ? ? ? ?		|
	|	5  ? ? ? ? ? ? ? ? ?		|
	|	6  ? ? ? ? ? ? ? ? ?		|
	|	7  ? ? ? ? ? ? ? ? ?		|
	|	8  ? ? ? ? ? ? ? ? ?		|

	|  Click(l for left(Reveal) r for right(Mark) ex. \"r,0,0\"): |

	3) Continue to enter inputs in the same format as step 2).

	4) If the input hits a mine -> YOU LOSE!!!!!!!!
                               The game board is revealed:  '*' is the location of the mine

	Example Output:

	|	YOU LOSE!!!!!!!!		|
	| 	  0 1 2 3 4 5 6 7 8		|
	|					|
	|	0    1 M 1       1 1		|
	|	1    1 2 2 1     1 *		|
	|	2      M * 2   1 2 2		|
	|	3      2 * M   1 * 1		|
	|	4  1 2 2 2 M 1 2 2 1		|
	|	5  * 2 * 2 1 1 * 1  		|
	|	6  1 2 2 * 1 1 1 1  		|
	|	7    1 2 2 1        		|
	|	8    1 * 1        		|

	5) Reinitialize the main Menu:

---------------------------------------------------------------------------------------------

b) View Status:

	1)  Choose number 2 to view status


---------------------------------------------------------------------------------------------

c) Quit Program:
	
	1)  Choose number 3 to Quit the Program and exit out.

----------------------------------------------------------------------------------------------

d) Error Checking:

	1)   Click(l for left(Reveal) r for right(Mark) ex. \"r,0,0\"): input of anything other than r or l,#,# will 
	     loop back to the the input rather than exiting out of the program.

	Example output
	
	Click(l for left(Reveal) r for right(Mark) ex. \"r,0,0\  asdfdsjfdsapi
	Click(l for left(Reveal) r for right(Mark) ex. \"r,0,0\
	