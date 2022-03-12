#include <stdio.h>

void Bucket_Sort(int array[], int n)
{
	int	i;
	int	j;  
	int count[n]; 

	for (i = 0; i < n; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		(count[array[i]]) = (count[array[i]]) + 1; // accessing the memory which is undifined
	for (i = 0, j = 0; i < n; i++)  
		for(; count[i] > 0; (count[i])--) // why even if count[i] = 0, this process continue?
			array[j++] = i; // ???
}   

int main(void)
{
	int array[100];
 int	i;
 int	num; 

	printf("Enter the size of array : ");
	scanf("%d", &num);   
	printf("Enter the %d elements to be sorted:\n",num); 
	for (i = 0; i < num; i++)
		scanf("%d", &array[i]); 
	printf("\nThe array of elements before sorting : \n");
	for (i = 0; i < num; i++)
		printf("%d ", array[i]);  
	printf("\nThe array of elements after sorting : \n"); 
	Bucket_Sort(array, num); 
	for (i = 0; i < num; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
