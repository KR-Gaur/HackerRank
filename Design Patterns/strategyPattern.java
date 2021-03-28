import java.util.*;

interface Strategy{
    void move();
}

class Car implements Strategy{
    public void move(){
        System.out.println("Going via Car");
    } 
}

class Bus implements Strategy{
    public void move(){
        System.out.println("Going via Bus");
    } 
}

class Cycle implements Strategy{
    public void move(){
        System.out.println("Going via Cycle");
    } 
}

class Travel{
    
    Strategy stgy;

    Travel(Strategy s){
        stgy = s;
    }

    public void setStgy(Strategy stgy) {
        this.stgy = stgy;
    }

    public void mode(){
        System.out.print("Mode : ");
        stgy.move();
    }

}

public class strategyPattern {
    public static void main(String[] args) {
    
        Cycle cycle = new Cycle();
        Bus bus = new Bus();
        Car car = new Car();

        System.out.println("Initially ");
        Travel t = new Travel(cycle);
        t.mode();
        
        System.out.println("\nThen Changed to ");
        t.setStgy(car);
        t.mode();
        
        System.out.println("\nAgain Changed to ");
        t.setStgy(bus);
        t.mode();

        /**
         *  Initially 
            Mode : Going via Cycle

            Then Changed to
            Mode : Going via Car

            Again Changed to
            Mode : Going via Bus
         */
    }    
}
