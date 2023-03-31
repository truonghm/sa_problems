

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;

public class LB {

	static String hosts[] = {"localhost", "localhost"};
	static int ports[] = {8081,8082};
	static int nbHosts = 2;
	static Random rand = new Random();
	
	public static void main(String[] args) {

		try {
			ServerSocket ss = new ServerSocket(6080);
			while (true) {
				Socket s = ss.accept();
				Slave slave = new Slave(s);
				slave.start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
	}

}
