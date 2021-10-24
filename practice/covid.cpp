#include "graphics.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> numbers;
int width = 1200;
int gap = 5;
int height = 600;
int n = 200;
int dly;

void swap(int i, int j, int x, int y){
    setcolor(GREEN);
    line(i+100, height, i+100, height - x);
    delay(dly);
    setcolor(BLACK);
    line(i+100, height, i+100, height- x);
    setcolor(WHITE);
    line(i+100, height, i+100, height - y);
    setcolor(RED);
    line(j+100, height, j+100, height- y);
    delay(dly);
    setcolor(BLACK);
    line(j+100, height, j+100, height - y);
    setcolor(WHITE);
    line(j+100, height, j+100, height - x);
}

void selectionSort(){
	int temp, i ,j;
	for(i=0; i<n; i++){
		int mn=i;
		for(j=i;j<n; j++){
			if(numbers[j]<numbers[mn]){
				mn=j;
			}
		}
		temp=numbers[mn];
		numbers[mn]=numbers[i];
		numbers[i]=temp;
		swap(gap*i+1, gap*mn+1, numbers[mn], numbers[i]);
	}
}

void bubbleSort(){
	int temp, i, j;

	for (i = 1; i < n; i++) {
		for (j = 0; j < n- i; j++) {
			if (numbers[j] > numbers[j + 1]) {
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
				swap(gap * j + 1, gap * (j + 1) + 1, numbers[j + 1], numbers[j]);
			}
		}
	}
}

void insertionSort(){
	int temp, i, j;
	for(i=0;i<n;i++){
		temp=numbers[i];
		j=i-1;
		while(j>=0 && numbers[j]>temp){
			numbers[j+1]=numbers[j];
			numbers[j]=temp;
			swap(gap*j+1,gap*(j+1)+1,numbers[j+1],numbers[j]);
			j--;
		}
	}
}

void merge(vector<int> &arr, int l, int r){
	int mid=l+(r-l)/2, i=l, j=mid+1;
	vector<int> left, right;
	while(i<=mid){
		left.push_back(arr[i]);
		i++;
	}
	while(j<=r){
		right.push_back(arr[j]);
		j++;
	}
	i=0; j=0;
	while(i<=(mid-l) && j<(r-mid)){
		if(left[i]<right[j]){
	    	setcolor(BLACK);
    		line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]);   		
			arr[l+i+j]=left[i];
	    	setcolor(GREEN);
    		line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]); 
    		delay(dly);
    		setcolor(WHITE);
    		line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]); 
			i++;
		}
		else{
	    	setcolor(BLACK);
    		line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]);   		
			arr[l+i+j]=right[j];
	    	setcolor(GREEN);
    		line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]); 
    		delay(dly);
    		setcolor(WHITE);
    		line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]);
			j++;
		}
	}
	while(i<=(mid-l)){
	    setcolor(BLACK);
    	line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]);   		
		arr[l+i+j]=left[i];
	    setcolor(GREEN);
    	line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]); 
    	delay(dly);
    	setcolor(WHITE);
    	line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]);
		i++;
	}
	while(j<(r-mid)){
	    setcolor(BLACK);
    	line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]);   		
		arr[l+i+j]=right[j];
	    setcolor(GREEN);
    	line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]); 
    	delay(dly);
    	setcolor(WHITE);
    	line(1+gap*(l+i+j)+100, height, 1+gap*(l+i+j)+100, height - arr[l+i+j]);
		j++;
	}
	
}

void mergeSort(vector<int> &arr, int l, int r){
	if(l>=r)return;
	int mid = l+(r-l)/2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid+1, r);
	merge(arr, l, r);
}

int partition (vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1), j, temp;
    for (j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++; 
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            swap(gap*i+1,gap*j+1,arr[j],arr[i]);
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    swap(gap*(i+1)+1,gap*high+1,arr[high],arr[i+1]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
	srand(time(NULL));
	cout<<"Type your choice for sorting algorithm here, and press Enter key.\n~ 1 for Selection Sort.\n~ 2 for Bubble Sort.\n~ 3 for Insertion Sort.\n~ 4 for Merge Sort.\n~ 5 for Quick Sort.\n";
	int choice; cin>>choice;
	if(choice<1 || choice>5){
		cout<<"Enter a valid choice!\n";
		cin>>choice;
	}
	cout<<"Type the delay time and press Enter key.\nIf you enter delay time = \'t\', then each comparison will be delayed by \'t\' miliseconds for better visualization.\n";
	cin>>dly;
	while(dly<0){
		cout<<"Please enter non-negative number.\n";
		cin>>dly;
	}
	cout<<"\n";
	int gd = DETECT, gm;
	int wid1;
	initgraph(&gd, &gm, NULL);
//	wid1 = initwindow(gap * width + 1, width+1);
	wid1 = initwindow(width,height);
	setcurrentwindow(wid1);
	for (int i = 1; i <= n; i++)
		numbers.push_back(rand()%height+1);
	for (int i = 1; i <= gap * n; i += gap) {
		line(i+100, height, i+100, (height - numbers[i / gap]));
	}
	
	delay(200);
	if(choice==1){
		selectionSort();
	}
	else if(choice==2){
		bubbleSort();
	}
	else if(choice==3){
		insertionSort();
	}
	else if(choice==4){
		mergeSort(numbers, 0, n-1);
	}
	else{
		quickSort(numbers, 0, n-1);
	}
	setcolor(GREEN);
	for (int i = 1; i <= gap * n; i += gap) {
		line(i+100, height, i+100, (height - numbers[i / gap]));
	}

	for (int i = 0; i < n; i++){
		cout << numbers[i] << " ";
	}
	
	cout <<"\n\n";
	
	delay(5000);
	
	closegraph();
	cout<<"The program will end in ";
	for(int i=0;i<10;i++){
		cout<<10-i<<" ";
		delay(1000);
	}
	return 0;
}
