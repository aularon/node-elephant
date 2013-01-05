var fs = require('fs'),
	util = require('util');

var textToObject = function (text) {
	var obj = {}
	text.trim().replace(/\s*\n\s*/g, '\n').replace(/(.+): (.+)/g, function(a, b, c) {
		obj[b] = (c.search(/^\d+(?:\.\d+)?$/)!=-1)? parseFloat(c): c;
	});
	

	return obj;


}

var all = []
for(var i=2; i<process.argv.length; ++i) {
	var res = textToObject(fs.readFileSync(process.argv[i], 'utf8'));
	all.push(res);
}

var getHTML = function(arr) {
	var html = '<table style="font-family: mono;">';
	for(var i in arr[0]) {
		html += '<tr>';

		html += util.format('<th>%s</th><td>%s</td>', i, arr[0][i]);
		for(var k=1; k<arr.length; ++k) {
			var cell = arr[k][i];
			if('number'==typeof cell) {
				cell += util.format(' (%s)', (arr[k][i]==arr[k-1][i])? '=':
					Math.round(arr[k][i]*100/arr[k-1][i])+'%');
			}
			html += util.format('<td>%s</td>', cell);
		}

		html += '</tr>';
	}
	html += '</table>';

	return html;
}

console.log(getHTML(all))