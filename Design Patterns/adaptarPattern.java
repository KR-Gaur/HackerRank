import java.util.*;

interface Duck{
    void makeSound();
    void fly();
}

class DuckImpl implements Duck{
    public void makeSound(){
        System.out.println("Quack....Quack.....");
    }
    public void fly(){
        System.out.println("Fly....Fly....Fly");
    }
}

class Drone {
    void Sound(){
        System.out.println("Rotating Rotors sound");
    }
    void fly(){
        System.out.println("Rotate Rotors......Fly");
    }
}

// to adapt to Duck
class Adaptar implements Duck{

    Drone drone;

    Adaptar(Drone d){
        drone = d;
    }

    public void makeSound(){
        drone.Sound();
    }

    public void fly(){
        drone.fly();
    }

}

public class adaptarPattern {
    public static void main(String[] args) {
    
        System.out.println("\nDuck being Duck below\n");

        Duck donaldDuck = new DuckImpl();
        donaldDuck.makeSound();
        donaldDuck.fly();

        // new requirement : Drone can also do same actions as Duck. Can we use/adapt Duck actions(functions) for Robot as well ? 

        System.out.println("\nDrone being Duck below\n");

        Drone fourWingDrone = new Drone();

        Duck droneAsDuck = new Adaptar(fourWingDrone);
        droneAsDuck.makeSound();
        droneAsDuck.fly();

        /**
         *  Duck being Duck below

            Quack....Quack.....
            Fly....Fly....Fly

            Drone being Duck below

            Rotating Rotors sound
            Rotate Rotors......Fly
         */

    
    }    
}
