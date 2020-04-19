#ifndef PAGE_H
#define PAGE_H

#include "filesys/filesys.h"
#include "threads/palloc.h"
#include <list.h>

/* Supplemental page table element. */
struct sup_page_table_entry {

  uint32_t* user_vaddr;
  uint64_t access_time;
  bool dirty;
  bool accessed;
};


#endif /* vm/pageTable.h */