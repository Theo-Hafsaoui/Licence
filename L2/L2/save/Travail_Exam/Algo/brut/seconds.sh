#!/bin/bash

laps=`(time ($* > /dev/null) 2>&1) | grep  "real" | sed 's/^[:space:\t]*real[:space:\t]*//g' `
m=`expr "$laps" : '\(^[^m]\)m.*'`
s=`expr "$laps" : '^[^m]*m\([^m]*\)s$'`
echo 60*$m+$s | bc -l
