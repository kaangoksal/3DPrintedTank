#!/bin/bash

while true ; do 
	if ifconfig wlan0 | grep -q "inet addr:" ; then
		echo "It is workimg"
		sleep 5
	else
		echo "Network Connection down! Attempting reconnection"
		sudo ifup wlan0
		sleep 2
	fi
done