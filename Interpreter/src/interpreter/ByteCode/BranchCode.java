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
 * @author zhangzhewei
 */
public abstract class BranchCode extends ByteCode {
    @Override
    public abstract void init(ArrayList<String> args);
    @Override
    public abstract void execute(VirtualMachine vm);
    public abstract int getTargetAddress();
    public abstract void setTargetAddress(int n);
    public abstract String getLabel();
}
