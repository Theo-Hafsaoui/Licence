#include "ts.h"


ts * tsymb = NULL;
static int mem_offset = 33;


void ts_ajouter_id(char *id, int size)
{
  ts *new = malloc(sizeof(ts));
  new->id = malloc(strlen(id)+1);
  strcpy(new->id, id);
  new->adr = mem_offset;
  new->size = size;
  mem_offset += size;
  new->next = tsymb;
  tsymb = new;
  
}

ts* ts_retrouver_id(char *id)
{
  ts *t = tsymb;
  while (t!=NULL){
    if (strcmp(t->id, id)==0){
      return t;
    }
    t = t->next;
  }
  return (ts*)0;
}

void ts_free_table()
{
  ts *next, *t = tsymb;

  while (t!=NULL){
    next = t->next;
    free(t->id);
    free(t);
    t = next;
  }
}

void ts_print()
{
  ts *t = tsymb;
  if (t!=NULL){
    printf("{%s : %d}", t->id, t->adr);
    t = t->next;
  }
  while (t!=NULL){
    printf("-->{%s : %d}", t->id, t->adr);
    t = t->next;
  }

}
