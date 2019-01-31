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
public class LitCode extends ByteCode{
        protected int n;//value
    protected String id;//id
    
        @Override
    public void init(ArrayList<String> args) {
        n = Integer.parseInt(args.get(0));
        if(args.size()>1){
            id = args.get(1);
        }else{
            id = "";
        }
    }
    
        @Override
    public void execute(VirtualMachine vm) {
        //load the value onto the run time stack
        if("".equals(id)) {
            vm.getRunStack().push(n);
        } else {
            vm.getRunStack().push(0);
        }
        
        //check if the dump is on
        if("ON".equals(vm.dump)) {
            String output = "LIT " + n + " " + id;
            if(!id.equals("")){
                output = output + "    int " + id;
            }
            System.out.println(output);
        }
        
    }
}
