void min_max (const int arr[], int count, int *min, int *max) {
    *min = *max = arr[0]; // fix me!
	for (int i = 1; i < count; i++) {
		if (arr[i] < *min) {*min = arr[i];}
		if (arr[i] > *max) {*max = arr[i];}
	}
}
