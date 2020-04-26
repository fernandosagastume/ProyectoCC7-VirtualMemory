#ifndef PAGE_H
#define PAGE_H

#include "filesys/file.h"
#include "threads/palloc.h"
#include "lib/kernel/hash.h"

/* Supplemental page table element. */
struct sup_page_table_entry {

  void* user_vaddr; //User virtual address asociada a la SPTE
  bool dirty; //Verdadero si se escribió en la página
  bool accessed; //Verdadero si la página fue accesada para lectura/escritura.
  struct hash_elem spte_elem; 	
};

/*Función que busca dada una hash table y un user virtual address
  la SPTE asociada a la misma*/
struct sup_page_table_entry* 
get_SPTE(void* user_vaddr, struct hash* hash_table);

//----------------------------------------------------------------------
/*Funciones utilizadas y requeridas para incializar el hash table que 
alberga la suplemetal page table de cada thread*/

/* Computes and returns the hash value for hash element E, given	
   auxiliary data AUX. */
unsigned SPTE_hash (const struct hash_elem* e, void* aux);

/* Compares the value of two hash elements A and B, given
   auxiliary data AUX.  Returns true if A is less than B, or
   false if A is greater than or equal to B. */
bool SPTE_less (const struct hash_elem* a,
               	const struct hash_elem* b,
	       		void* aux);
//----------------------------------------------------------------------

#endif /* vm/pageTable.h */