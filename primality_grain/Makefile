CHARMDIR = $(CHARM_HOME)
CHARMC = $(CHARMDIR)/bin/charmc

default: all
all: hello


hello : main.C main.decl.h main.def.h
	$(CHARMC) main.C -o hello

main.decl.h main.def.h : main.ci
	$(CHARMC) main.ci

clean:
	rm -f main.decl.h main.def.h hello charmrun