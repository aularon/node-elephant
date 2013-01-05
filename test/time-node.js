var max = process.argv[2]? parseInt(process.argv[2]): 1000*1000;//10*
var mh3 = require('../').mh3;
//console.log(mh3("haha"),mh3("dada"));d()

var Store = function() {
	this.hash = {};
	this.stats = {
		added: 0,
		dup: 0
	}
}
Store.prototype.memorize = function(str) {
	var hash = mh3(str);
	if(this.hash[hash]) {
		++this.stats.dup;
		return false;
	}
	this.hash[hash] = true;
	++this.stats.added;
	return true;
}
Store.prototype.remember = function(str) {
	var hash = mh3(str);
	return !!this.hash[hash];
}

var s = new Store();

var stats = {
	found: 0,
	miss: 0
}
for(var i=0; i<max; i++) { s.memorize(Math.random()+''); }

for(var i=0; i<max; i++) {
	if(s.remember(Math.random()+'')) {
		++stats.found;
	} else {
		++stats.miss;
	}
}

//console.log(stats, s.stats, process.memoryUsage())