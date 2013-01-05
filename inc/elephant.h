#include <sparsehash/sparse_hash_map>
//#include "MH3/MurmurHash3.h"

#ifndef _ELEPHANT_H_
#define _ELEPHANT_H_

using google::sparse_hash_map;

uint32_t mh3(char* key);

class Elephant {
	private:
	sparse_hash_map<uint32_t, bool> map;
	uint32_t stats_added;
	uint32_t stats_duplicates;
	
	public:
	Elephant();
	bool remember(char* key);
	bool memorize(char* key);

	uint32_t get_stats_added();
	uint32_t get_stats_duplicates();
};


#endif // _ELEPHANT_H_