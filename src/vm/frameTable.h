#ifndef VM_FRAME_TABLE_H
#define VM_FRAME_TABLE_H
#include "threads/thread.h"
#include "threads/palloc.h"

//a list of frame_table_entry as the page table
struct list frame_table;

struct frame_table_entry {
	void * frame;
	struct thread* owner;
	struct list_elem frame_elem;	
};

//Se incializan elementos necesarios (Definida en vm/frameTable.c)
void init_frameTable(void);
//Se obtiene la pagina y se guarda en la lista frame_table
void *get_pageFT(enum palloc_flags);
//Remueve los frames de la frame_table (Definida en vm/frameTable.c)
void free_frameTable(void *);


#endif /* vm/frameTable.h */