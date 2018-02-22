wordcount:
	gcc -c wordcount.c
	gcc -o wordcount wordcount.c
	chmod +x wordcount
debug:
	gcc -o wordcount wordcount.c -D DEBUG
	chmod +x wordcount
clean:
	rm -f wordcount 
	rm -f wordcount.o