gcc -c quiz.c -o exe/quiz.o
gcc -c quiz_text.c -o exe/quiz_text.o
gcc exe/quiz.o exe/quiz_text.o -o exe/quiz