
class Box{
    /**
     * size of box
     */
    private final float x,y,z;

    /**
     * Box() -> empty constructor
     *  makes 0 size box
     */
    Box(){
        this(0,0,0);
    }

    /**
     * Box(_x,_y,_z) -> init constructor
     * @param _x -> x size of box
     * @param _y -> y size of box
     * @param _z -> z size of box
     */
    Box(float _x,float _y,float _z){
        this.x = _x;
        this.y = _y;
        this.z = _z;
    }

    /**
     * Box(Box) -> copy constructor
     * @param _obj -> object which copied
     */
    Box(Box _obj){
        this(_obj.x, _obj.y, _obj.z);
    }

    /**
     * info() -> print message about object
     */
    void info(){
        System.out.println("Box( " + this.x + "," + this.y + "," + this.z + " )");
    }
}

class App{
    public static void main(String[] args){
        Box a = new Box();
        Box b = new Box(5,9,2);
        Box c = new Box(new Box(-1,9,0)); // looks very good...

        a.info();
        b.info();
        c.info();

    }
}
