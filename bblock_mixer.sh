#!/bin/bash

if [ "$1" == "help" ];
then
echo "path/file, samples, identificativo"
exit 0
fi
mkdir temp 
echo "#block compression_ratio error" > results/curve_${3}.dat
R= echo $(wc -c $1 | awk '{print $1}')
declare -i R
echo $R
echo "entropy measure in progress for" $1 " enjoy your book"
for x in  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000 1200 1400 1600 1800
do
	echo "" > temp/samples_${3}.tmp
	var=0
	count=0
	for i in $(seq 1 $2)
	do
	        ./mixer.o $1 $x > temp/bloc_${3}.tmp
		gzip -cf9 temp/bloc_${3}.tmp > temp/zipped_${3}.tmp.gz
		echo $(wc -c temp/zipped_${3}.tmp.gz)  >> temp/samples_${3}.tmp
		rm temp/zipped_${3}.tmp.gz 
		rm temp/bloc_${3}.tmp
	done
	
	awk -v z=$(wc -c $1 |awk '{print $1}') ' {u+=$1; s+= $1*$1; c++} END { print '$x' "  " u/c/z "  " sqrt((s/c-(u/c)**2)/c)/z "  "}' temp/samples_${3}.tmp>> results/curve_$3.dat  

echo "zipping" $1 "over " $x "blocks" 
done
