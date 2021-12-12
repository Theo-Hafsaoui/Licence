#!/bin/bash

if [ ! -f sigma.dat ] ; then
    for (( n=1; n<=1024; n++ ));
    do
        ./sigma.exe $n | grep [0-9]* -o | tr "\n" " " && echo ;
    done > sigma.dat
fi
