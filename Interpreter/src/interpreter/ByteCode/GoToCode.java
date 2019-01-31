/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;

import interpreter.VirtualMachine;
import java.util.ArrayList;
/**
 *
 * @author KamranKhadivi
 */
public class GoToCode extends ByteCode{
    private String label;//label
    private int target;//target address
    
    @Override
    public void init(ArrayList<String> args) {
         label = args.get(0);
    }
    
    @Override
    public void execute(VirtualMachine vm) {
        //branch to the address
        vm.setPC(target);
        
        //check if the dump is on
        if("ON".equals(vm.dump)) {
            System.out.println("GOTO" + " " + label);
        }
    }
    
    public int getTargetAddress(){
        return target;
    }
    
    public void setTargetAddress(int n){
        target = n;
    }
    
    public String getLabel(){
        return label;
    }
}
