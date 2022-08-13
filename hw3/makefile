all: clear compile run clean

compile: hw3.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o test hw3.c -lm
run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test
	@echo "================================================================================="
	@echo "Completed tests...."
clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
	@rm -f *.out
	@rm -f temp.txt
clear:
	@clear
