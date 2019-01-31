/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;

import interpreter.VirtualMachine;
import java.util.ArrayList;
import java.util.Stack;
/**
 *
 * @author KamranKhadivi
 */
public class CallCode extends ByteCode {
    
    protected String function;
    protected int target;
    protected int value;
    
    @Override
    public void init(ArrayList<String> args) {
        function = args.get(0); 
    }
    
    @Override
    public void execute(VirtualMachine vm) {
        //push the return address to the stack, go to the function
        vm.setReturnAddress(push(vm.getPC()));
        vm.setPC(target);
        value = vm.getRunStack().peek();
        
        //check if the dump is on
        if("ON".equals(vm.dump)) {
            int n = function.indexOf("<");
            String temp;
            if(n<0){
                temp = function;
            }else{
                temp = function.substring(0,n);
            }
            System.out.println("CALL " + function + "    " + temp + "(" + value + ")");
        }
    }
    
    public int getTargetAddress(){
        return target;
    }
    
    public void setTargetAddress(int n){
        target = n;
    }
    
    public String getLabel(){
        return function;
    }

    private Stack push(int pc) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
