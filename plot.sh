gnuplot -p << eof

set logs x
set xlabel 'blocks'
set ylabel 'shannon entropy'
c=0
plot "$1" u 1:2:3 w e title "text n $c"
eof
