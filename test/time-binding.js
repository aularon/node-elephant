var elephant = require('../');

var ele = new elephant.Elephant();

var stats = {
	found: 0,
	miss: 0
}
var max = process.argv[2]? parseInt(process.argv[2]): 1000*1000;//10*

for(var i=0; i<max; i++) { ele.memorize(Math.random()); }
//''+Math.random()+Math.random()+Math.random()+Math.random()+Math.random()+Math.random()+Math.random()+Math.random()

for(var i=0; i<max; i++) {
	if(ele.remember(Math.random()+'')) {
		++stats.found;
	} else {
		++stats.miss;
	}
}

//console.log(stats, ele.stats(), process.memoryUsage())