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
public class LoadCode extends ByteCode {
    private int n;//value
    private String id;//id
    
    @Override
    public void init(ArrayList<String> args) {
        n = Integer.parseInt(args.get(0));
        id = args.get(1);
    }
    
    @Override
    public void execute(VirtualMachine vm) {
        //load the value onto the run time stack
        vm.getRunStack().load(n);
        
        //check if the dump is on
        if("ON".equals(vm.dump)) {
            System.out.println("LOAD " + n + " " + id + "    <load " + id + ">");
        }
    }
}
