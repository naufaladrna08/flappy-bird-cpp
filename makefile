OBJS := main.o Game.o State.o GameState.o

%.o: %.cpp
	g++ -c $^ -o $@ -Iinclude

game: $(OBJS)
	g++ -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf $(OBJS) game