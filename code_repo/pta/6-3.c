int Length( List L ){
  int len=0;
  List q=L;
  while(q){
    len++;
    q=q->Next;
  }
  return len;
}