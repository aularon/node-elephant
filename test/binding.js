var elephant = require('../')

var obj = new elephant.Elephant();

console.log(obj.memorize("hello"));	// false: first time to be seen, increases stats_added by 1
console.log(obj.memorize("hello"));	// true: seen before, increases stats_duplicates by 1
console.log(obj.remember("hello"));	// true: remembered, told before to memorize it
console.log(obj.remember("hi"));	// false: not remembered, as has not been told to memorize it
console.log(obj.remember("hi"));	// false: still not remembered, of course

console.log(obj.stats());			// { added: 1, duplicates: 1 }

console.log('Success, because you can read this : )');
