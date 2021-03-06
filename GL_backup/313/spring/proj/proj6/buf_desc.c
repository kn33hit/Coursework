// gcc -o test1 -m32 -g test1.c buf_desc.c buf_desc.h
// neh patel
#include "buf_desc.h" 
//  THEN DO HEX DUMP (GO FIGURE) 


static int total;
static int filledSpace;

void init_buf_desc(){
  total = 0;
  filledSpace = 0;
  int i;
  buf_desc *current; // pointer to make and keep track
  head = (buf_desc *)malloc( sizeof(buf_desc) ); // use mallloc to make head
  assert( head != NULL);
  current = head; // give the address of head to current 
  total++;
  // creating the 10 structs including head for now
  for( i = 0; i < 9; i++){
    // intialize a struct through malloc
    buf_desc *buf = (buf_desc *)malloc(sizeof(buf_desc) );
    assert( buf != NULL);
    // we give pointer in current the address of the new node we made
    current->next = buf;
    // assign the new address, as the current address
    current = current->next;
    // so that when the next time it comes around it works fine 
    total++;
  }
}

buf_desc* new_buf_desc(){
  buf_desc *current;
  // assign the current with head
  int check = getLength(head);
  if(check != 0){
    current = head;
    // make the next one the head, current now holds precious one
    head = head->next;
  }else{
    head = (buf_desc *)malloc( sizeof(buf_desc) ); // use mallloc to make head
    assert( head != NULL);
    current = head; // give the address of head to current                   
    total++;
    int i;
    // creating the 10 structs including head for now                        
    for( i = 0; i < 9; i++){
      // intialize a struct through malloc                                   
      buf_desc *buf = (buf_desc *)malloc(sizeof(buf_desc) );
      assert( buf != NULL);
      // we give pointer in current the address of the new node we made    
      current->next = buf;
      // assign the new address, as the current address                       
      current = current->next;
      // so that when the next time it comes around it works fine          
      total++;
    }
    current = head;
    head = head->next;
  }
  return current;
}

void del_buf_desc(buf_desc *buf){
  buf_desc *tempHead;
  // zero out the previous values passed in
  tempHead = buf;
  while(buf != NULL){
    buf->buffer = NULL;
    buf->len = 0;
    buf = buf->next;
  }
  buf = head;
  // the new head will be tempHead assigned earlier
  head = tempHead;
}

void clean_buf_desc(){
  // dont go forgetting filledSpace now, mate
  int i;
  int Heretotal = getLength(head);
  if(Heretotal > 10){
    for(i = 0; i < 10; i++){
      buf_desc *current;
      current = head;
      head = current->next;
      free(current);
      Heretotal--;
      total--;
    }
  }
}

void dump_buf_desc(){
  buf_desc *current;
  current = head;
  int freeSpace = getLength(head);
  printf("Total allocated entries: %d\n" , total);
  printf("Total available entries: %d\n" , freeSpace);
  printf("Addresses of available buf_structs: \n");
  while(current !=NULL){
    printf("    %p\n",current);
    current = current->next;
  }
}


void hexdump_buf_desc(buf_desc *buf){
  unsigned int i, j;
  char temp;
  int totalLen;

  while(buf != NULL){
    
    for(i = 0; i < buf->len + ((buf->len % HEXDUMP_COLS) ? (HEXDUMP_COLS - buf->len % HEXDUMP_COLS) : 0); i++)
      {
	/* print offset */
	if(i % HEXDUMP_COLS == 0)
	  {
	    printf("0x%06x: ", i);
	  }
	
	/* print hex data */
	if(i < buf->len)
	  {
	    printf("%02x ", 0xFF & ((char*)buf->buffer)[i]);
	  }
	else /* end of block, just aligning for ASCII dump */
	  {
	    printf("   ");
	  }
	
	/* print ASCII dump */
	if(i % HEXDUMP_COLS == (HEXDUMP_COLS - 1))
	  {
	    for(j = i - (HEXDUMP_COLS - 1); j <= i; j++)
	      {
		if(j >= buf->len) /* end of block, not really printing */
		  {
		    putchar(' ');
		  }
		else if(isprint(((char*)buf->buffer)[j])) /* printable char */
		  {
		    putchar(0xFF & ((char*)buf->buffer)[j]);
		  }
		else /* other char */
		  {
		    putchar('.');
		  }
	      }
	    putchar('\n');
	  }
      }
    buf = buf->next;
  }
}



int getLength(buf_desc *buf){
  int count = 0;
  while(buf != NULL){
    count++;
    buf = buf->next;
  }
  return count;
}
