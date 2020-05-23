p_name = Laba4t1
source_file = Laba4_task2.c


$(p_name).exe: $(p_name).o
	gcc -o $(p_name).exe $(p_name).o

$(p_name).o: $(source_file)
	gcc -Wall -c $(source_file) -o $(p_name).o	

build: $(p_name).o $(p_name).exe

clean:
	del -rf *.o *.s *.exe

run:
	$(p_name).exe