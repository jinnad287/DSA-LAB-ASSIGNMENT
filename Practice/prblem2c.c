#include<stdio.h>

void deleteData(int *arr, int n){
int x, c=0;

printf("Enter The Data you want to Delete: ");
scanf("%d",&x);
for(int i=0 ; i<n ; i++){
if(arr[i]=x){
c++;
}
}

int newarr[n-c];
int m=0;

printf("New Array After Deleting %d is: ",x);
for(int i=0 ; i<(n-c) ; i++){

if(arr[i]=x){
continue;
}

else{
newarr[m]=arr[i];
m++;
}

}

}

int main(){
int n;
printf("Enter the Size of the Array: ");
scanf("%d",&n);


int arr[n];

//taking input
printf("Enter the Elements: ");
printf("\n");

for(int i=0 ; i<n ; i++){
printf("Element %d: ",i+1);
scanf("%d",&arr[i]);

}

//print
printf("\n");
printf("The Array is: ");
for(int i=0 ; i<n ; i++){
printf("%d ",arr[i]);

}
printf("\n");

deleteData(arr,n);

return 0;


}
