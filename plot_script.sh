gnuplot -p << eof

set logs x
set xlabel 'blocks'
set ylabel 'shannon entropy'
c=0
plot for [ file in "$@" ] file u 1:2:3 w e title "text n $c"
eof
