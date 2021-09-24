import java.nio.charset.StandardCharsets;
import java.util.Scanner;

class IO{
    IO(){}
    void print(String str){
        System.out.print(str);
    }
    void println(String str){
        System.out.println(str);
    }
    void printUTF8(String str) {
        String utf8str = new String(str.getBytes(), StandardCharsets.UTF_8);
        this.print(utf8str);
    }
    void printlnUTF8(String str) {
        String utf8str = new String(str.getBytes(), StandardCharsets.UTF_8);
        this.println(utf8str);
    }

    float ask(String str){
        this.print(str);
        return new Scanner(System.in).nextFloat();
    }
}

abstract class Human{
    private String name = "";

    abstract void sayHello();

    Human(String n) {
        String utf8str = new String(n.getBytes(), StandardCharsets.UTF_8);
        this.setName(utf8str);
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

class German extends Human{

    German(String n) {
        super(n);
    }

    @Override
    void sayHello() {
        new IO().printlnUTF8("Hallo, " + this.getName());
    }
}

class Englishman extends Human{

    Englishman(String n) {
        super(n);
    }

    @Override
    void sayHello() {
        new IO().printlnUTF8("Hello, " + this.getName());
    }
}

class Spaniard extends Human{

    Spaniard(String n) {
        super(n);
    }

    @Override
    void sayHello() {
        new IO().printlnUTF8("Hola, " + this.getName());
    }
}

class App{
    static Human h;
    public static void main(String[] args) {
        h = new German("Muller");
        h.sayHello();
        h = new Englishman("Steve");
        h.sayHello();
        h = new Spaniard("Isabella");
        h.sayHello();
    }
}
