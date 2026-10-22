#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int bubbleMin(int a[], int n){
    int i, j;
    for(i = 0; i < n - 1 ; i++){
        for(j = n-1; j > i; j--){
            if(a[j-1] > a[j]){
                int aux;
                aux = a[j];
                a[j] = a[j-1];
                a[j-1] = aux;
            }
        }
    }
    return 0;
}

int bubble(int a[], int n){
    int i, j;
    for(i = n-1; i > 0 ; i--){
        for(j = 1; j <= i; j++){
            if(a[j-1] > a[j]){
                int aux = a[j];
                a[j] = a[j-1];
                a[j-1] = aux;
            }
        }
    }
    return 0;
}

int selectionMax(int a[], int n){
    int i, j, max;
    for(i = n-1; i > 0; i--){
        max = i;
        for(j = 0; j < i; j++){
            if(a[j] > a[max]) max = j;
        }
        int aux = a[max];
        a[max] = a[i];
        a[i] = aux;
    }
    return 0;
}

int selection(int a[], int n){
    int i, j, min;
    for(i = 0; i < n; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(a[j] < a[min]) min = j;
        }
        int aux = a[min];
        a[min] = a[i];
        a[i] = aux;
    }
    return 0;
}

int maxHeapify(int a[], int i, int n){

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;

    if(l < n && a[l] > a[i]) largest = l; else largest = i;
    if(r < n && a[r] > a[largest]) largest = r;

    if(largest != i){
        int aux = a[i];
        a[i] = a[largest];
        a[largest] = aux;
        maxHeapify(a, largest, n);
    }
    return 0;
}

int buildMaxHeap(int a[], int n){
    int i;
    for (i=(n/2)-1; i >= 0; i--){
        maxHeapify(a, i, n);
    }
    return 0;
}

int heapSort(int a[], int n){
    buildMaxHeap(a, n);
    int i;
    for(i = n-1; i > 0; i--){
        int max = a[0];
        a[0] = a[i];
        a[i] = max;
        maxHeapify(a, 0, i);
    }
    return 0;
}

int printHeap(int a[], int i, int n, int depth){
    if(i < n){
        int j;
        for(j = 0; j < depth; j++) printf("\t");
        printf("a[%d]: %d\n", i, a[i]);
        printHeap(a, 2*i + 1, n, depth + 1);
        printHeap(a, 2*i + 2, n, depth + 1);
    }
    return 0;
}

int merge(int a[], int l, int m, int u){
    int invertions = 0;
    int ne_e = (m - l) + 1, ne_d = (u - (m + 1)) + 1;
    int suba_e[ne_e], suba_d[ne_d];
    int i, j, k;

    for(i = 0; i < ne_e; i++){
        suba_e[i] = a[l + i];
    }

    for(i = 0; i < ne_d; i++){
        suba_d[i] = a[m + 1 + i];
    }

    i = 0;
    j = 0;
    k = 0;

    while(i < ne_e && j < ne_d){
        if(suba_e[i] < suba_d[j]){
            a[l + k] = suba_e[i];
            i++;
        }
        else{
            a[l + k] = suba_d[j];
            j++;
            invertions = invertions + (ne_e - i);
        }
        k++;
    }

    while(i < ne_e){
        a[l + k] = suba_e[i];
        i++;
        k++;
    }

    while(j < ne_d){
        a[l + k] = suba_d[j];
        j++;
        k++;
    }

    return invertions;
}

int mergeSort(int a[], int l, int u, int r){
    int invertions = 0;
    if(l < u){
        int p = (u-l)%2 == 0 ? (u-l)/2 : (u-l-1)/2;
        int invertions_l;
        int invertions_r;
        int invertions_m;
        //sleep(1);
        invertions_l = mergeSort(a, l, l+p, r+1);
        invertions_r = mergeSort(a, l+p+1, u, r+1); 
        invertions_m = merge(a, l, l+p, u);
        invertions = invertions_l + invertions_r + invertions_m;
    }
    return invertions;
}

int partition(int a[], int p, int r){
    int i = p, j;
    int aux;

    for(j = p; j <= r-1; j++){
        if(a[j] <= a[r]){
            if(j != i){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
            i++;
        }
    }
    aux = a[r];
    a[r] = a[i];
    a[i] = aux;

    return i;
}

int quickSort(int a[], int p, int r){
    if(p < r){
        int q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }
    return 0;
}

int main()
{
 
    int n, i;
    scanf("%d", &n);
 
    int a[n];
 
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    //bubbleMin(a, n);
    //selectionMax(a, n);
    //bubble(a, n);
    //selection(a, n);
    //heapSort(a, n);
    //int teste = mergeSort(a, 0, n-1, 0);

    //printf("inversoes: %d, a = [", teste);

    quickSort(a, 0, n-1);

    printf("a = [");
    for(i=0;i<n;i++){
        printf(" %d ", a[i]);
    }
    printf("]\n");

    return 0;
}