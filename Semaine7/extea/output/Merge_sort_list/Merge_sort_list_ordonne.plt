#-----------------------------------------------------------------------------------------+
# Fichier de commandes gnuplot : extea/output/Merge_sort_list/Merge_sort_list_ordonne.plt |
#-----------------------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "Merge sort list"
set grid
set terminal png
set output 'extea/output/Merge_sort_list/png/Merge_sort_list_ordonne_op.png'
plot 'extea/output/Merge_sort_list/Merge_sort_list_ordonne.dat' using 1:2 title 'ordonne'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'extea/output/Merge_sort_list/png/Merge_sort_list_ordonne_cmp.png'
plot 'extea/output/Merge_sort_list/Merge_sort_list_ordonne.dat' using 1:3 title 'ordonne'
quit
