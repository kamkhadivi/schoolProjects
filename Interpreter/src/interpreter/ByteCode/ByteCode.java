package interpreter.ByteCode;
import java.util.*;
import interpreter.VirtualMachine;


public abstract class ByteCode {


  public abstract void init(ArrayList<String> args);

  public abstract void execute(VirtualMachine vm);

} 

