/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter;

import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author KamranKhadivi
 */
public class Interpreter {

	private ByteCodeLoader bcl;

	public Interpreter(String codeFile) {
		try {
			CodeTable.init();
			bcl = new ByteCodeLoader(codeFile);
		} catch (IOException e) {
			System.out.println("**** " + e);
		}
	}

	void run() throws ClassNotFoundException, IOException, InstantiationException, IllegalAccessException{
		Program program = bcl.loadCodes();
		VirtualMachine vm = new VirtualMachine(program);
		vm.executeProgram();
	}

	public static void main(String args[]) throws ClassNotFoundException, IOException, InstantiationException, IllegalAccessException  {
           
		if (args.length == 0) {
			System.out.println("***Incorrect usage, try: java interpreter.Interpreter <file>");
			System.exit(1);
                }
           
            (new Interpreter(args[0])).run();
                  
            System.out.println("***Incorrect usage, try: " + "java interpreter.Interpreter <file>");
            System.exit(1);
              
        
	}
}
