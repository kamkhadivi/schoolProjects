/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;
import interpreter.VirtualMachine;
import java.util.*;

/**
 *
 * @author KamranKhadivi
 */
public class LabelCode extends ByteCode {

    private String label;
    
    @Override
    public void init(ArrayList<String> args) {
        label = args.get(0);
    }

    @Override
    public void execute(VirtualMachine vm) {
        if("ON".equals(vm.dump)){
            System.out.println("Label "+label);
        }
    }
    
    public String getLabel(){
        return label;
    }
    
    
}
