#!/bin/bash
#liste les commande intterne ou externe

while read aux cmd 
do
	echo aux=$aux cmd=$cmd

done < <( enable )
