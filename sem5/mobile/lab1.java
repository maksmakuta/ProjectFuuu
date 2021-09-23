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
        task4(io);
        task5(io);
        task6(io);
        task7(io);
        task8(io);
    }

    static void task1(IO io){
        double expr  = 20.0 * (1.0/3.0) + Math.pow(158,2);
        io.println("Task1 : " + expr );
    }

    static void task2(IO io){
        byte a = 14;
        double expr  = a / 209 +a *(29 - Math.pow(13,2) + a/3);
        io.println("Task2 : " + expr );
    }

    static void task3(IO io){
        int i = 50000;char c = '5'; short s = 2010; byte b = 2;
        double expr = (i * b) + (i / c) - (b * s);
        io.println("Task3 : " + expr );
    }

    static void task4(IO io){
        int[][] mat = new int[5][5];
        io.println("Task 4 : ");
        for(int _a = 0;_a < 5;_a++) {
            for (int _b = 0; _b < 5; _b++){
                if(_a  >= _b) {
                    mat[_a][_b] = 1;
                }else{
                    mat[_a][_b] = 0;
                }
            }
        }

        for(int _a = 0;_a < 5;_a++) {
            for (int _b = 0; _b < 5; _b++){
                io.print(" " + mat[_a][_b]);
            }

            io.print("\n");
        }
        io.println("");
    }

    public static void task5(IO io){
        int q = 21,w = 8;
        io.println("Task5 : " + (q % w));
    }

    public static void task6(IO io){
            int n = 21;
            io.println("Task6 : " + sum(n));
    }

    public static void task7(IO io){
        float n = 456.856f;
        io.println("Task7 : " + Math.round(n));
    }

    public static void task8(IO io){
        int n = 215;
        io.println("Task8 : " + sum(n));
    }


    public static int sum(int n){
        int number = n, digit, sum = 0;
        while(number > 0) {
            digit = number % 10;
            sum = sum + digit;
            number = number / 10;
        }
        return sum;
    }

}
