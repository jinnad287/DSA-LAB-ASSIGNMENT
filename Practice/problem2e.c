#include<stdio.h>


void middleData(int *arr, int n){

if(n%2 == 0){
printf("There is Two Middle Data.\n");
printf("The First is at index %d is: %d\n",((n-2)/2),arr[((n-2)/2)]);
printf("The First is at index %d is: %d\n",(n/2),arr[(n/2)]);

}
else{
printf("There is Only Middle Data.\n");
printf("The Midle Data is at index %d is: %d\n",((n-1)/2),arr[((n-1)/2)]);

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

middleData(arr,n);

return 0;


}
