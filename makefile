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
test1:
	./wordcount -i Supporting_files/single_words_test.txt
test2:
	./wordcount -i Supporting_files/sentences_test.txt
test3:
	./wordcount -i Supporting_files/single_words_test.txt -c
test4:
	./wordcount -i Supporting_files/sentences_test.txt -c
