all : bin
bin :
	gcc src/main.c -o lw -Wall
	time ./lw http/www/index.cgi
test :
	gcc src/main.c -o lw -Wall
	./http/httpserver.py -p 8080 -P http/www
color :
	sudo cp language-specs/leewee.lang /usr/share/gtksourceview-3.0/language-specs/leewee.lang
	sudo cp language-specs/leewee.lang /usr/share/gtksourceview-2.0/language-specs/leewee.lang
uncolor :
	sudo rm -f /usr/share/gtksourceview-3.0/language-specs/leewee.lang
	sudo rm -f /usr/share/gtksourceview-2.0/language-specs/leewee.lang
install :
	gcc src/main.c -o lw -Wall
	sudo cp lw /usr/bin/lw
uninstall :
	sudo rm -f /usr/bin/lw
clean :
	rm -f lw
