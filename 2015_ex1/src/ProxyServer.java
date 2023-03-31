import java.io.*;
import java.net.*;

public class ProxyServer {
    public static void main(String[] args) throws IOException {
        // Define the constants for the proxy server
        final int PORT = 8080;
        String HOST = args[0];
        int REMOTE_PORT = Integer.parseInt(args[1]);

        // Create a server socket to listen for incoming connections
        ServerSocket serverSocket = new ServerSocket(PORT);

        // Loop indefinitely to accept new connections
        while (true) {
            // Accept a new client connection
            Socket clientSocket = serverSocket.accept();

            // Create a new socket to connect to the remote server
            Socket remoteSocket = new Socket(HOST, REMOTE_PORT);

            // Create a new thread to handle the client connection
            Thread clientThread = new Thread(new ProxyThread(clientSocket, remoteSocket));
            clientThread.start();

            // Create a new thread to handle the remote server connection
            Thread remoteThread = new Thread(new ProxyThread(remoteSocket, clientSocket));
            remoteThread.start();
        }
    }
}

class ProxyThread implements Runnable {
    private Socket inputSocket;
    private Socket outputSocket;

    public ProxyThread(Socket inputSocket, Socket outputSocket) {
        this.inputSocket = inputSocket;
        this.outputSocket = outputSocket;
    }

    public void run() {
        try {
            // Create input and output streams for the sockets
            InputStream input = inputSocket.getInputStream();
            OutputStream output = outputSocket.getOutputStream();

            // Loop indefinitely to read data from the input stream and write it to the output stream
            byte[] buffer = new byte[4096];
            int bytesRead;
            while ((bytesRead = input.read(buffer)) != -1) {
                output.write(buffer, 0, bytesRead);
                output.flush();
            }

            // Close the sockets and streams
            inputSocket.close();
            outputSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
