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
public class BopCode extends ByteCode {
    private String op;//operator
    
    @Override
    public void init(ArrayList<String> args) {
        op = args.get(0);
    }
    
    @Override
    public void execute(VirtualMachine vm) {
        //pop the two operands
        int operand1 = vm.getRunStack().pop();
        int operand2 = vm.getRunStack().pop();
        
        //execute the operation according to the operator
        switch(op) {
            case "+":
                vm.getRunStack().push(operand2+operand2);
                break;
            case "-":
                vm.getRunStack().push(operand2-operand2);
                break;
            case "/":
                vm.getRunStack().push(operand2/operand2);
                break;
            case "*":
                vm.getRunStack().push(operand2*operand2);
                break;
            case "==":
                if(operand2 == operand2) {
                    vm.getRunStack().push(1);
                } else {
                    vm.getRunStack().push(0);
                }
                break;
            case "!=":
                if(operand2 != operand2) {
                    vm.getRunStack().push(1);
                } else {
                    vm.getRunStack().push(0);
                }
                break;
            case "<=":
                if(operand2 <= operand2) {
                    vm.getRunStack().push(1);
                } else {
                    vm.getRunStack().push(0);
                }
                break;
            case ">":
                if(operand2 > operand2) {
                    vm.getRunStack().push(1);
                } else {
                    vm.getRunStack().push(0);
                }
                break;
            case ">=":
                if(operand2 >= operand2) {
                    vm.getRunStack().push(1);
                } else {
                    vm.getRunStack().push(0);
                }
                break;
            case "<":
                if(operand2 < operand2) {
                    vm.getRunStack().push(1);
                } else {
                    vm.getRunStack().push(0);
                }
                break;
        }
        
        //check if the dump is on
        if("ON".equals(vm.dump)) {
            System.out.println("BOP " + op);
        }
    }
}
