import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class Slave extends Thread {

	Socket client;
	
	public Slave(Socket s) {
		client = s;
	}
	
	public void run() {
		try {
			int n = LB.rand.nextInt(LB.nbHosts);
			Socket server = new Socket(LB.hosts[n], LB.ports[n]);
			
			InputStream cis = client.getInputStream();
			OutputStream cos = client.getOutputStream();
			InputStream sis = server.getInputStream();
			OutputStream sos = server.getOutputStream();
			
			byte buffer[] = new byte[1024];
			
			int r = cis.read(buffer);
			if (r>0) sos.write(buffer, 0, r);
			r = sis.read(buffer);
			if (r>0)cos.write(buffer,0,r);
			client.close();
			server.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
