import java.util.Random;
import java.util.Scanner;

class IO{
    IO(){}
    void print(String str){
        System.out.print(str);
    }
    void println(String str){
        System.out.println(str);
    }
}

class App{
    public static void main(String[] args){
        IO io = new IO();
        task1(io);
        task2(io);
        task3(io);
    }

    static void task1(IO io){
        io.println("Task1 : ");
        int a = 3;
        int b = 6;
        int c = 1;

        double d = b * b - 4 * a * c;
        if(d > 0.0){
            io.println("x1 = " + ((-b - Math.sqrt(d)) / (2*a)));
            io.println("x2 = " + ((-b + Math.sqrt(d)) / (2*a)));
        }else if(d == 0){
            double x = -b / (2*a);
            io.println("x1 = " + x);
            io.println("x2 = " + x);
        }else{
            io.print("x1 = \nx2 = ");
        }
    }

    static void task2(IO io) {
        io.println("Task2 : ");
        int[] arr = new int[10];
        for(int a = 0;a < 10;a++){
            arr[a] = new Random().nextInt(100);
        }

        io.print("Arr :\n");
        printArr(arr,io);

        bubbleSort(arr);
        io.print("bubble :\n");
        printArr(arr,io);

        for(int a = 0;a < 10;a++){
            arr[a] = new Random().nextInt(150);
        }

        io.print("Arr :\n");
        printArr(arr,io);

        shellSort(arr);
        io.print("bubble :\n");
        printArr(arr,io);

    }


    static void task3(IO io) {
        io.println("Task3 : ");
        int[] arr = new int[20];
        for(int a = 0;a < 20;a++){
            arr[a] = new Random().nextInt(100);
        }

        io.print("Arr :\n");
        printArr(arr,io);

        bubbleSort(arr);
        io.print("sorted :\n");
        printArr(arr,io);

        int x = new Scanner(System.in).nextInt();
        int p = find(arr,0,arr.length,x);
        io.println("pos -> " + p);

    }


    static void printArr(int[] arr,IO io){
        for(int a : arr){
            io.print(" " + a);
        }
        io.print("\n");
    }

    static void bubbleSort(int[] arr)
    {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
    }

    static void shellSort(int[] arr) {
        int n = arr.length;
        for (int gap = n/2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i += 1) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];

                arr[j] = temp;
            }
        }
    }

    static int find(int[] arr,int l,int r,int x){
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return find(arr, l, mid - 1, x);

            return find(arr, mid + 1, r, x);
        }
        return -1;
    }
}
