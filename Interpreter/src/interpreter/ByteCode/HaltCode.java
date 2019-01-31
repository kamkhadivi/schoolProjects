package interpreter.ByteCode;

import interpreter.VirtualMachine;
import java.util.ArrayList;

public class HaltCode extends ByteCode {

    
    @Override
    public void init(ArrayList<String> args) {

    }

    
    @Override
    public void execute(VirtualMachine vm) {
        vm.setIsRunning(false);
        
        if("ON".equals(vm.dump)){
            System.out.print("HALT");
        }

    }
    
}

