#!/bin/bash
for (( c=1; c<=10; c++ ))
do
	httperf --server 192.168.1.100 --port 80 --uri / --rate 150 --num-conn 1000 --num-call 1 --timeout 5 >> httperf_bal_haproxy.txt
done
