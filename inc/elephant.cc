#include "elephant.h"
#include <sparsehash/sparse_hash_map>
#include "MH3/MurmurHash3.h"


using google::sparse_hash_map;

uint32_t mh3(char* key) {
	uint32_t out;
	MurmurHash3_x86_32(key, strlen(key), &out);
	
	return out;
}

Elephant::Elephant() {
	stats_added = 0;
	stats_duplicates = 0;
}

bool Elephant::remember(char* key) {
	uint32_t hash = mh3(key);
	
	//cout<<map.count(hash)<<endl;
	return map.count(hash)>0;
}

bool Elephant::memorize(char* key) {
	uint32_t hash = mh3(key);
	//cout<<key<<' '<<out<<endl;
	if(map[hash]) {
		++stats_duplicates;
		return true;
	} else {
		++stats_added;
		map[hash]=true;
		return false;
	}
}

uint32_t Elephant::get_stats_added() { return stats_added; }
uint32_t Elephant::get_stats_duplicates() { return stats_duplicates; }



/*
void print() {
	cout<<"size() "<<map.size()<<endl;
	//cout<<"max_size() "<<map.max_size()<<endl;
	cout<<"stats_added "<<stats_added<<endl;
	cout<<"stats_duplicates "<<stats_duplicates<<endl;
}*/

