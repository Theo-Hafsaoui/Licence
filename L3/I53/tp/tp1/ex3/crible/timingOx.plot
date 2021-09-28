set term png
set output 'timingOx.png'
set title 'influence des options de compilation'
set xlabel 'x'
plot 'timing.dat' w l, 'timingO1.dat' w l, 'timingO2.dat' w l, 'timingO3.dat' w l
quit