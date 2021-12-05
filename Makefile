TEST_FOLDER=./testing

BIN=bf

a:
	gcc src/bf.c -o $(BIN)

test:
	./$(BIN) $(TEST_FOLDER)/Hello.bf 
	./$(BIN) $(TEST_FOLDER)/Beer.bf 

