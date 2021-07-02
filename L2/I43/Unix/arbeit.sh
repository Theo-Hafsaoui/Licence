#! /bin/bash

s=0
for ((i=$1;i<$2;i++))
do
	temp=$(date +'%a' -d 5/28/$i)
	if [ $temp == "sam." ] || [ $temp == "dim." ];
	then
		((s++))
	fi
done
echo $s
