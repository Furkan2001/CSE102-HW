all: clear compile run clean

compile: main.c utils.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -c  main.c utils.c
	@gcc -o test main.o utils.o
run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test
	@echo "================================================================================="
	@echo "Completed tests...."

clear:
	@clear

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
	@rm -f *.out


