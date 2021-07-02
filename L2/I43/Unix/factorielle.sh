#! bin/bash
s=1
for ((i=$1;i>0;i--))
do
	((s*=i))
done
echo $s
