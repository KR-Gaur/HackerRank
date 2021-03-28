import java.util.*;

class Subject {

    private ArrayList<Observer> observers = new ArrayList<Observer>();
    private int state;

    public void  notifyAllObservers(){
        for( Observer ob : observers){
            ob.update();
        }
    }

    public void attach(Observer observer) {
        this.observers.add(observer);       
    }

    public int getState() {
        return state;
    }

    public void setState(int state) {
        this.state = state;
        notifyAllObservers(); 
    }
 
}

abstract class Observer{
    protected Subject subject;
    public abstract void update();
}

class BinaryObserver extends Observer{
    BinaryObserver(Subject sub){
        subject = sub;
        subject.attach(this);
    }
    
    public void update(){
        System.out.println("Binary String: "+ Integer.toBinaryString(subject.getState()) );
    }
}

class HexObserver extends Observer{
    HexObserver(Subject sub){
        subject = sub;
        subject.attach(this);
    }
    
    public void update(){
        System.out.println("Hex String: "+ Integer.toHexString(subject.getState()));
    }
}

public class observerPattern {
    
    public static void main(String[] agrs) {
        
        Subject subjectTracked = new Subject();
        subjectTracked.setState(5);

        BinaryObserver b = new BinaryObserver(subjectTracked);
        b.update();

        HexObserver h = new HexObserver(subjectTracked);
        h.update();

        System.out.println("\n Tiggering Update... \n");
        subjectTracked.setState(6);

        /**
         * Binary String: 101
           Hex String: 5

           Tiggering Update...

           Binary String: 110
           Hex String: 6
         */

    }
    
}
