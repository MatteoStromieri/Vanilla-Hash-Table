#include <stdio.h>
#include <stdlib.h>
#include "miller-rabin-test.h"
#include "hash.h"

unsigned int compute_hash(hashf_dtype* hashf, unsigned int element);

/*
 * Creates an empty dictionary
 * m = 2 is the default prime setting 
 * */
dict_dtype* make_dictionary(){
	dict_dtype* dict = (dict_dtype*) malloc(sizeof(dict_dtype));
	dict -> m = 2;
	dict -> n = 0;
	dict -> N = 0;
	dict -> hashf = (hashf_dtype*) malloc(sizeof(hashf_dtype));
	dict -> hashf -> m = dict -> m;
	dict -> hash_table = (List*) malloc((dict->m)*sizeof(List));
	
	for(int i = 0; i < dict -> m; i++){
		dict -> hash_table[i].head = NULL;
	}
	
	return dict;
}

unsigned int compute_hash(hashf_dtype* hashf, unsigned int element){
	return element % (hashf -> m);
}

/* Returns 1 if element is contained inside the dictionary
 *
 * Returns 0 otherwise
 * */
unsigned int lookup(dict_dtype* dict, unsigned int element){
	unsigned int hash = compute_hash(dict->hashf,element);
	
	return find(element, &(dict -> hash_table[hash]));	
}

unsigned int insert(dict_dtype* dict, unsigned int element){
	
	if(lookup(dict,element))
		return 1;
	
	dict -> n ++;
	if (dict -> n > dict -> N){
		// N = 2N
		dict -> N = 2*(dict -> N);
		// find a new prime m between N and 2N
		unsigned int old_m = dict -> m;
		dict -> m = prime(dict -> N, 2*(dict -> N));
		// update the hash function
		dict -> hashf -> m = dict -> m;
		// malloc a new list of linked lists
		List* new_hash_table = (List*) malloc((dict->m)*sizeof(List)); 
		for(int i = 0; i < dict -> m; i++){
                	new_hash_table[i].head = NULL;
        	}
		// re-map all the elements inside the dictionary
		Node* node, *new_node;
		for (int i = 0; i < old_m; i++){
			node = dict -> hash_table[i].head;
		
			while(node != NULL){
				new_node = node;
				node = node -> next;
				new_node -> next = NULL;
				add_node(new_node,&new_hash_table[compute_hash(dict->hashf,new_node->data)]);

			}
		}
	      dict -> hash_table = new_hash_table;	
	}
	unsigned int hash = compute_hash(dict->hashf,element);
	add(element, &(dict -> hash_table[hash]));
	
	return 1;
}

unsigned int delete(dict_dtype* dict, unsigned int element){

        if(!lookup(dict,element))
                return 1;

        dict -> n --;
        if (dict -> n < (dict -> N)/4){
                // N = 2N
                dict -> N = (dict -> N)/2;
                // find a new prime m between N and 2N
                unsigned int old_m = dict -> m;
                dict -> m = prime(dict -> N, 2*(dict -> N));
                // update the hash function
                dict -> hashf -> m = dict -> m;
                // malloc a new list of linked lists
                List* new_hash_table = (List*) malloc((dict->m)*sizeof(List));
                for(int i = 0; i < dict -> m; i++){
                        new_hash_table[i].head = NULL;
                }
                // re-map all the elements inside the dictionary
                Node* node, *new_node;
                for (int i = 0; i < old_m; i++){
                        node = dict -> hash_table[i].head;

                        while(node != NULL){
                                new_node = node;
                                node = node -> next;
                                new_node -> next = NULL;
                                add_node(new_node,&new_hash_table[compute_hash(dict->hashf,new_node->data)]);

                        }
                }
              dict -> hash_table = new_hash_table;
        }
        unsigned int hash = compute_hash(dict->hashf,element);
        delete_node(element, &(dict -> hash_table[hash]));

        return 1;
}

