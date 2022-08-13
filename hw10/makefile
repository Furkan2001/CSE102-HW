all: clear compile run clean

compile: hw10.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -c  hw10.c
	@gcc -o test hw10.o
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



