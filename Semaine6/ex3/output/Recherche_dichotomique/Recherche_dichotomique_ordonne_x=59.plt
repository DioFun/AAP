#----------------------------------------------------------------------------------------------------------+
# Fichier de commandes gnuplot : ex3/output/Recherche_dichotomique/Recherche_dichotomique_ordonne_x=59.plt |
#----------------------------------------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "RECHERCHE DICHOTOMIQUE"
set grid
set terminal png
set output 'ex3/output/Recherche_dichotomique/png/Recherche_dichotomique_ordonne_x=59_op.png'
plot 'ex3/output/Recherche_dichotomique/Recherche_dichotomique_ordonne_x=59.dat' using 1:2 title 'ordonne_x=59'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'ex3/output/Recherche_dichotomique/png/Recherche_dichotomique_ordonne_x=59_cmp.png'
plot 'ex3/output/Recherche_dichotomique/Recherche_dichotomique_ordonne_x=59.dat' using 1:3 title 'ordonne_x=59'
quit
