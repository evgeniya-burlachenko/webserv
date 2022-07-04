
CC = clang++ 
FLAGS = -std=c++98

SERVER = server.cpp
CLIENT = client.cpp

all: 
	$(CC) $(FLAGS) $(SERVER) -o server
	$(CC) $(FLAGS) $(CLIENT) -o client
