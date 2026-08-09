set terminal wxt size 1600,1000
set multiplot layout 4,2 rowsfirst
set grid
set logscale y
set xlabel 'Input Size (n)'
set ylabel 'Operations (log scale)'
set key font ',7'
set title 'Search'
plot 'dictionary.dat' every 7::0 using 1:2 with lines title 'UA','dictionary.dat' every 7::0 using 1:3 with lines title 'SA','dictionary.dat' every 7::0 using 1:4 with lines title 'SLU','dictionary.dat' every 7::0 using 1:5 with lines title 'SLS','dictionary.dat' every 7::0 using 1:6 with lines title 'DLU','dictionary.dat' every 7::0 using 1:7 with lines title 'DLS'
set title 'Insert'
plot 'dictionary.dat' every 7::1 using 1:2 with lines title 'UA','dictionary.dat' every 7::1 using 1:3 with lines title 'SA','dictionary.dat' every 7::1 using 1:4 with lines title 'SLU','dictionary.dat' every 7::1 using 1:5 with lines title 'SLS','dictionary.dat' every 7::1 using 1:6 with lines title 'DLU','dictionary.dat' every 7::1 using 1:7 with lines title 'DLS'
set title 'Delete'
plot 'dictionary.dat' every 7::2 using 1:2 with lines title 'UA','dictionary.dat' every 7::2 using 1:3 with lines title 'SA','dictionary.dat' every 7::2 using 1:4 with lines title 'SLU','dictionary.dat' every 7::2 using 1:5 with lines title 'SLS','dictionary.dat' every 7::2 using 1:6 with lines title 'DLU','dictionary.dat' every 7::2 using 1:7 with lines title 'DLS'
set title 'Maximum'
plot 'dictionary.dat' every 7::3 using 1:2 with lines title 'UA','dictionary.dat' every 7::3 using 1:3 with lines title 'SA','dictionary.dat' every 7::3 using 1:4 with lines title 'SLU','dictionary.dat' every 7::3 using 1:5 with lines title 'SLS','dictionary.dat' every 7::3 using 1:6 with lines title 'DLU','dictionary.dat' every 7::3 using 1:7 with lines title 'DLS'
set title 'Minimum'
plot 'dictionary.dat' every 7::4 using 1:2 with lines title 'UA','dictionary.dat' every 7::4 using 1:3 with lines title 'SA','dictionary.dat' every 7::4 using 1:4 with lines title 'SLU','dictionary.dat' every 7::4 using 1:5 with lines title 'SLS','dictionary.dat' every 7::4 using 1:6 with lines title 'DLU','dictionary.dat' every 7::4 using 1:7 with lines title 'DLS'
set title 'Predecessor'
plot 'dictionary.dat' every 7::5 using 1:2 with lines title 'UA','dictionary.dat' every 7::5 using 1:3 with lines title 'SA','dictionary.dat' every 7::5 using 1:4 with lines title 'SLU','dictionary.dat' every 7::5 using 1:5 with lines title 'SLS','dictionary.dat' every 7::5 using 1:6 with lines title 'DLU','dictionary.dat' every 7::5 using 1:7 with lines title 'DLS'
set title 'Successor'
plot 'dictionary.dat' every 7::6 using 1:2 with lines title 'UA','dictionary.dat' every 7::6 using 1:3 with lines title 'SA','dictionary.dat' every 7::6 using 1:4 with lines title 'SLU','dictionary.dat' every 7::6 using 1:5 with lines title 'SLS','dictionary.dat' every 7::6 using 1:6 with lines title 'DLU','dictionary.dat' every 7::6 using 1:7 with lines title 'DLS'
unset logscale y
unset multiplot
