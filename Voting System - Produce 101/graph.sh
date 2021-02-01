#!/bin/bash

for FILE in *.dat; do
    gnuplot <<- EOF
        set xlabel "Round"
        set ylabel "Rank"
	set xtics 0,1,5
	set ytics 1,1
	set xrange[1:x]
	set yrange[] reverse
        set title "Rank info"   
	set nokey
        set term dumb
        plot "rank.dat" using 1:2 with linespoints
EOF
done
