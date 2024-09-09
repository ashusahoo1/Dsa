#include<stdio.h>

int insert(int list[],int size,int itm,int pos){
    for(int i=size-1;i>=pos-1;i--)
    {
        list[i+1]=list[i];
    }
    list[pos-1]=itm;
    size++;
    return size;
}
void traverse(int list[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}

int main(){
    int list[]={1,2,3,4};
    int size=4;
    int item=9;
    int pos=1;

    size=insert(list,size,item,pos);
    traverse(list,size);

    return 0;
}
