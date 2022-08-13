all: clear compile run clean

compile: hw5.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -c  hw5.c 
	@gcc -o test hw5.c -lm
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



