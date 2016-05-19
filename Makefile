PROJ=mprot_perf
PROJ2=mprot_perf_multiple
PROJ3=mprot_perf_error
CC=gcc

all:
	$(CC) $(DEFINES) -o $(PROJ) $(PROJ).c -Wall -std=gnu99
	$(CC) $(DEFINES) -o $(PROJ2) $(PROJ2).c -Wall -std=gnu99
	$(CC) $(DEFINES) -o $(PROJ3) $(PROJ3).c -Wall -std=gnu99

clean:
	rm -rf $(PROJ)

