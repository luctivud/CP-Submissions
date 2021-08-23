package com; import java.net.*; import java.io.*;
public class SimpleClient {
public static void main(String args[]) { try {
Socket s1 = new Socket("localhost", 4242); InputStream is = s1.getInputStream(); DataInputStream dis = new DataInputStream(is); System.out.println(dis.readUTF());
dis.close();
s1.close();
} catch (ConnectException connExc) { System.err.println("Could not connect.");
} catch (IOException e) {
} }
}