#include <iostream> 
 
const int MAX_SIZE = 10000; 
 
 
void swapN(int i, int j, int mas[MAX_SIZE]) { 
    int temp = mas[i]; 
    mas[i] = mas[j]; 
    mas[j] = temp; 
} 
 
 
//сортировка обменом 
void swapSort(int n, int mas[MAX_SIZE]) { 
    for (int i = 0; i < n - 1; ++i) { 
        for (int j = i + 1; j < n; ++j) { 
            if (mas[i] > mas[j]) { 
                swapN(i, j, mas); 
            } 
        } 
    } 
} 
 
 
//сортировка пузырьком 
void bubbleSort(int n, int mas[MAX_SIZE]) { 
    for (int i = 0; i < n; ++i) { 
        bool flag = true; 
        for (int j = 0; j < n - i + 1; ++j) { 
            if (mas[j] > mas[j + 1]) { 
                swapN(j, j + 1, mas); 
                bool flag = false; 
            } 
        } 
        if (flag) { 
            break; 
        } 
    } 
} 
 
 
//сортировка Шелла 
void shellSort(int n, int mas[MAX_SIZE]) { 
    for (int step = n / 2; step > 0; step /= 2) { 
        for (int i = step; i < n; ++i) { 
            for (int j = i - step; j >= 0 && mas[j] > mas[j + step]; j -= step) { 
                swapN(j, j + 1, mas); 
            } 
 
        } 
    } 
} 
 
 
//быстрая сортировка 
void quickSort(int start, int end, int mas[]) {
    if (start > end) {
        return;
    }
    int mid = mas[(start + end) / 2];
    int i = start;
    int j = end;

    while (i <= j) {
        while (mas[i] < mid) {
        i++;
        }
        while (mas[j] > mid) {
        j--;
        }
        if (i <= j) {
            swapN(i, j, mas);
            i++;
            j--;
        } 
    }
    quickSort(start, j, mas);
    quickSort(i, end, mas);
} 
 
 
//сортировка слиянием!!!!
void merge(int start, int end, int mid, int mas[MAX_SIZE]) {
    int mergedmas[MAX_SIZE];
    int i, j, k;
	i = start;
	k = start;
	j = mid + 1;
	
	while (i <= mid && j <= end) {
		if (mas[i] < mas[j]) {
			mergedmas[k] = mas[i];
			k++;
			i++;
		}
		else {
			mergedmas[k] = mas[j];
			k++;
			j++;
		}
	}
	
	while (i <= mid) {
		mergedmas[k] = mas[i];
		k++;
		i++;
	}
	
	while (j <= end) {
		mergedmas[k] = mas[j];
		k++;
		j++;
	}
	
	for (i = start; i < k; i++) {
		mas[i] = mergedmas[i];
	}

}


void mergeSort(int start, int end, int mas[MAX_SIZE]) {
    int mid{};
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(start, mid, mas);
		mergeSort(mid+1, end, mas);
		merge(start, end, mid, mas);
	}
}

 
 
//сортировка посчётом 
void countingSort(int n, int mas[MAX_SIZE]) { 
    int tmp_mas[MAX_SIZE]{}; 
    for (int i = 0; i < n; ++i) { 
        tmp_mas[mas[i]]++; 
    } 
 
    int k = 0; 
    for (int i = 0; i < n; ++i) { 
        while (tmp_mas[i] > 0) { 
            mas[k] = i; 
            k++; 
            tmp_mas[i]--; 
        } 
    } 
 
} 
 
 
//сортировка кучей !!!

void heapify(int n, int i, int mas[MAX_SIZE]) {
    int largest = i;   

    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && mas[l] > mas[largest]) {
        largest = l;
    }

    if (r < n && mas[r] > mas[largest]) {
        largest = r;
    }

    if (largest != i) {
        swapN(i, largest, mas);
        heapify(n, largest, mas);
    }
}

void heapSort(int n, int mas[MAX_SIZE]) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(n, i, mas);
    }

    for (int i = n - 1; i >= 0; --i)  {
        swapN(0, i, mas);
        heapify(i, 0, mas);
    }
}
 
 
 
 
int main() { 
    int mas[5]{ 93, -86, 457, 5, -9 }; 
 
    heapSort(5, mas); 
 
    for (int i = 0; i < 5; ++i) { 
        std::cout << mas[i] << " "; 
    } 
 
    return 0; 
}
