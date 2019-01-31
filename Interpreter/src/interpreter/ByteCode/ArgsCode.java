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
public class ArgsCode extends ByteCode {
    private int numArgs;
    
    @Override
    public void init(ArrayList<String> args){
        numArgs = Integer.parseInt(args.get(0));
    }
    
    @Override
    public void execute(VirtualMachine vm){
        vm.getRunStack().newFramePositioned(numArgs);
        if("ON".equals(vm.dump)) 
            System.out.println("ARGS " + numArgs);

    }
}
