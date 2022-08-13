all: clear compile run clean

compile: hw8.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -c  hw8.c util.c
	@gcc -o test hw8.o util.o
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



