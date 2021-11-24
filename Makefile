
CC=g++

tictactoe: TicTacToe.o src/drawfield.o src/imageOnStart.cpp src/checkWin.cpp
	$(CC) -o tictactoe TicTacToe.cpp drawfield.o imageOnStart.o checkWin.o gameTitle.o libs/libinput.o 


TicTacToe.o: TicTacToe.cpp
	$(CC) -c TicTacToe.cpp

drawfield.o: src/drawfield.cpp
	$(CC) -c src/drawfield.cpp

imageOnStart.o: src/imageOnStart.cpp
	$(CC) -c src/imageOnStart.cpp

checkWin.o: src/checkWin.cpp
	$(CC) -c src/checkWin.cpp	

gameTitle.o: src/gameTitle.cpp
	$(CC) -c src/gameTitle.cpp	


clean: 
	rm TicTacToe.o drawfield.o imageOnStart.o gameTitle.o


