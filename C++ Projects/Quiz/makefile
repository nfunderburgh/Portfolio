
quiz: main.o quiz.o question.o questiontf.o questionmc.o questionsa.o
	g++ -g main.o quiz.o question.o questiontf.o questionmc.o questionsa.o -o quiz

main.o: main.cpp quiz.h question.h
	g++ -g -c main.cpp

quiz.o: quiz.cpp quiz.h 
	g++ -g -c quiz.cpp

question.o: question.cpp question.h
	g++ -g -c question.cpp

questiontf.o: questiontf.cpp questiontf.h question.h
	g++ -g -c questiontf.cpp

questionmc.o: questionmc.cpp questionmc.h question.h
	g++ -g -c questionmc.cpp

questionsa.o: questionsa.cpp questionsa.h question.h
	g++ -g -c questionsa.cpp

clean:
	rm quiz *.o
