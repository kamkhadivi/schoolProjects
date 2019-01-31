package interpreter;

import java.util.Iterator;
import java.util.ArrayList;
import java.util.Stack;

public class RunTimeStack {

    private ArrayList runTimeStack;
    private Stack<Integer> framePointer;

    public RunTimeStack() 
    {
        runTimeStack = new ArrayList<>();
        framePointer = new Stack<>();
        //Add initial Frame Pointer, main is the entry
        // point of our language, so its frame pointer is 0.
        framePointer.add(0);
    }

    public void dump(){
        
        Iterator itr = framePointer.iterator();
        int frame = (Integer) itr.next();
        int nextframe = frame;
        
        for(int a = 0; a < framePointer.size(); a++ ){
            if(itr.hasNext()){
                nextframe = (Integer) itr.next();
            }
            else{
                nextframe = runTimeStack.size();
            }
            
        System.out.print("[");  
            for(int b = frame; b < nextframe; b++){
                System.out.print(runTimeStack.get(b));
                if( b != nextframe -1)
                    System.out.print(",");
        }
        System.out.print("]");  
        frame = nextframe;
   
        }
        System.out.println("");
    }
        
    public int push( int a){
        runTimeStack.add(a);
        return a;
    }
    public int peek(){
        return (int) runTimeStack.get(runTimeStack.size() -1);
    }

    public int pop(){
        int temp = (int) runTimeStack.get(runTimeStack.size() -1);
        runTimeStack.remove(runTimeStack.size() -1);
        return temp;
    }
    
    public void newFramePositioned(int i){
        framePointer.push(this.runTimeStack.size() - i);
    }
    
    public void popFrame(){
        int temp1 = this.peek();
        int temp2 = framePointer.pop();
        
        for (int i = runTimeStack.size() - 1; i >= temp2; i--) {
            this.pop();
        }
        this.push(temp1);
    }
    
    public int store(int i){
        int temp = this.pop();
        runTimeStack.set(framePointer.peek() +i, temp);
        
        return temp;        
    }

    public int load(int i){
        int temp = (int) runTimeStack.get(framePointer.peek() + i);
        runTimeStack.add(temp);
        return temp;
    }

    public Integer push(Integer i){
        runTimeStack.add(i);
        return i;
    }

    public int getOffset(){
        return runTimeStack.size() - framePointer.peek() - 1;
    }

    public int getValOffSet(int i){
        return (int) runTimeStack.get(framePointer.peek() +i);
    }

    public boolean empty(){
        return runTimeStack.isEmpty();
    }
}
