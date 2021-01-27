
template <class Type>
void siftDown( Type R[], int pos, int size )
{ 	int child;
  	Type tmp = R[ pos ];
	    
  	for( ; pos * 2 + 1 < size; pos = child )
	{  child = pos * 2 + 1;
	    if( child != size - 1 && R[ child + 1 ] > R[ child ] )
	         child++;							// ѡȡ�������ӵĴ���							
	    if( R[ child ] > tmp )   R[ pos ] = R[ child ];  
		else  break;
	}
  	R[ pos ] = tmp;
}
// ���ô���ѣ�������R��ǰsize��Ԫ������
template <class Type>
void heapSort(Type R[], int size)				
{	int  i; 
 	//Type tmp;
 	// ������ʼ�ѣ�����siftDown( R, i, size )����Ϊ�����
 	for(  i = size / 2 - 1; i >= 0; i-- )		// �����һ����Ҷ��㿪ʼ����
		siftDown( R, i, size );					

 	for ( i = size - 1; i > 0;i--) {	 		// size-1�γ��ӣ��������ף��Ѷ�Ԫ����ѣ��ӣ�βԪ�ؽ���
		swap(R[0],R[i]);							// ������tmp = R[0]; R[0] = R[i]; R[i] = tmp;					
	 	siftDown( R, 0, i );					// �Զ����µ���

	}	
}
 
