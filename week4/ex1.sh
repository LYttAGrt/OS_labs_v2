#!/bin/sh
DATA=""
RES=""
for i in 0 1 2 3 4 5 6 7 8 9; do
	RES=$(~/OS_labs/week4/ex1)
	echo $RES
	DATA=$(echo "$RES$DATA")
	echo $DATA
done

