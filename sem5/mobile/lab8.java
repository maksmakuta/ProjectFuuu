// Beautiful names for interfaces, methods and variables, or no?

interface Nadinter1 {
    int pidsymok(int a, int b);
}

interface Nadinter2 {
    int pidsymokAbs(int a, int b);
}

interface Yspadkovanuj extends Nadinter1, Nadinter2 {
    void vuvid();
}

interface Inter {
    int QUSLO1 = 45;
    int QUSLO2 = -38;
    void vuvid();
}

class Dodatu implements Yspadkovanuj, Inter {
    public int a = 10;

    public int pidsymok(int a, int b) {
        return a + b;
    }

    public int pidsymokAbs(int a, int b) {
        if(a < 0) a = -a;
        if(b < 0) b = -b;
        return a + b;
    }
    public void vuvid() {
        System.out.println("Dodatu.vuvid()");
    }

}

class Vidnjatu implements Yspadkovanuj, Inter {
    public int pidsymok(int a, int b) {
        return a - b;
    }

    public int pidsymokAbs(int a, int b) {
        if(a < 0) a = -a;
        if(b < 0) a = -b;
        return a - b;
    }

    public void vuvid() {
        System.out.println("Vidnjatu.vuvid()");
    }
}

class Interfejsu {
    public static void main(String args[]) {
        Yspadkovanuj ysp;
        Inter inter;

        ysp = new Dodatu();
        System.out.println("Dodatu.pidsymok() : " + ysp.pidsymok(Inter.QUSLO1, Inter.QUSLO2));
        System.out.println("Dodatu.pidsymokAbs() : " + ysp.pidsymokAbs(Inter.QUSLO1, Inter.QUSLO2));

        inter = new Dodatu();

        inter.vuvid();
        ysp.vuvid();

        ysp = new Vidnjatu();
        System.out.println("Vidnjatu.pidsymok() : " + ysp.pidsymok(Inter.QUSLO1, Inter.QUSLO2));
        System.out.println("Vidnjatu.pidsymokAbs()  : " + ysp.pidsymokAbs(Inter.QUSLO1, Inter.QUSLO2));
    }
}
