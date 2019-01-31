/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter;

import interpreter.ByteCode.ByteCode;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class ByteCodeLoader extends Object {

    private BufferedReader byteSource;

    public ByteCodeLoader(String file) throws IOException {
        this.byteSource = new BufferedReader(new FileReader(file));
    }
    /**
     * This function should read one line of source code at a time.
     * For each line it should:
     *      Tokenize string to break it into parts.
     *      Grab correct class name for the given bytecode from CodeTable
     *      create an instance of the bytecode class name returned from code table.
     *      Parse any additional arguments for the given bytecode and send them to
     *      the newly created bytecode instance via the init function.
     */
    
    public Program loadCodes() throws ClassNotFoundException, IOException, InstantiationException, IllegalAccessException {
       
            Program program = new Program();
            ArrayList<String> args= new ArrayList<String>();
            String code = byteSource.readLine();
            
            //loops through input file and creates an instance of the class and 
            //adds it to the arraylist in Program.java
            while(code!=null){
                StringTokenizer token=new StringTokenizer(code);
                args.clear();//We need to clear the argument on each iteration!
                String codeClass= CodeTable.getClassName(token.nextToken());
                
                while(token.hasMoreTokens()){
                    args.add(token.nextToken());
                }
             
                ByteCode byteCode;
                byteCode = (ByteCode)(Class.forName("interpreter.ByteCode."+codeClass).newInstance());
                  
                byteCode.init(args);
                program.add(byteCode);
                code=byteSource.readLine();
            }
            
            program.resolveAddrs(program);
            return program; 
    }

}