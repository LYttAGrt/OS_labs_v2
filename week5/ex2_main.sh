#!/bin/sh
FILE="ex2.txt"
for i in 0 
do
	ps
	# background
	sh ex2_bg.sh $FILE
	# foreground
	sh ex2_fg.sh $FILE
	
	# Part II - let's give a priority for background job
	if ln $FILE $FILE.lock; then
		sh ex2_bg.sh $FILE
		rm $LOCKFILE.lock
		sh ex2_fg.sh $FILE
	else
		sh ex2_fg.sh $FILE
		sleep 1
	fi
	ps
done
