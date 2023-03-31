import java.rmi.Naming;

public class RE {

	public static void main(String[] args) {

		try {
			String host = args[0];
			String cmd = args[1];
			Daemon s = (Daemon)Naming.lookup("//localhost/daemon");
			s.execute(cmd, new ConsoleImpl());
			System.exit(0);
		} catch (Exception e) {
			e.printStackTrace();
		} 
	}
}

// import java.rmi.*;

// public class RE {
//     public static void main(String[] args) {
//         if (args.length != 2) {
//             System.err.println("Usage: java RE <host> <command>");
//             System.exit(1);
//         }

//         String host = args[0];
//         String cmd = args[1];

//         try {
//             Daemon daemon = (Daemon) Naming.lookup("rmi://" + host + "/Daemon");
//             daemon.localExec(cmd);
//         } catch (Exception e) {
//             System.err.println("RE exception:");
//             e.printStackTrace();
//         }
//     }
// }