#!/bin/sh
# initial
ls -l > ex3.txt

# ok, thanks to tutorialspoint.com for its existance
# 1: remove X to all
chmod a-x _ex3.txt
ls -l > ex3.txt

# 2: all permissions to owner and others, not group
chmod 707 _ex3.txt
ls -l > ex3.txt

# 3. Equate user and group
chmod ug+rwx _ex3.txt
ls -l > ex3.txt
