import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.*;

public class DaemonImpl extends UnicastRemoteObject implements Daemon {

    public DaemonImpl() throws RemoteException {
        super();
    }

    public void localExec(String cmd) throws RemoteException {
        try {
            System.out.println(cmd);
            String[] cmdArgs = cmd.split("\\s+");
            ProcessBuilder pb = new ProcessBuilder(cmdArgs).inheritIO();
            pb.start();
        } catch (Exception e) {
            System.err.println("Error executing command: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    public static void main(String[] args) {
        try {
            LocateRegistry.createRegistry(1099);
            DaemonImpl daemon = new DaemonImpl();
            Naming.bind("rmi://localhost/Daemon", daemon);
            System.out.println("Daemon ready.");
        } catch (Exception e) {
            System.err.println("Daemon exception: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
