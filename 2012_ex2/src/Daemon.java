import java.rmi.*;

public interface Daemon extends Remote {
    public void localExec(String cmd) throws RemoteException;
}