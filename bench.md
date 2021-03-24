Benchmark was slightly screwed with:
> `unsigned int` as the iterator (removed warnings because `auto` is weird, thanks GCC)
> custom logging

**Build commands**
```
g++ -c -Wall -g speedtest.cpp
g++ -g -o speedtest-unoptimized speedtest.o
./speedtest-unoptimized

g++ -c -O2 -Wall -g speedtest.cpp
g++ -g -o speedtest-optimized speedtest.o
./speedtest-optimized
```

__**AMD Ryzen 7 1700X @ 4.1GHz**__
> Running in Ubuntu 18.04 Docker container on Windows (couldn't be fucked to use Visual Studio)
> Compiler: GCC 7.5.0

**Unoptimized Results**
```
std::   392.249 ms 398.021 ms 439.550 ms 410.178 ms 398.570 ms 413.471 ms 448.726 ms 377.056 ms 403.071 ms 407.615 ms
qmath:: 325.916 ms 357.680 ms 262.490 ms 363.707 ms 321.490 ms 355.107 ms 299.554 ms 308.143 ms 306.475 ms 308.552 ms
```

**Optimized Results**
```
std::   -33.096 ms -55.105 ms -55.622 ms -38.638 ms -32.804 ms -58.523 ms -34.770 ms -38.312 ms -43.539 ms -47.197 ms
qmath:: 114.376 ms 113.490 ms 121.379 ms 115.644 ms 119.188 ms 114.064 ms 115.384 ms 112.967 ms 114.111 ms 112.561 ms
```

__**Intel Core2Duo E8400 @ 3.1GHz**__
> Running on Linux Mint 19.1
> Compiler: GCC 7.5.0

**Unoptimized Results**
```
std::   615.140 ms 612.924 ms 621.468 ms 613.260 ms 614.600 ms 613.113 ms 615.057 ms 615.936 ms 610.189 ms 622.851 ms
qmath:: 823.874 ms 818.769 ms 818.830 ms 810.404 ms 818.456 ms 818.649 ms 817.905 ms 818.251 ms 818.554 ms 817.809 ms
```

**Optimized Results**
```
std::   -204.621 ms -204.137 ms -199.368 ms -204.249 ms -203.984 ms -204.230 ms -207.489 ms -204.406 ms -206.652 ms -203.749 ms
qmath::  196.243 ms  197.930 ms  195.921 ms  196.300 ms  196.610 ms  196.033 ms  197.290 ms  196.391 ms  197.055 ms  195.673 ms
```

__**Intel Xeon E5-2620 @ 2.4GHz**__
> Running on Ubuntu 18.04 Server
> Compiler: GCC 7.5.0

**Unoptimized Results**
```
std::   544.868 ms 609.873 ms 629.048 ms 513.261 ms 740.134 ms 349.737 ms 594.561 ms 596.180 ms 607.058 ms 467.871 ms
qmath:: 481.458 ms 467.838 ms 463.723 ms 587.957 ms 508.514 ms 488.360 ms 503.392 ms 465.477 ms 465.898 ms 501.536 ms
```

**Optimized Results**
```
std::   19.427 ms  -22.852 ms  34.548 ms -20.165 ms -79.804 ms -18.288 ms -20.089 ms -15.745 ms -14.580 ms -13.174 ms
qmath:: 141.239 ms 143.582 ms 132.756 ms 175.315 ms 142.120 ms 136.709 ms 138.343 ms 136.209 ms 133.517 ms 146.100 ms
```

__**AMD Ryzen 7 1700X @ 4.1GHz**__
> Running Windows 10 20H2
> Compiler: Visual Studio 2019 64 bit

Notes:
> ported the library to use a header file (will pull request soon)

**Unoptimized Results**
```
std::   652.668 ms 682.827 ms 700.893 ms 652.387 ms 646.259 ms 652.548 ms 665.363 ms 648.780 ms 646.225 ms 648.635 ms
qmath:: 579.114 ms 560.223 ms 577.879 ms 569.571 ms 584.219 ms 605.949 ms 592.836 ms 623.810 ms 634.707 ms 613.598 ms
```

**Optimized Results**
```
std::    83.198 ms  84.763 ms  84.963 ms  80.975 ms  88.956 ms  88.125 ms  87.567 ms  87.649 ms  88.908 ms  92.004 ms
qmath:: 150.142 ms 149.967 ms 149.870 ms 149.701 ms 150.177 ms 149.882 ms 149.823 ms 149.884 ms 149.817 ms 150.179 ms
```
