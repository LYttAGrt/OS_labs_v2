#!/bin/sh
ln -s _ex2.txt ../week1/file.txt
ls -i . > ex2.txt
# this is _ex2.txt id
find -inum 1449849 > ex2.txt 
find -inum 1449849 -exec {} rm \; > ex2.txt
