#!/bin/bash
for (( c=1; c<=10; c++ ))
do
	ab -n 1000 -c 5 http://192.168.1.100/ >> ab_bal_haproxy.txt
done
