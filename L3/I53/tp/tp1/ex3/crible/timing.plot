set term png
set output 'timing.png'
set title 'timing:mesure du temps de calcul du crible'
set xlabel 'x'
plot 'timing.dat' w l, 2.55*x/100
quit