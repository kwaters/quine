SHELL := /bin/bash

.PHONY: all test

all: quine test

test: quine
	diff -u quine.c <(./quine)

quine: quine.c
	$(CC) -std=c89 -pedantic -Wall -Werror -Os -o $@ $<

