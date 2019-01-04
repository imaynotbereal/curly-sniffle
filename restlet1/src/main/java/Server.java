

import org.restlet.Component;
import org.restlet.data.Protocol;

public class Server {
	Component component;
	
	public static void main(String[] args) {
		Server server = new Server();
		try {
			server.start(8081);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void start(int port) throws Exception {
		component = new Component();
		Myapplication app = new Myapplication();
		component.getServers().add(Protocol.HTTP, port);
		component.getDefaultHost().attach(app);
		component.start();
	}
	
	public void stop() throws Exception {
		component.stop();
	}
}
