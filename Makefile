PROJ=mprot_perf

all:
	gcc $(DEFINES) -o $(PROJ) $(PROJ).c -Wall -std=gnu99

clean:
	rm -rf $(PROJ)

