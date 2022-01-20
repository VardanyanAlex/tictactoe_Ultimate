
CC=g++

tictactoe: TicTacToe.o drawfield.o imageOnStart.o gameplay.o checkWin.o gameTitle.o importantDetails.o youWin.o scriptCalls.o
	$(CC) -o tictactoe TicTacToe.cpp src/gameTitle.cpp src/drawfield.cpp src/imageOnStart.cpp src/gameplay.cpp src/checkWin.cpp src/importantDetails.cpp  src/youWin.cpp src/scriptCalls.cpp libs/libinput.o -pthread

TicTacToe.o: TicTacToe.cpp
	$(CC) -c TicTacToe.cpp

all.o: *.cpp
	cd src; 
	$(CC) -c *.cpp

drawfield.o: src/drawfield.cpp
	$(CC) -c src/drawfield.cpp

imageOnStart.o: src/imageOnStart.cpp
	$(CC) -c src/imageOnStart.cpp

checkWin.o: src/checkWin.cpp
	$(CC) -c src/checkWin.cpp	

gameTitle.o: src/gameTitle.cpp
	$(CC) -c src/gameTitle.cpp	

gameplay.o: src/gameplay.cpp
	$(CC) -c src/gameplay.cpp	

importantDetails.o: src/importantDetails.cpp
	$(CC) -c src/importantDetails.cpp		

youWin.o: src/youWin.cpp
	$(CC) -c src/youWin.cpp	-pthread	
	
scriptCalls.o: src/scriptCalls.cpp
	$(CC) -c src/scriptCalls.cpp

clean: 
	rm TicTacToe.o drawfield.o imageOnStart.o gameTitle.o importantDetails.o


