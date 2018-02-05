plot "output_coord_cartesian" u 1:((($4 - $6)**2+($5 - $7)**2)**(1./2)) w l title "distance of Janus to Saturn"
replot "output_coord_cartesian" u 1:((($2 - $6)**2+($3 - $7)**2)**(1./2)) w l title "distance of Epimetheus to Saturn"

pause -1 "Press Enter!"