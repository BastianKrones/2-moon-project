#To plot Epimetheus and Saturn
plot "output_coord_cartesian" u 1:3 lc 3 title "Epimetheus"
replot "output_coord_cartesian" u 1:5 lc 3 title "Janus"

pause -1 "Press Enter!"