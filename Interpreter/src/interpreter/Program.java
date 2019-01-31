package interpreter;

import interpreter.ByteCode.*;
import java.util.ArrayList;
import java.util.HashMap;


public class Program {

    private ArrayList<ByteCode> program;
    private static HashMap<String,Integer> Label;
    
    
    public Program() {
        program = new ArrayList<ByteCode>();
        Label = new HashMap<String,Integer>();
    }

    public int getSize() {
        return this.program.size();
    }
    

    /**
     * This function should go through the program and resolve all addresses.
     * Currently all labels look like LABEL <<num>>>, these need to be converted into
     * correct addresses so the VirtualMachine knows what to set the Program Counter(PC)
     * HINT: make note what type of data-stucture bytecodes are stored in.
     *
     * @param program Program object that holds a list of ByteCodes
     */
    
    
    public void resolveAddrs(Program program) {
        Integer changeAddress;
        for (int i=0; i < program.getSize(); i++) {            
            if (program.getCode(i) instanceof BranchCode){
                BranchCode temp;
                temp = (BranchCode)program.getCode(i);
                changeAddress = new Integer(Label.get(temp.getLabel()));
                temp.setTargetAddress(changeAddress.intValue());
            }          
        }
    }

    //Function used in loader that adds the ByteCode instance to the Program class
    public void add(ByteCode byteCode) {
        if (byteCode instanceof LabelCode){
            LabelCode label = (LabelCode) byteCode;
            Label.put(label.getLabel(), program.size());
        }
        program.add(byteCode);
    }

    //Locates the ByteCode using pc as the index
    protected ByteCode getCode(int pc) {
        return this.program.get(pc);
    }

    


    
}