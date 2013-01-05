node-elephant
=============

![Elephant Logo](https://raw.github.com/aularon/node-elephant/master/doc/logo.png)

A fast &amp; memory-efficient data structure that cat tell if it saw a string before

## Prerequisites
You will need [google sparsehash](https://code.google.com/p/sparsehash/downloads/list), under ubuntu you can do `sudo apt-get install sparsehash`.

## Time Table
Numbers between (brackets) refer to the difference between current cell value and the one to its left.


<table style="font-family: mono;"><tr><th>Command being timed</th><td>"build/time-native 5000000"</td><td>"node test/time-binding.js 5000000"</td><td>"node test/time-node.js 5000000"</td></tr><tr><th>User time (seconds)</th><td>10.27</td><td>14.6 (142%)</td><td>22.18 (152%)</td></tr><tr><th>System time (seconds)</th><td>0</td><td>0.1 (Infinity%)</td><td>0.41 (410%)</td></tr><tr><th>Percent of CPU this job got</th><td>99%</td><td>100%</td><td>100%</td></tr><tr style="color: darkblue; text-decoration: underline"><th>Elapsed (wall clock) time (h:mm:ss or m:ss)</th><td>0:10.31</td><td>0:14.65</td><td>0:22.53</td></tr><tr><th>Average shared text size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Average unshared data size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Average stack size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Average total size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr style="color: darkblue; text-decoration: underline"><th>Maximum resident set size (kbytes)</th><td>44576</td><td>364368 (817%)</td><td>2188960 (601%)</td></tr><tr><th>Average resident set size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Major (requiring I/O) page faults</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Minor (reclaiming a frame) page faults</th><td>2997</td><td>23614 (788%)</td><td>167480 (709%)</td></tr><tr><th>Voluntary context switches</th><td>1</td><td>14790 (1479000%)</td><td>19914 (135%)</td></tr><tr><th>Involuntary context switches</th><td>872</td><td>1253 (144%)</td><td>2008 (160%)</td></tr><tr><th>Swaps</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>File system inputs</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>File system outputs</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Socket messages sent</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Socket messages received</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Signals delivered</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Page size (bytes)</th><td>4096</td><td>4096 (=)</td><td>4096 (=)</td></tr><tr><th>Exit status</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr></table>
