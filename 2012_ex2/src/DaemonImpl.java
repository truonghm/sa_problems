import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;

public class DaemonImpl extends UnicastRemoteObject implements Daemon {

	protected DaemonImpl() throws RemoteException {
		super();
	}
	
	private void LocalExec(String cmd, Console c) {
		try {
			c.println("I should execute the command : "+cmd);
		} catch (RemoteException e) {
			e.printStackTrace();
		}
	}
	public void execute(String cmd, Console c) throws RemoteException {
		LocalExec(cmd, c);
	}
	
	public static void main(String[] args) {

		try {
			LocateRegistry.createRegistry(1099);
			Naming.bind("//localhost/daemon", new DaemonImpl());
			System.out.println("daemon ready");
		} catch (Exception e) {
			e.printStackTrace();
		} 
	
	}

}

// import java.rmi.*;
// import java.rmi.registry.LocateRegistry;
// import java.rmi.server.*;

// public class DaemonImpl extends UnicastRemoteObject implements Daemon {

//     public DaemonImpl() throws RemoteException {
//         super();
//     }

//     public void localExec(String cmd) throws RemoteException {
//         try {
//             System.out.println(cmd);
//             String[] cmdArgs = cmd.split("\\s+");
//             ProcessBuilder pb = new ProcessBuilder(cmdArgs).inheritIO();
//             pb.start();
//         } catch (Exception e) {
//             System.err.println("Error executing command: " + e.getMessage());
//             e.printStackTrace();
//         }
//     }
    
//     public static void main(String[] args) {
//         try {
//             LocateRegistry.createRegistry(1099);
//             DaemonImpl daemon = new DaemonImpl();
//             Naming.bind("rmi://localhost/Daemon", daemon);
//             System.out.println("Daemon ready.");
//         } catch (Exception e) {
//             System.err.println("Daemon exception: " + e.getMessage());
//             e.printStackTrace();
//         }
//     }
// }
