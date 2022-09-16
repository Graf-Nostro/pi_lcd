#!/bin/bash

TEMP=`tail -c 6 /sys/bus/w1/devices/28-00000da0cd5a/w1_slave`
T_CELSIUS=`echo $TEMP | sed 's/\([0-9]\{2\}\)\([0-9]\{3\}\)/\1.\2\C/'`

# print to terminal
echo "Temperature is: " $T_CELSIUS

# print string to lcd
./textToDisplay $T_CELSIUS 
