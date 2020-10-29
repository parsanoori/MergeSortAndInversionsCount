#include <iostream>

using namespace std;


int merge(int* arr,int left,int middle,int right)
{

	int inversionsCount = 0;
	
	int leftArrLength = middle-left+1, rightArrLength = right - middle;
	int* leftArr = new int[leftArrLength];
	int* rightArr = new int[rightArrLength];

	for (int i=0; i<leftArrLength; i++)
		leftArr[i] = arr[left + i];

	for (int i=0; i<rightArrLength; i++)
		rightArr[i] = arr[middle + 1 + i];

	int i=0,j=0,k=left;
	
	while(i < leftArrLength && j < rightArrLength)
	{
		if(leftArr[i] <= rightArr[j])
			arr[k++] = leftArr[i++];
		else {
			arr[k++] = rightArr[j++];
			inversionsCount += leftArrLength - i;
		}
	}

	for (; i < leftArrLength; i++)
		arr[k++] = leftArr[i];

	for (; j < rightArrLength; j++)
		arr[k++] = rightArr[j];

	return inversionsCount;
	
}

int numberOfInversions(int* arr,int left,int right)
{
	if (left >= right)
		return 0;

	int middle = (left + right)/2;

	int inversionsLeft = numberOfInversions(arr,left,middle);
	int inversionsRight = numberOfInversions(arr,middle+1,right);
	
	int inversionsOfMerging = merge(arr,left,middle,right);

	return inversionsLeft + inversionsRight + inversionsOfMerging;

}

void print(int *arr,int n)
{
	for(int i = 0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{

	int arr[] = {1,-5,8,-5,7,6,14,15,10,3,4,85,99,97,-103};
	int n = sizeof(arr)/sizeof(int);
	cout << "Previous array used to be: " << endl;
	print(arr,n);
	
	int inversions = numberOfInversions(arr,0,n-1);
	cout << endl << "Sorted array is: " << endl;
	print(arr,n);
	cout << endl << "Number of inversions are: " << endl << inversions << endl;
	
	return 0;
}

