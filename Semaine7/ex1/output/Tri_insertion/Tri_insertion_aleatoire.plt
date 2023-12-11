#-------------------------------------------------------------------------------------+
# Fichier de commandes gnuplot : ex1/output/Tri_insertion/Tri_insertion_aleatoire.plt |
#-------------------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "TRI INSERTION"
set grid
set terminal png
set output 'ex1/output/Tri_insertion/png/Tri_insertion_aleatoire_op.png'
plot 'ex1/output/Tri_insertion/Tri_insertion_aleatoire.dat' using 1:2 title 'aleatoire'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'ex1/output/Tri_insertion/png/Tri_insertion_aleatoire_cmp.png'
plot 'ex1/output/Tri_insertion/Tri_insertion_aleatoire.dat' using 1:3 title 'aleatoire'
quit
