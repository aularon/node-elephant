var elephant = require('../')

//console.log(elephant.hello())



var obj = new elephant.Elephant();

console.log(obj.memorize("hello"));
console.log(obj.memorize("hello"));
console.log(obj.remember("hello"));
console.log(obj.remember("hi"));
console.log(obj.remember("hi"));

console.log(obj.stats());

console.log('Success, because you can read this : )')