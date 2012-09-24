//: C25:ParseTrash.java
// Open a file and parse its contents into
// Trash objects, placing each into a Vector
package c16.trash;

import java.util.*;
import java.io.*;

public class ParseTrash {
    public static void fillBin(String filename, Fillable bin) {
        try {
            BufferedReader data = new BufferedReader(new FileReader(filename));
            String buf;
            while ((buf = data.readLine()) != null) {
                String type = buf.substring(0, buf.indexOf(':')).trim();
                double weight = Double.valueOf(buf.substring(buf.indexOf(':') 
                + 1).trim()).doubleValue();
                bin.addTrash(Trash.factory(new Trash.Info(type, weight)));
            }
            data.close();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Special case to handle Vector:
    public static void fillBin(String filename, Vector bin) {
        fillBin(filename, new FillableVector(bin));
    }
} ///:~