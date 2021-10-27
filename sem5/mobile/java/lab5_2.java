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

    float ask(String str){
        this.print(str);
        return new Scanner(System.in).nextFloat();
    }
}


class Circle{
    private float x,y,r;

    /**
     * Circle() -> empty constructor
     */
    Circle(){
        this(0,0,0);
        float t;

        t = new IO().ask("Enter X -> ");
        this.setX(t);

        t = new IO().ask("Enter Y -> ");
        this.setY(t);

        t = new IO().ask("Enter R -> ");
        this.setR(t);

    }

    /**
     * Circle(float,float,float) -> base constructor
     * @param _x -> x point of circle
     * @param _y -> r point of circle
     * @param _r -> radius of circle
     */
    Circle(float _x,float _y,float _r){
        this.setPos(_x,_y);
        this.setR(_r);
    }

    /**
     * Circle(Circle) -> copy constructor
     * @param _obj -> object to copy
     */
    Circle(Circle _obj){
        this(_obj.getX(), _obj.getY(), _obj.getR());
    }

    /**
     * setPos(float,float) -> set point of circle
     * @param x -> x coordinate of point
     * @param y -> y coordinate of point
     */
    void setPos(float x,float y){
        this.setX(x);
        this.setY(y);
    }

    /**
     * setX(float) -> set x coordinate of circle
     * @param _x -> x coordinate of point
     */
    void setX(float _x){
        this.x = _x;
    }
    /**
     * setY(float) -> set y coordinate of circle
     * @param _y -> y coordinate of point
     */
    void setY(float _y){
        this.y = _y;
    }
    /**
     * setR(float) -> set radius of circle
     * @param _r -> radius of point
     */
    void setR(float _r){
        this.r = _r;
    }

    /**
     * getArea() -> calculate area of circle
     * @return area of circle [double]
     */
    double getArea(){
        return Math.PI * Math.pow(r,2);
    }

    /**
     * isAreaEqual(Circle) -> compare areas of 2 circles
     * @param c -> other circle to compare
     * @return true if area are equal else false [boolean]
     */
    boolean isAreaEqual(Circle c){
        return this.getArea() == c.getArea();
    }

    /**
     * getLength() -> calculate length of circle
     * @return lenght of circle [double]
     */
    double getLength(){
        return 2.0 * Math.PI * this.getR();
    }

    /**
     * calcDistance(Circle) -> calculate distance between 2 circles points
     * @param c -> another circle
     * @return distance between 2 circles [double]
     */
    double calcDistance(Circle c){
        return Math.sqrt(Math.pow(c.getX() - this.getX(),2) + Math.pow(c.getY() - this.getY(),2));
    }

    /**
     * replace() -> change point of circle to another in range (-99,-99) ... (99,99)
     */
    void replace(){
        Random r = new Random();
        this.setPos(r.nextInt(99) - 100,r.nextInt(99) - 100);
    }

    /**
     * isTouch(Circle) -> check if 2 circles has a touch point
     * @param c -> another circle
     * @return true if circles has 1 touch point else false
     */
    boolean isTouch(Circle c){
        double d = this.calcDistance(c);
        new IO().println("" + d);
        if(d < this.getR())
            return d == Math.sqrt(c.getR()) - Math.sqrt(this.getR());
        else
            return d == Math.sqrt(c.getR()) + Math.sqrt(this.getR());
    }

    /**
     * getX() -> getter for x point coordinate of circle
     * @return x coordinate of circle
     */
    float getX(){return this.x;}
    /**
     * getY() -> getter for y point coordinate of circle
     * @return y coordinate of circle
     */
    float getY(){return this.y;}
    /**
     * getR() -> getter for radius of circle
     * @return radius of circle
     */
    float getR(){return this.r;}


}

class App{
    public static void main(String[] args){
        IO i = new IO();
        Circle c1 = new Circle(2,1,5);
        Circle c2 = new Circle(4,5,45);
        if(c1.isTouch(c2)){
            i.print("Touch");
        }else{
            i.print("Nope");
        }
    }
}
