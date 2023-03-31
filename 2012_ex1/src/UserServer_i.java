import java.io.*;
import java.net.*;

public class UserServer_i {
    final static String hosts[] = {"host1", "host2", "host3"};
    final static int ports[] = {8081, 8082, 8083};
    final static int nb = 3;
    static String document[] = {"hello", "hanoi", "vietnam"};

    public static void main(String[] args) throws IOException {
        int id = Integer.parseInt(args[0]);
        int port = ports[id];

        ServerSocket serverSocket = new ServerSocket(port);
        System.out.println("Server " + id + " started on port " + port);

        while (true) {
    
            Socket socket = serverSocket.accept();
            System.out.println("Accepted connection from " + socket.getInetAddress());
    
            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
    
            int index = in.readInt();
            System.out.println("Received request for index " + index);
    
            String response = document[index];
            out.writeObject(response);
            System.out.println("Sent response " + response);
    
            out.close();
            in.close();
            socket.close();
            
        }
        
    }
}
