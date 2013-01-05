#include <iostream>
#include <stdint.h>

#include "../inc/elephant.h"


using std::cout;
using std::endl;

void gen_random(char *s, const int len) {
    static const char alphanum[] = "01"
        /*"0123456789"
        "!@#$%^&*(){}~|\\/-+[]="
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"*/;

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}


int main(int argc, char* argv[]) {
	uint32_t iterations = (argc>1)? atoi(argv[1]) : 1*1000*1000;
	//cout<<iterations<<endl;
	Elephant e;

	char str[] = "01234567890123456789";
	uint32_t found=0, miss=0, i=0;
	for(; i<iterations; i++) {
		gen_random(str, 20);
		e.memorize(str);
	}
	
	
	for(i=0; i<iterations; i++) {
		gen_random(str, 20);
		if (e.remember(str)) { ++found; }
		else { ++miss; }
	}
	
	//s.print();
	/*
	cout<<"added "<<e.get_stats_added()<<endl;
	cout<<"duplicates "<<e.get_stats_duplicates()<<endl;
	cout<<"miss "<<miss<<endl;
	cout<<"found "<<found<<endl;*/

	return 0;
}