#include<stdlib.h>

#define COLLECTION_ERR_NULL -1
#define COLLECTION_MEM_ERR -2

typedef struct citem_t {
   void *object;
   struct citem_t *prev;
   struct citem_t *next;
} collection_item_t;

typedef struct collection_t {
  int size;
  collection_item_t *first;
  collection_item_t *last;
} *Collection;

// allocates memory for and initialized a collection
Collection new_collection();

// frees memory used by the collection object
void destroy_collection(Collection);

// adds a new item to the collection, returns the # of items
// in the collection after the add completes
int collection_add_item(Collection, void *);

// returns a pointer to the item at the ith position in
//  the collection
void * collection_item_at(Collection, int);

// removes the item at the ith position in the collection
void collection_remove_at(Collection, int);

// returns the objects in the collection as an array
void ** collection_as_array(Collection);
