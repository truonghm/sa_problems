import java.io.*;
import java.net.*;

public class UserClient {
    final static String hosts[] = {"localhost", "localhost", "localhost"};
    final static int ports[] = {8081, 8082, 8083};
    final static int nb = 3;
    static String document[] = new String[nb];

    public static void main(String[] args) throws IOException, ClassNotFoundException {

        for (int i = 0; i < nb; i++) {
            Socket socket = new Socket(hosts[i], ports[i]);
            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

            out.writeInt(i);
            out.flush();
            
            String response = (String) in.readObject();
            document[i] = response;
            System.out.println(response);

            in.close();
            out.close();
            socket.close();
        }
    }
}
