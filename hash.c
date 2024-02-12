#include <stdio.h>
#include <stdlib.h>
#include "miller-rabin-test.h"
#include "hash.h"

/*
 * Creates an empty dictionary
 * m = 2 is the default prime setting 
 * */
dict_dtype* make_dictionary(){
	dict_dtype* dict = (dict_dtype*) malloc(sizeof(dict));
	dict -> m = 2;
	dict -> n = 0;
	
	for(int i = 0; i < INT_SIZE; i++){
		(dict -> hash_func)[i] = 1;
	}
	
	return dict;
}




