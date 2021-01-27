long numWayPaintFence(int n,int k){
    if(n==0)
	return 0;
    if(n==1)
	return k;
    long same=k*1;
    long diff=k*(k-1);
    long total=same+diff;
    for(int i=3;i<=n;i++){
      same=diff*1;
      diff=total*(k-1);
      total=same+diff;
    }	
    return total;
 
} 