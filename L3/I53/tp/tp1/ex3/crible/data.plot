set term png
set output 'pi.png'
set title 'pi:comparaison des fonctions pi(x) et x/log(x)'
set xlabel 'x'
plot 'data.dat' w l , x/log(x)
quit