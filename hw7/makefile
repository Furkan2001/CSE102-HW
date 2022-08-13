all: clear compile run clean

compile: hw7.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -c  hw7.c
	@gcc -o test hw7.o
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



