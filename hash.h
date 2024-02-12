#define INT_SIZE 32

/*
 * n : maount of elements inside the hashtable
 * m : hash table size
 * hash_func : vector of size sizeof(int) in bits used to compute the hash function
 * 		- this vector only contains integers between 0 and m-1 
 * */
typedef struct {
        int** hash_table;
        int m;
	int n;
	int hash_func[INT_SIZE];

} dict_dtype;

dict_dtype* make_dictionary();
