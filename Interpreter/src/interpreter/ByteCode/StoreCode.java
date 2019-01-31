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
public class StoreCode extends ByteCode {
    private int offset;
    private String st;
    private int val;
    
    @Override
    public void init(ArrayList<String> args) {
        offset = Integer.parseInt(args.get(0));
        st = args.get(1);
    }
    
    @Override
    public void execute(VirtualMachine vm) {
        
        val = vm.getRunStack().peek();
        vm.getRunStack().store(offset);
        
        
        if("ON".equals(vm.dump)) {
            System.out.println("STORE " + offset + " " + st + "    " + st + " = " + val);
        }
    }
}
