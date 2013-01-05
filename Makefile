NODE_GYP = /usr/lib/nodejs/npm/bin/node-gyp-bin/node-gyp
TIME=`which time`
iterations = 1000000

gyp:
	/usr/lib/nodejs/npm/bin/node-gyp-bin/node-gyp clean configure build

test-binding: build/Release/elephant.node
	node test/binding.js

test-time-native:
	c++ test/time-native.cc inc/elephant.cc inc/MH3/MurmurHash3.cc -o build/time-native
	$(TIME) -v build/time-native ${iterations} 2>&1 | tee build/test-time-native

test-time-binding: build/Release/elephant.node
	$(TIME) -v node test/time-binding.js ${iterations} 2>&1 | tee build/test-time-binding

test-time-node: build/Release/elephant.node
	$(TIME) -v node test/time-node.js ${iterations} 2>&1 | tee build/test-time-node

test-time: test-time-native test-time-binding test-time-node

test-time-html:
	node test/time-output-format.js build/test-time-native build/test-time-binding build/test-time-node | tee build/test-time.html


clean:
	${NODE_GYP} clean



#build/Release/elephant.node: gyp