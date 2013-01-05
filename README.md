[node-elephant](https://github.com/aularon/node-elephant)
=============

![Elephant Logo](https://raw.github.com/aularon/node-elephant/master/doc/logo.png)


A fast & memory-efficient data structure that cat tell if it saw a string before

## Summary
In case you need a fast, memory-efficient data structure that would remember whether or not it had seen a string before, for example you are running through a list of filename with possible duplicates that you do not want to double-process, or through long list of emails/GUIDs with possible duplicate that you wanna deal with, here is the module for you.

The Node.js/c++ binding is 2/3 times faster, and uses 6 times less memory than a JavaScript implementation.
The pure c++ is even faster and uses 8 times less memory than the nodejs binding, that is 200% faster than pure JavaScript, and 50 times (5000%) more memory-efficient*. Check the [Time Table](#time-table) for details.

_* For some reason arguments passed from JavaScript to c++ lingers in memory, if you have a way to set them free let me know_

## Prerequisites
You will need [google sparsehash](https://code.google.com/p/sparsehash/downloads/list), under Ubuntu you can do `sudo apt-get install sparsehash`.

## Usage
Check the test/time-binding.js file for an example usage.

## Example
```javascript
var elephant = require('elephant')

var obj = new elephant.Elephant();

console.log(obj.memorize("hello"));	// false: first time to be seen, increases stats_added by 1
console.log(obj.memorize("hello"));	// true: seen before, increases stats_duplicates by 1
console.log(obj.remember("hello"));	// true: remembered, told before to memorize it
console.log(obj.remember("hi"));	// false: not remembered, as has not been told to memorize it
console.log(obj.remember("hi"));	// false: still not remembered, of course

console.log(obj.stats());			// { added: 1, duplicates: 1 }

console.log('Success, because you can read this : )');
```

## API
* `bool .memorize("string")` tells the elephant to memorize a string, returns `true` if the string was seen before, and `false` otherwise.
* `bool .remember("string")` ask the elephant whether it remembers a string (has seen, aka told to memorize that string before), returns `true` if the string was seen before, and `false` otherwise.
* `object .stats()` returns some stats.


## Time Table
Numbers between (brackets) refer to the difference between current cell value and the one to its left.


<table style="font-family: mono;"><tr><th>Command being timed</th><td>"build/time-native 5000000"</td><td>"node test/time-binding.js 5000000"</td><td>"node test/time-node.js 5000000"</td></tr><tr><th>User time (seconds)</th><td>10.27</td><td>14.6 (142%)</td><td>22.18 (152%)</td></tr><tr><th>System time (seconds)</th><td>0</td><td>0.1 (Infinity%)</td><td>0.41 (410%)</td></tr><tr><th>Percent of CPU this job got</th><td>99%</td><td>100%</td><td>100%</td></tr><tr style="color: darkblue; text-decoration: underline"><th>Elapsed (wall clock) time (h:mm:ss or m:ss)</th><td>0:10.31</td><td>0:14.65</td><td>0:22.53</td></tr><tr><th>Average shared text size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Average unshared data size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Average stack size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Average total size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr style="color: darkblue; text-decoration: underline"><th>Maximum resident set size (kbytes)</th><td>44576</td><td>364368 (817%)</td><td>2188960 (601%)</td></tr><tr><th>Average resident set size (kbytes)</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Major (requiring I/O) page faults</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Minor (reclaiming a frame) page faults</th><td>2997</td><td>23614 (788%)</td><td>167480 (709%)</td></tr><tr><th>Voluntary context switches</th><td>1</td><td>14790 (1479000%)</td><td>19914 (135%)</td></tr><tr><th>Involuntary context switches</th><td>872</td><td>1253 (144%)</td><td>2008 (160%)</td></tr><tr><th>Swaps</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>File system inputs</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>File system outputs</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Socket messages sent</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Socket messages received</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Signals delivered</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr><tr><th>Page size (bytes)</th><td>4096</td><td>4096 (=)</td><td>4096 (=)</td></tr><tr><th>Exit status</th><td>0</td><td>0 (=)</td><td>0 (=)</td></tr></table>


## Roadmap
* Add more hashes options, besides the default 32-bit MurmurHash3, probably FNV-1 32-bit & 64-bit..

## Copyright & License
© 2013 Hasan Arous. All rights reserved.

Used libraries are copyrighted to their owners, as seen in files comments.

[Mozilla Public License Version 2.0](http://www.mozilla.org/MPL/2.0/)