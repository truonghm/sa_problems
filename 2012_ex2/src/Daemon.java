import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Daemon extends Remote {
	
	public void execute(String cmd, Console c) throws RemoteException;

}

// import java.rmi.*;

// public interface Daemon extends Remote {
//     public void localExec(String cmd) throws RemoteException;
// }
