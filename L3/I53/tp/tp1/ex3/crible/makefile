SHELL= /bin/bash

crible.exe:crible.c
	gcc -o crible.exe $< 

data.dat:crible.exe
	./crible.exe -p100 -l10 | sed -e 's/=/   /g;s/pi(//g;s/)//g'>data.dat

pi.png:data.plot
	gnuplot $<

timing.png:crible.exe timing.data
	>timing.data
	for n in {10..28};do \
		./crible.exe -t -l $$n>>timing.data; \
	done \

timingOx.png:
	for n in {1..3};do \
		gcc -o crible.exe crible.c;\
		done;\
		for n in {10..28};do \
			./crible.exe -t -l $$n>>timing.data; \
		done \


