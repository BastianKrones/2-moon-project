plot "./output_coord_cartesian" using 2:3

set size square

#To plot Epimetheus and Saturn
plot "output_coord_cartesian" u ($6/1e6):($7/1e6) lc 3 title "Epimetheus"
replot "output_coord_cartesian" u ($2/1e6):($3/1e6) lc 1 title "Saturn"

pause -1 "Press Enter!"

#To plot Janus and Saturn
plot "output_coord_cartesian" u ($6/1e6):($7/1e6) lc 3 title "Janus"
replot "output_coord_cartesian" u ($4/1e6):($5/1e6) lc 5 title "Saturn"

pause -1 "Press Enter!"

#To plot Saturn's position
plot "output_coord_cartesian" u ($2/1e6):($3/1e6) lc 3 title "Saturn"

pause -1 "Press Enter!"

