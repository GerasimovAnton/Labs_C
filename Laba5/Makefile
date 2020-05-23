p_name = main
source_file = my_stack.c


$(p_name).exe: $(p_name).o
	gcc -o $(p_name).exe $(p_name).o

$(p_name).o: $(source_file)
	gcc -Wall -c $(source_file) -o $(p_name).o	

build: $(p_name).o $(p_name).exe

clean:
	del -rf *.o *.s *.exe

run:
	$(p_name).exe
