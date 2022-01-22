OBJS := main.o Game.o
LIBS := -lsfml-window -lsfml-graphics -lsfml-system

%.o: %.cpp
	g++ -c $^ -o $@ -I include

game: $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS)