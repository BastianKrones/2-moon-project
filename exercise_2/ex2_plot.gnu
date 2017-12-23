plot "data.txt" using 1:2
plot "data.txt" using 1:3
replot sin(x) lc 3
replot cos(x) lc 3

pause -1 "Press Enter!"
