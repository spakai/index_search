uname -a
Linux prakash-ThinkPad-SL410 3.19.0-16-generic #16-Ubuntu SMP Thu Apr 30 16:13:00 UTC 2015 i686 i686 i686 GNU/Linux

1 million records in Index with single thread search

Primary Tree Index Exact Match Time taken = 177.93ms for 50000 transactions

Primary Tree Index Exact Match TPS = 281009
[       OK ] IndexBenchMarkTest.PrimaryTreeIndexExactMatch (26110 ms)
[ RUN      ] IndexBenchMarkTest.PrimaryHashIndexExactMatch

Primary Hash Index Exact Match Time taken = 43.296ms for 50000 transactions

Primary Hash Index Exact Match TPS = 1154841
[       OK ] IndexBenchMarkTest.PrimaryHashIndexExactMatch (26008 ms)
[ RUN      ] IndexBenchMarkTest.PrimaryTreeIndexBestMatch

Primary Tree Index Best Match Time taken = 191.299ms for 50000 transactions

Primary Tree Index Best Match TPS = 261370
[       OK ] IndexBenchMarkTest.PrimaryTreeIndexBestMatch (26166 ms)
[----------] 3 tests from IndexBenchMarkTest (79351 ms total)

[----------] 1 test from IndexBenchMarkTestForMultiMaps
[ RUN      ] IndexBenchMarkTestForMultiMaps.PrimaryTreeMultiMapIndexExactMatch

Primary Tree MultiIndex Exact Match Time taken = 108.672ms for 50000 transactions

Primary Tree MultiIndex Exact Match TPS = 460100
[       OK ] IndexBenchMarkTestForMultiMaps.PrimaryTreeMultiMapIndexExactMatch (13607 ms)
[----------] 1 test from IndexBenchMarkTestForMultiMaps (13608 ms total)

