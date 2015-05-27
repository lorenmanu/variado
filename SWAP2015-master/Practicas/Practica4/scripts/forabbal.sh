#!/bin/bash
for (( c=1; c<=10; c++ ))
do
	ab -n 1000 -c 5 http://192.168.1.102/ >> ab_bal_nginx.txt
done
