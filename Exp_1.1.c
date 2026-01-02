#include<stdio.h>
void main() {
	
	int key, flag=0, pos, i,n;

	printf("Enter number of elements");
	scanf("%d",&n);
	int a[n];

	printf("Enter the elements");
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	printf("Enter Element to be searched");
	scanf("%d",&key);

	for(i=0;i<n;i++){
		if(a[i]==key){
			flag = 1;
			pos = i;
		}
    }
	if (flag == 1) {
		printf("found at position %d\n", pos);
	} else {
		printf("%d not found\n", key);
	}

}
