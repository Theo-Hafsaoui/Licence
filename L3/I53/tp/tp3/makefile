SHELL:=/usr/bin/fish
match:match.c
	gcc -o match.exe match.c && ./match.exe "(a|b)*b" abbaba
grep:grep.c
	gcc -o grep.exe grep.c && ./mygrep.exe "([0-9]{1,3}\.){3}[0-9]{1,3}" /tmp/file.txt
test:mygrep.c
	gcc -o mygrep.exe mygrep.c && ./mygrep.exe 

