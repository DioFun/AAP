all : checksum.exe

checksum.exe : main.c
	gcc main.c -o checksum.exe

test : checksum.exe
	./checksum.exe > collected_data

.PHONY : clean
clean :
	rm checksum.exe collected_data