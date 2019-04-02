List Reverse( List L ){
  List p=NULL,q,r=L;
  while(r){
    q=r,r=r->Next,q->Next=p,p=q;
  }
  return q;
}