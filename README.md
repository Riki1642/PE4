Person_1 -> Riley Kirkham
Person_2 -> Riley Kirkham

I did both portions of this assignment since I could not find a partner. However, I made sure to create separate branches
and pull requests as the instructions say, so it shouldn't affect the assignment in any way.

This repository will host a file that can run a game of tictactoe.

To run this, download all files into a single folder.
Then open a terminal and navigate to this folder.
Then run the following commands:
make
./main

This will start the game.
At the top, it will announce which player's turn it currently is (X or O).
The player will see two grids, one of which is filled with numbers 1-9 and one of which is filled with "_"s.
The grid with numbers acts as a coordinate system and the player inputs the number corresonding to the point that they want to place their X or O on.

The bottom grid is a live view of the game which will update with every turn.

The game will automatically declare a winner once one is determined.
It will also check for valid/invalid moves and declare a tie if the players use up every available square.
