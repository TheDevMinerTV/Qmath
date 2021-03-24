echo "UNOPTIMIZED"

g++ -c -g speedtest.cpp
g++ -g -o speedtest speedtest.o
./speedtest

echo "OPTIMIZED"

g++ -O2 -c -g speedtest.cpp
g++ -g -o speedtest speedtest.o
./speedtest
