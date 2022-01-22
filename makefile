OBJS := main.o Game.o 

%.o: %.cpp
	g++ -c $^ -o $@ -Iinclude

game: $(OBJS)
	g++ -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system
