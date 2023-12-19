#-----------------------------------------------------------------+
# Fichier de commandes gnuplot : ex4/output/Hanoi/Hanoi_hanoi.plt |
#-----------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "HANOI"
set grid
set terminal png
set output 'ex4/output/Hanoi/png/Hanoi_hanoi_op.png'
plot 'ex4/output/Hanoi/Hanoi_hanoi.dat' using 1:2 title 'hanoi'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'ex4/output/Hanoi/png/Hanoi_hanoi_cmp.png'
plot 'ex4/output/Hanoi/Hanoi_hanoi.dat' using 1:3 title 'hanoi'
quit
