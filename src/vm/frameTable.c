#include "vm/frameTable.h"
#include <stdio.h>
#include "threads/thread.h"
#include "threads/synch.h"
#include "threads/malloc.h"
#include "kernel/list.h"
#include "threads/palloc.h"
#include "vm/pageTable.h"

//Se incializan elementos necesarios para la frame table
void init_frameTable(){

  list_init (&frame_table);
}

//Se obtiene la pagina y se guarda en la lista frame_table
void *get_pageFT(enum palloc_flags pFlags){
  //Allocate memory for the frame table entry
  struct frame_table_entry *FTE = malloc(sizeof(struct frame_table_entry));
  //Se obtiene la virtual address de una free page 
  void *va = palloc_get_page(pFlags);
  //Se guardan la información en la frame table entry
  FTE->frame = va;
  FTE->owner = thread_current();
  list_push_back(&frame_table, &FTE->frame_elem);
  return va;
}

//Remueve el frame de la lista de frames
void free_frameTable(void *frame){
  //Se verifica que no se tenga vacía la frame table
  ASSERT(!list_empty(&frame_table));
  //Se libera la página 
  palloc_free_page (frame);
  struct frame_table_entry *felem;
  struct list_elem *element;
  //Se itera en la frame table para encontrar y remover de el frame de la frame table
  for(element = list_begin(&frame_table);element != list_end(&frame_table);
  	  element = list_next(element)){
    felem = list_entry(element, struct frame_table_entry, frame_elem);
    if(felem->frame == frame){
      list_remove(element);
      return;
    }
  }
}