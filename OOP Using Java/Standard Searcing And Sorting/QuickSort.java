public class QuickSort{
    void sort(String arr[], int low, int high){
        if (low < high) {
            int pi = partition(arr, low, high);
            sort(arr, low, pi - 1);
            sort(arr, pi + 1, high);
        }
    }

    int partition(String arr[], int low, int high){
        String pivot = arr[low];
        int i = high + 1;

        for (int j = high; j > low; j--) {
            if (arr[j].compareToIgnoreCase(pivot) >= 0){
                i--;
                swap(arr, i, j);
            }
        }
        swap(arr, i - 1, low);
        return i - 1;
    }

    void swap(String arr[], int i, int j){
        String temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void printArray(String arr[]){
        for (String str : arr)
            System.out.print(str + " ");
        System.out.println();
    }

    public static void main(String args[]){
        String arr[] = {"John", "Alice", "Bob", "David", "Eva"};
        int n = arr.length;

        System.out.println("Before sorting:");
        for(int i=0;i<n;i++)
            System.out.print(arr[i]+" ");
        System.out.println();

        QuickSort ob = new QuickSort();
        ob.sort(arr, 0, n - 1);

        System.out.println("Sorted array:");
        printArray(arr);
    }
}