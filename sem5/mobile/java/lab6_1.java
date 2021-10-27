class Parent{
    public void print(){
        System.out.println("Parent call");
    }
    public static void staticPrint(){
        System.out.println("Parent static call");
    }
}

class Demo extends Parent{
    public void demoPrint(){
        System.out.println("Demo print void demoPrint");
    }
    public void print(){
        System.out.println("Child call");
    }
    public static void staticPrint(){
        System.out.println("Child static call");
    }
}

class Main{

    public static void main(String[] args) {
        example1();
        example2();
    }

    static void example1(){
        Parent parentChild = new Demo();
        parentChild.print();
        Parent.staticPrint();
    }

    static void example2(){
        Parent parentChild = new Demo();
        parentChild.print();
        Parent.staticPrint();
        Demo.staticPrint();
    }

}