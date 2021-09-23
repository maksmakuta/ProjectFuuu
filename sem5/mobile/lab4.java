class App{
    public static void main(String[] args){
        if(args.length == 0){
            System.out.println("No arguments");
        }else{
            for(String arg : args){
                System.out.println(arg);
            }
        }
    }
}
