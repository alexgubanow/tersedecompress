.SECONDARY:
.SUFIXES:
.PHONY: all src tests clean

default: all

src:
	$(MAKE) -j4 -C src
tests: src
	$(MAKE) -j4 -C tests
check: tests
	$(MAKE) -j4 -C tests check
all: src

clean:
	$(MAKE) -j4 -C src clean
	$(MAKE) -j4 -C tests clean