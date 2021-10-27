class RLEncoder{

    private final String data;
    private String result;

    RLEncoder(String str){
        this.data = str + "0";
        this.result = "";
    }

    void work(){
        StringBuilder tmp = new StringBuilder();
        char c = data.charAt(0);
        int s = 0;
        for(int a = 0;a < data.length();a++){

            //new IO().println("" + a + " -> " + data.charAt(a));
            if(c == data.charAt(a) && s != 9){
                s++;
            }else{
                if(s == 1)
                    tmp.append(c);
                else
                    tmp.append(c).append(s);
                //new IO().println("" + c + s);
                c = data.charAt(a);
                s = 1;
            }
        }
        result = tmp.toString();
    }

    String getResult(){
        return result;
    }

}

class App{
    public static void main(String[] args) {
        String test = "Hhhhhhhhhhhhhheeeellooooo";
        RLEncoder e = new RLEncoder(test);
        e.work();
        new IO().print("Result -> " + e.getResult());
    }
}