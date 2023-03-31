import java.rmi.*;

public class RE {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Usage: java RE <host> <command>");
            System.exit(1);
        }

        String host = args[0];
        String cmd = args[1];

        try {
            Daemon daemon = (Daemon) Naming.lookup("rmi://" + host + "/Daemon");
            daemon.localExec(cmd);
        } catch (Exception e) {
            System.err.println("RE exception:");
            e.printStackTrace();
        }
    }
}