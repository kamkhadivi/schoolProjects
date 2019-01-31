/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;

import java.util.ArrayList;
import interpreter.VirtualMachine;
import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 *
 * @author KamranKhadivi
 */
public class ReadCode extends ByteCode {
        @Override
        public void init(ArrayList<String> args) {
        
    }
    
        @Override
     public void execute(VirtualMachine vm) {
         //read integer from user
         System.out.print("Please enter an integer: ");
         
         try {
             BufferedReader in = new BufferedReader( new InputStreamReader(System.in ) );
             String line = in.readLine();
             vm.getRunStack().push(Integer.parseInt(line));
         } catch( java.io.IOException ex ) {   
         }
         
         //check if the dump is on
         if("ON".equals(vm.dump)) {
             System.out.println("READ");
         }
     }
}
