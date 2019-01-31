package interpreter;

import java.util.Stack;
import interpreter.ByteCode.*;

public class VirtualMachine {

    private RunTimeStack getRunStack;
    private int pc;
    private Stack returnAddrs;
    private boolean isRunning;
    private Program program;
    public String dump = "OFF";

    protected VirtualMachine(Program program) {
        this.program = program;
    }
    
    public void executeProgram(){
        pc = 0;
        getRunStack = new RunTimeStack();
        returnAddrs = new Stack<Integer>();
        isRunning = true;
        
        while(isRunning){
            ByteCode bCode = program.getCode(pc);
            bCode.execute(this);
            if(!(bCode instanceof DumpCode) && "ON".equals(dump)){
                getRunStack.dump();
            } 
                
            pc++;
        }
    }
   
    public RunTimeStack getRunStack(){
        return getRunStack;
    }
    public void setRunStack(RunTimeStack stack){
        this.getRunStack = stack;
    }
    
    public int getPC(){
        return pc;
    }
    public void setPC(int pcc){
        this.pc = pcc;
    }

    public Stack getReturnAddress(){
        return returnAddrs;
    }
    public void setReturnAddress(Stack returnAddress){
        this.returnAddrs = returnAddress;
    }
    
    public boolean getIsRunning(){
        return isRunning;
    }
    public void setIsRunning(boolean bool){
        this.isRunning = bool;
    }
}
