import java.util.*; 

class Bit{
    
    int size;
    private ArrayList<Integer> a;
    private ArrayList<Integer> q;
    boolean isUsingQ;

    Bit(Integer sizeOfBITArray){
        this.size = sizeOfBITArray + 1;
        a = new ArrayList<Integer>(Collections.nCopies(size, 0));
        q = new ArrayList<Integer>(Collections.nCopies(size, 0));
        isUsingQ = false;
    }

    Bit(ArrayList<Integer> qu, Integer sizeOfBITArray){
    
        // this.q = q;
        qu.add(0,0);
        this.q = qu;
        isUsingQ = true;

        this.size = sizeOfBITArray + 1;
        a = new ArrayList<Integer>(Collections.nCopies(size, 0));

        for( Integer ind=1; ind < q.size(); ind++){
            updateBIT(ind, q.get(ind));
        }

    }
    
    public Integer next( Integer ind ){
        // if(ind > size) return 0;
        return ind + (ind & (-1*ind));
    }
    
    public Integer parent(Integer ind){
        // if(ind > size) return 0;
        return ind - (ind & (-1*ind));
    }
    
    public Integer sum(Integer ind){
        if(ind == 0 ) return a.get(0);
        // System.out.println(ind);
        return a.get(ind) + sum(parent(ind));
    }

    public void updateBIT(Integer ind, Integer diff){

        int n = ind;
        if(n==0) return;
        while(n <= size){ 
                a.set(n, a.get(n) + diff);
                n = next(n);
            }   
    }

    public void update(Integer ind, Integer val){

        Integer diff = val;
        
        if(isUsingQ) { 
            diff = val - q.get(ind);
            q.set(ind,val);
        }
        updateBIT(ind, diff);       
    }

    public void printQ(){
        System.out.println("Q "+q);
    }

    public void printA(){
        System.out.println("BIT "+a);
    }
    

}
    
public class BIT_Tree{
    public static void main(String []args){
        // System.out.println("BIT Demo");
        ArrayList<Integer> q = new ArrayList<Integer>(Arrays.asList(1,2,3,4,5,6));
        Bit bit = new Bit(q,6);
        bit.printQ();
        bit.printA();
        
        System.out.println("Range query : Sum [3, 5] -> 1 base indexing");
        System.out.println(bit.sum(5) - bit.sum(2));
        System.out.println();

        System.out.println("Point update: q[3] -> 0");
        bit.update(3,0);
        bit.printQ();
        bit.printA();
        System.out.println();

        System.out.println("Range query : Sum [3, 5] -> 1 base indexing");
        System.out.println(bit.sum(5) - bit.sum(2));


        // Counting Inversion Using BIT
        // what hasppens when values are -ve ==  take least and offset them
        System.out.println();
        System.out.println("Count Inversions");
        ArrayList<Integer> inv = new ArrayList<Integer>(Arrays.asList(6,5,4,6,2,6));
        
        Integer ansInvCount = 0;
        Bit inversionCounBit = new Bit(inv.size());
        for( Integer eachVal : inv){
            inversionCounBit.update(eachVal, 1);
            ansInvCount += inversionCounBit.sum(inv.size()) - inversionCounBit.sum(eachVal);
        }
        inversionCounBit.printQ();
        inversionCounBit.printA();
        System.out.println(ansInvCount);

        System.out.println();

        ArrayList<Integer> rangeUpdatePointQuery = new ArrayList<Integer>(Arrays.asList(1,2,3,4,5));
        Bit bitForRUPQ = new Bit(rangeUpdatePointQuery.size()+1);
        
        // update values in range [3,5] with 2 -> 1 based indexing
        bitForRUPQ.update(3, 2);
        bitForRUPQ.update(6, -2);

        // point query : get value of rangeUpdatePointQuery[4] (should be incremented by 2)
        Integer ind = 4;
        System.out.println(bitForRUPQ.sum(ind) + rangeUpdatePointQuery.get(ind-1));
        bitForRUPQ.printA();

        // update values in range [2,5] with 5 -> 1 based indexing
        bitForRUPQ.update(2, 5);
        bitForRUPQ.update(6, -5);
        
        // point query : get value of rangeUpdatePointQuery[4] (should be incremented by 2+5)
        ind = 4; 
        System.out.println(bitForRUPQ.sum(ind) + rangeUpdatePointQuery.get(ind-1));
        bitForRUPQ.printA();

     }

}