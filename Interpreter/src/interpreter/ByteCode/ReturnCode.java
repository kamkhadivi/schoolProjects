/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;

import java.util.ArrayList;
import interpreter.VirtualMachine;
/**
 *
 * @author KamranKhadivi
 */
public class ReturnCode extends ByteCode {
        
    protected String function;//function name
    protected int val;
    
    @Override
    public void init(ArrayList<String> args) {
        if(args.size()>0){
            function = args.get(0);
        }else{
            function = "";
        }
    }
    
    @Override
    public void execute(VirtualMachine vm) {
        //return the return address
        vm.setPC((int) vm.getReturnAddress().pop());
        vm.getRunStack().popFrame();
        val = vm.getRunStack().peek();
        
        ////check if the dump is on
        if("ON".equals(vm.dump)) {
            int n = function.indexOf("<");
            String temp;
            if(n<0){
                temp = function;
            }else{
                temp = function.substring(0,n);
            }
            System.out.println("RETURN " + function + "    exit " + temp + ": " + val);
        }
        
    }
}
