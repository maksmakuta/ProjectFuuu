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
        task4(io);
    }

    static void task1(IO io){
        io.println("Task1 : ");
        for(float a = 0.0f;a <= 2.0f;a+= 0.4f){
            double z = ((a*a+2*a) / (3*Math.cos(Math.sqrt(a))+1));
            io.println( "" + a +  " -> " + z);

        }
    }

    static void task2(IO io){
        io.println("Task2 : ");
        double s = 0.0;
        for(int a = 1;a < 10;a++){
            double z = a / 10.0;
            s += a + z;
        }
        io.println(" -> " + s);
    }

    static void task3(IO io){
        io.println("Task3 : ");
        io.print("n -> ");
        int s = new Scanner(System.in).nextInt();
        io.println(" -> " + fact(s));
    }

    static void task4(IO io){
        io.println("Task4 : ");
        //int s = new Scanner(System.in).nextInt();
        for(int n = 1;n <= 10;n++)
        io.println( n + " -> " + 2.0/fact(n));
    }


    static long fact(int n){
        long f = 1L;
        if(n == 0 | n == 1)
            return 1;
        while(n > 0){
            f = f * n;
            n--;
        }
        return f;
    }
}
