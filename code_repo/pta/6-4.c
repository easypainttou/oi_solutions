ElementType FindKth( List L, int K ){
  int i=0;
  while(L){
    i++;
    if(i==K)return L->Data;
    L=L->Next;
  }
  return ERROR;
}