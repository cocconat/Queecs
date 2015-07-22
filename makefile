CC= g++

FILES= cpp_mixer_vectorized.cpp

build: $(FILES)
	$(CC) -o mixer $(FILES) -std=c++11	
	
clean: 
	rm -f mixer

rebuild: clean build
