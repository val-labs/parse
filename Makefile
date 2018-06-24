test: p
	./$<<tests/data/dat0
	./$<<tests/data/dat1
	./$<<tests/data/dat3
	perl x.pl p.h
p.o: *.h
clean: ; rm -fr parse *.o *~ p
