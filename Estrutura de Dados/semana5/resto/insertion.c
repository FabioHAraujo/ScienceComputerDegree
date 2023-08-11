insertion_sort(A,n){
    int chave;
    for(j=1;j<n;j++){
        chave = A[j];
        i = j-1;
        while(i>=0 && A[i]>chave){
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = chave;
    }
}