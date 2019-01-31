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
public class PopCode extends ByteCode {
        protected int n;//top n level

        @Override
    public void init(ArrayList<String> args) {
        n = Integer.parseInt(args.get(0));
    }
    
        @Override
    public void execute(VirtualMachine vm) {
        //pop top n level of the run time stack
        for(int i = 0; i < n; i++) {
            vm.getRunStack().pop();
        }
        
        //check if the dump is on
        if("ON".equals(vm.dump)) {
            System.out.println("POP" + " " + n);
        }
    }
}
