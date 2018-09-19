#!/bin/sh
FILE=$1
LASTELEM=0
UNIT=1
RES=""
read line < $FILE
for i in $line
do
	LASTELEM="$i"
	RES="$RES $i"
done
for i in 0
do
	LASTELEM=`expr "$LASTELEM" + "$UNIT"`
	RES="$RES $LASTELEM"
	echo "New line $RES"
	echo "$RES" > $FILE
done
	

