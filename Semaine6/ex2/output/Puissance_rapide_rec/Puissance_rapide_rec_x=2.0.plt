#-----------------------------------------------------------------------------------------------+
# Fichier de commandes gnuplot : ex2/output/Puissance_rapide_rec/Puissance_rapide_rec_x=2.0.plt |
#-----------------------------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "PUISSANCE RAPIDE REC"
set grid
set terminal png
set output 'ex2/output/Puissance_rapide_rec/png/Puissance_rapide_rec_x=2.0_op.png'
plot 'ex2/output/Puissance_rapide_rec/Puissance_rapide_rec_x=2.0.dat' using 1:2 title 'x=2.0'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'ex2/output/Puissance_rapide_rec/png/Puissance_rapide_rec_x=2.0_cmp.png'
plot 'ex2/output/Puissance_rapide_rec/Puissance_rapide_rec_x=2.0.dat' using 1:3 title 'x=2.0'
quit
