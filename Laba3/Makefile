p_name = Laba3
source_file = Laba3_var30.c


$(p_name).exe: $(p_name).o
	gcc -o $(p_name).exe $(p_name).o

$(p_name).o: $(source_file)
	gcc -Wall -c $(source_file) -o $(p_name).o	

build: $(p_name).o $(p_name).exe

clean:
	del -rf *.o *.s *.exe

run:
	$(p_name).exe