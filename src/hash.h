#include "linked-list.h"

/* THIS IMPLEMENTATION OF THE HASH FUCNTION TYPE IS TEMPORARY
 *
 * m : size of the table
 * */
typedef struct {
        unsigned int m;
} hashf_dtype;

/*
 * n : maount of elements inside the hashtable
 * m : hash table size
 * hash_func : vector of size sizeof(int) in bits used to compute the hash function
 * 		- this vector only contains integers between 0 and m-1 
 * */
typedef struct {
        List* hash_table;
        unsigned int m;
	unsigned int n;
	unsigned int N;
	hashf_dtype* hashf;

} dict_dtype;

dict_dtype* make_dictionary();
/*
 * The following operations return 0 if they succeed, 0 otherwise
 *
 * The following operations act on the input dictionary, assuming that it is not a NULL pointer
 * */
unsigned int insert(dict_dtype* dict, unsigned int element);
unsigned int delete(dict_dtype* dict,unsigned int element);
unsigned int lookup(dict_dtype* dict,unsigned int element);
