reset
set terminal png
set output 'squares.png'
set xlabel 'x'
set ylabel 'y = x^2'
plot 'squares.dat' using 1:2 with lines
