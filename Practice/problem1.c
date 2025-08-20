#include<stdio.h>

int main(){
int n;
printf("Enter the Size of the Array: ");
scanf("%d",&n);


int arr[n];
arr[n-1]= 0;

//taking input
printf("Enter the Elements: ");
printf("\n");

for(int i=0 ; i<(n-1) ; i++){
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

return 0;


}
