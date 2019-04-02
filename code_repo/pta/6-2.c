List MakeEmpty(){
	List L=(List)malloc(sizeof(struct LNode));
	L->Last=0;
	return L;
}

Position Find( List L, ElementType X ){
	int i;
	for(i=0;i<L->Last;i++){
		if(L->Data[i]==X)return i;
	}
	return ERROR;
}
bool Insert( List L, ElementType X, Position P ){
	int i;
	if(L->Last==MAXSIZE){
		printf("FULL");
		return false;
	}
	if(P<0||P>L->Last){
		printf("ILLEGAL POSITION");
		return false;
	}
	for(i=L->Last;i>P;i--){
		L->Data[i]=L->Data[i-1];
	}
	L->Data[P]=X;
	L->Last++;
	return true;
}
bool Delete( List L, Position P ){
	int i;
	if(P<0||P>=L->Last){
		printf("POSITION %d EMPTY",P);
		return false;
	}
	for(i=P;i<L->Last-1;i--){
		L->Data[i]=L->Data[i+1];
	}
	L->Last--;
	return true;
}