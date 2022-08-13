all: clear compile run clean

compile: hw11.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -c  hw11.c
	@gcc -o test hw11.o
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



